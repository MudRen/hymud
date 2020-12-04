// combatd.c
// modify by zzz year 2000
#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/quest/givegift.c"

inherit F_DBASE;

mapping limb_damage = ([
    "ͷ��"  :   100,
    "����"  :   90,
    "�ؿ�"  :   90,
    "����"  :   80,
    "���"  :   50,
    "�Ҽ�"  :   55,
    "���"  :   40,
    "�ұ�"  :   45,
    "����"  :   20,
    "����"  :   30,
    "����"  :   60,
    "С��"  :   70,
    "����"  :   40,
    "����"  :   50,
    "���"  :   35,
    "�ҽ�"  :   40,
    "����"  :   80,
    "ǰ��"  :   40,
    "���"  :   50,
    "�Ȳ�"  :   40,
    "β��"  :   10,
    "���"  :   50,
    "צ��"  :   40,
]);

mixed danger_limbs = ({
        "ͷ��", "����", "�ؿ�", "����","С��",
});

mapping *combat_action = ({
        ([      "action":               "$N��ȭ����$n��$l",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��$n��$lһץ",
                "damage_type":  "ץ��",
        ]),
        ([      "action":               "$N��$n��$l�ݺݵ�����һ��",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N����ȭͷ��$n��$l��ȥ",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��׼$n��$l�����ӳ�һȭ",
                "damage_type":  "����",
        ]),
});
object *player;
int userno;


string *head_damage_me_msg = ({
        HIR "�����ͷ��һ�㷢�Ρ�\n" NOR,
        HIB "�����һ����ѣ���������һ�¡�\n" NOR,
        BLU "��ֻ����ð���ǣ�����Ʈ��\n" NOR,
});

string *body_damage_me_msg = ({
        HIR "��ֻ��$l������ʹ�����������ܵ�һ���񵴡�\n" NOR,
        HIB "��ֻ��$l���ۣ���������һ���Ҵܡ�\n" NOR,
        BLU "��ֻ����$l����ʹ����������������һ����й��\n" NOR,
});

string *guard_msg = ({
	CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
	CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
	CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
	CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
	HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
	HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
	HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
	CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
	CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
	CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
	CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
	CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

string *catch_hunt_beast_msg = ({
	HIW "$Nŭ��һ�������˹�������$n��\n" NOR,
	HIW "$N����$n�����ɱ��$n��\n" NOR,
	HIW "$N���������ͺ�ͻȻ���𹥻�$n��\n" NOR,
});

string *catch_hunt_bird_msg = ({
	HIW "$N����$nһ��ŭ�����ɳ��˹�����\n" NOR,
	HIW "$Nŭ��������ͻȻ���𹥻�$n��\n" NOR,
	HIW "$Nһ����������Ȼ��$n���𹥻���\n" NOR,
});

string *winner_animal_msg = ({
	CYN "\n$N����һ�ԣ��������$n���ӣ�\n\n" NOR,
	CYN "\n$N���ؿ���������Ȼ�������ɵض���$n��\n\n" NOR,
	CYN "\n$N���˼���������ʱ�����ٳ������\n\n" NOR
});

void create()
{
	seteuid(getuid());
	set("name", "ս������");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "��� " + damage + " ��" + type + "��\n";
	if( damage == 0 ) return "���û������κ��˺���\n";

	switch( type ) {
		case "����":
		case "����":
			if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
			if( damage < 50 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
			if( damage < 100 ) return "������͡���һ������$n���ϻ���һ���˿ڣ�\n";
			if( damage < 200 ) return "������͡���һ������$n���ϻ���һ��Ѫ���ܵ��˿ڣ�\n";
			if( damage < 320 ) return "������͡���һ������$n���ϻ���һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
			return "���ֻ����$nһ���Һ���$w����$p$l����һ����ɼ��ǵĿ����˿ڣ���\n";
		case "����":
			if( damage < 10 ) return "���ֻ������ش���$n��Ƥ�⡣\n";
			if( damage < 50 ) return "�����$n$l�̳�һ�����ڡ�\n";
			if( damage < 100 ) return "������ۡ���һ��������$n$l����\n";
			if( damage < 200 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
			if( damage < 320 ) return "��������͡���һ����$w�̽���$n��$l��������Ѫ�漴���˳�����\n";
			return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
		case "����":
			if( damage < 20 ) return "���ֻ�����������$n�����Ĳ�Ӭ��΢���˵㡣\n";
			if( damage < 40 ) return "�����$n��$l���һ�����ࡣ\n";
			if( damage < 80 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
			if( damage < 100 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
			if( damage < 170 ) return "������项��һ����$n����������\n";
			if( damage < 240 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
			if( damage < 320 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
			if( damage < 450 ) return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
			return "ֻ����$nһ���ҽУ���������������ߵķ���һ�����˳�ȥ����\n";
		case "����":
			if( damage < 20 ) return "���ֻ�ǰ�$n������˰벽����������\n";
			if( damage < 60 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
			if( damage < 100 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
			if( damage < 170 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
			if( damage < 240 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
			if( damage < 320 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
			if( damage < 450 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
			return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		case "����":                
			if( damage < 100 ) return "���$n�ܵ�$N�ľ���һ���ƺ�һ����\n";
			if( damage < 150 ) return "���$n��$N�Ծ���һ�𣬡��١���һ������������\n";
			if( damage < 230 ) return "���$n��$N�Ծ���һ���ؿ������ܵ�һ���ش�����������������\n";
			if( damage < 340 ) return "���$N�ľ���һ�����$n�����˺ü�������һ��ˤ����\n";
			if( damage < 450 ) return "���$n��$N�ľ������ȫ����Ѫ������������Ѫ���������\n";
			return "���$n��$N�ľ��������ǰһ�ڣ��������ѣ�����ƾ�շ��˳�ȥ����\n";
		case "����":
			if( damage < 15 ) return "���ֻ������ػ�����$n��Ƥ����\n";
			if( damage < 50 ) return "�����$n��$l���һ��ϸ����Ѫӡ��\n";
			if( damage < 150 ) return "�����ž����һ��$w��$n��$lƤ���������γ�һ���������˿ڣ�\n";
			if( damage < 250 ) return "ֻ��$n��������һ���³�һ����Ѫ��ԭ��$p$l�ڵĹ�ͷ�Ѿ���$w�ľ������ѣ�\n";
			if( damage < 350 ) return "������š��ǡ���һ����$w�ѽ�$n$l���Ĺ�ͷӲ�����س�ϣ��ϹǴ�����ð�˳�����\n";
			return "���$nһ���Һ���$w�Ѵ�$p$l��˺����һ��ƬѪ���ܵ�Ƥ�⣬��Ѫ�������أ���\n";
		case "����":
		case "����":
			if( damage < 20 ) return "���ֻ���������ײ����$nһ�£�û�����ʲô�˺���\n";
			if( damage < 80 ) return "���$wֻ��$n��$l�ҳ�һ�����졣\n";
			if( damage < 160 ) return "�����ž����һ����$w����$n��$l����ʱ����һ���ϸߣ�\n";
			if( damage < 320 ) return "���$w���صû���$n��$l�����$p�������������ۡ����³�һ�����Ѫ��\n";
			if( damage < 450 ) return "���ֻ�������𡹵�һ�����죬$w����$n���ϣ���$p��һ�����ݰ���ɳ�ȥ��\n";
			return "���$wһ�´���$n�����ϣ������������У�$p��ɢ�˼��Ƶ�̱����ȥ����\n";
		case "ץ��":
			if( damage < 20 ) return "���ֻ����$n$l������ι���û��ʲô�˺���\n";
			if( damage < 40 ) return "���$n������ü��$p��$l�Ѿ���������һ��ǳǳ��Ѫ�ۡ�\n";
			if( damage < 80 ) return "���������$n$l��һ��Ƥ�⣬�۵�$p�����ۡ��ֽ���������\n";
			if( damage < 120 ) return "�����ৡ���һ����$n��$l�϶�ʱ��ץ�����Ѫ�ۣ���Ѫ���˳�����\n";
			if( damage < 220 ) return "���$n�۵ô��һ����$p$l�ϱ�ץ���˼��������Ѫ������Ѫֱ����\n";
			if( damage < 330 ) return "���ֻ����$nһ���Һ���$N����צ����$p��$l���̳������Ѫ��ģ���Ŀ�����\n";
			if( damage < 440 ) return "�����������һ���ҽУ�$n����$l����$Nץ����һ��ƬƤ�⣬��Ѫ������أ���\n";
			return "���$nһ����ҵ�˻�У�$l������Ƥ���⳶��һ��飬¶���˰�ɭɭ�Ĺ�ͷ����\n";
        case "ˤ��":
			if( damage < 20 ) return "���$n���²��ȣ��ڵ��ϲ����˵��Ƥ��\n";
			if( damage < 80 ) return "�����ž����һ����$n�ڵ���ˤ�˸�ƨ�⡣\n";
			if( damage < 160 ) return "���$nһ��С�ģ���$N����ˤ���ڵأ�\n";
			if( damage < 300 ) return "���$n��һ��ˤ���ڵأ����۵ء�һ�������һ�����Ѫ��\n";
            if( damage < 420 ) return "�����$N��һ��ˤ�ڵ��ϣ�$l���Ĺ�ͷ�����꡹һ�����ˣ�\n";
			return "���ֻ����$nһ���Һ�����$Nˤ��Ѫ���ɣ��Ҳ��̶ã���\n";
        case "����":
                if( damage < 100 ) return "���$p�͵�һ����û��ô���š�\n";
                else if( damage < 200 ) return "�������ߴ��һ����$p��ˤ�˸�ƨ�ա�\n";
                else if( damage < 400 ) return "���$p��$l��ʵ�ر�ˤ��һ�£�\n";
                else if( damage < 800 ) return "���$p��$l���ڵ��ϣ���ˤ�����ϣ�\n";
                else if( damage < 1600 ) return "�����$p��$l��ʱ����һ��飬��Ѫ��͸�����ϣ�\n";
                else return "���$p��$l��ˤ��Ƥ����������ͷ���������������\n";
                break;
        case "ҧ��":
                if( damage < 100 ) return "���ֻ������ز���һ��$p��Ƥ�⡣\n";
                else if( damage < 200 ) return "�����$p$lҧ��һ����ӡ��\n";
                else if( damage < 400 ) return "���$p��ҧ��һƬ������\n";
                else if( damage < 800 ) return "���$p��Ƥ���ⱻҧ��һ��飡\n";
                else if( damage < 1600 ) return "�����$p������ҧ����Ѫ��ģ����һ���$l�⣡\n";
                else return "���ֻ����$nһ���Һ���$p��$l�ϵ��ⱻһ��ҧ����¶����ͷ����\n";
                break;
        case "����":
        case "����":
        case "����":
                if( damage < 100 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 200 ) return "�����$p��$l���һ�����ࡣ\n";
                else if( damage < 400 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                else if( damage < 800 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                else if( damage < 1200 ) return "������项��һ����$n����������\n";
                else if( damage < 1600 ) return "�����һ�¡��项��һ������$n�����˺ü�������һ��ˤ����\n";
                else if( damage < 2400 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ����\n";
                else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                break;
        case "����":
                if( damage < 100 ) return "���ֻ�ǰ�$n������˰벽����������\n";
                else if( damage < 200 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
                else if( damage < 400 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
                else if( damage < 800 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
                else if( damage < 1200 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
                else if( damage < 1600 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else if( damage < 2400 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ�����������\n";
                else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
                break;
	case "����":
		if( damage < 100 ) return "���$p�ɻ�ؿ���$Pһ�ۣ��ƺ�û�ио���ʲôʹ����\n";
		else if( damage < 200 ) return "���$p����һ�Σ����㲻����������Ҫˤ����\n";
		else if( damage < 400 ) return "���$p���㲻����������ˤ����������۵�һ�������һ����Ѫ��\n";
		else if( damage < 800 ) return "���$p�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����࣡\n";
		else if( damage < 1600 ) return "���$p���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磡\n";
		else if( damage < 2400 ) return "���ֻ��һ�����죬$p������Ѫ���磬ȫ��������ѣ���\n";
		else return "���ֻ��һ�����죬$pȫ��������ѣ����Ʊ�����ɽ�������һ�������Ӵ�������أ���\n";
		break;
        case "����":
        case "ץ��":
                if( damage < 100 ) return "���$pֻ������ز�����һ����Ƥ��\n";
                else if( damage < 200 ) return "���$p��$l�ϱ�����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 400 ) return "�����ৡ�����$p��$l�ϲ��һ��ƬƤ�⣡\n";
                else if( damage < 800 ) return "�����ৡ���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 1600 ) return "�����ৡ���һ��$p��$l�ϱ�˺��Ѫ���ܵ�һƬ�⣡\n";
                else return "���ֻ����$nһ���Һ���$p$l��Ƥ�⾡�ѣ�¶����ɭɭ�Ĺ�ͷ��\n";
                break;
        case "����":
        case "����":
        case "����":
                if( damage < 100 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
                else if( damage < 200 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 400 ) return "������͡���һ������һ���˿ڣ�\n";
                else if( damage < 800 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 1600 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
        case "����":
                if( damage < 100 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
                else if( damage < 200 ) return "�����$p$l�̳�һ�����ڡ�\n";
                else if( damage < 400 ) return "������ۡ���һ��������$n$l����\n";
                else if( damage < 800 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                else if( damage < 1600 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
                else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        case "����":
		if( damage < 20 ) return "���ֻ���������ײ����$nһ�£�û�����ʲô�˺���\n";
		if( damage < 60 ) return "���$wֻ��$n��$l�ҳ�һ�����졣\n";
		if( damage < 120 ) return "�����ž����һ����$w����$n��$l����ʱ����һ���ϸߣ�\n";
		if( damage < 240 ) return "���$w���صû���$n��$l�����$p�������������ۡ����³�һ�����Ѫ��\n";
		if( damage < 380 ) return "���ֻ�������𡹵�һ�����죬$w����$n���ϣ���$p��һ�����ݰ���ɳ�ȥ��\n";
		return "ֻ��$w���ص�ײ����$n�����ϣ������������У�$p��ɢ�˼��Ƶ�̱����ȥ����\n";
                break;
        case "����":
                if( damage < 100 ) return "���ֻ����$p$l�ϲ���һ����ӡ��\n";
                else if( damage < 200 ) return "�����$p��$l�ϳ��һ��Ѫ�ۡ�\n";
                else if( damage < 400 ) return "�����ž����һ��$p������һ���˿ڣ�\n";
                else if( damage < 800 ) return "���$p��$l�ϱ�����һ��Ѫ���ܵĴ��ڣ�\n";
                else if( damage < 1600 ) return "�����ž����һ��$p��$N��$w����һ����ͷ���ŵ�Ѫӡ��\n";
                else return "���ֻ���������꡹һ����$p��$l�Ĺ�ͷ����ϣ�$w��Ⱦ��Ѫ�죡��\n";
                break;
	case "����":
	case "����":
		if( damage < 100 ) return "���ֻ�ǰ�$p��$l����һ�¡�\n";
		else if( damage < 200 ) return "���$p��$l��$w���˵����˸�С�塣\n";
		else if( damage < 400 ) return "���$p��$l��$w�յú�����ʹ��ʹ�ò�סð��ҧ����\n";
		else if( damage < 800 ) return "������͡�һ�����죬$p���$l��һƬ��ʹ���ѱ�$w�ճ��˰���ɫ�����罹̿��\n";
		else if( damage < 1600 ) return "��������͡�һ�������ȥ��$n��ɫʹ���ѵ���$l��$w�յ�һƬ���ڣ�����ֱð��\n";
		else return "���ֻ����$n�����Һ����ڵ��ϲ�ס�����$l�ѱ�$w�յ�Ƥ�⾡�ã��������磡��\n";
		break;
	case "����":
		if( damage < 100 ) return "���$p���Ǿ���$l��Щ���쬵أ���ͦ����ġ�\n";
		else if( damage < 200 ) return "���$p��$l��������Щ��ľ��\n";
		else if( damage < 400 ) return "���$p������ش��˸�������\n";
		else if( damage < 800 ) return "���$p��ɫһ�䣬������Щ��Ӳ������Ҳ���ɪɪ������\n";
		else if( damage < 1600 ) return "���$p���Ӵ������ɫ�԰ף��촽���÷��ϣ����ظ��ֱ�죡\n";
		else return "���������$n����һ�ƣ����ϲҰ׵�û���Ѫɫ���������ݣ�����ѪҺ�ƺ�������˱�����\n";
		default:
			if( !type ) type = "�˺�";
			if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
			else if( damage < 20 ) str = "��������΢��";
			else if( damage < 30 ) str = "������һ��";
			else if( damage < 50 ) str = "������һ������";
			else if( damage < 80 ) str = "��������Ϊ���ص�";
			else if( damage < 120 ) str = "�������൱���ص�";
			else if( damage < 170 ) str = "������ʮ�����ص�";
			else if( damage < 230 ) str = "�����ɼ������ص�";
			else str =  "�����ɷǳ����µ�����";
			return str + type + "��\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
	if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
	if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
	if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
	if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
	if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
					 return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
	if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
	if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
	if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
	if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
				     return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}




varargs void report_status(object ob, int effective)
{
// �����ֳ�ת�� start
//	player=users();
// �����ֳ�ת�� end
	if( effective ) 
	{//	if(!ob->query_temp("tjj_jie"))
		message_vision( "( $N" + eff_status_msg(
		(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
// �����ֳ�ת�� start
//		if ((string)environment(ob)->query("short") == "��̨")
//		for (userno=0; userno<sizeof(player); userno++)
//		    if ((player[userno])->query_temp("view_leitai"))
//			tell_object(player[userno], "( " + ob->name() + eff_status_msg(
//			(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
//			+ " )\n");
// �����ֳ�ת�� end
	}
	else
	{//	if(!ob->query_temp("tjj_jie"))
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
// �����ֳ�ת�� start
//		if ((string)environment(ob)->query("short") == "��̨")
//		for (userno=0; userno<sizeof(player); userno++)
//		    if ((player[userno])->query_temp("view_leitai"))
//			tell_object(player[userno], "( " + ob->name() + status_msg(
//			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
//			+ " )\n");
// �����ֳ�ת�� end
	}
}
void fight_reward(object winner, object loser)
{
        object owner;

        if(owner=winner->query("possessed"))  winner = owner;
        winner->win_enemy(loser);
}
void fight_penalty(object winner, object loser)
{
        object owner;

        if(owner=loser->query("possessed"))  loser = owner;
        loser->lose_enemy(winner);
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power,attack,def,exp;
	int stra,dodgea,dexa;
	if( !living(ob) ) return 0;
	attack=ob->query_temp("apply/attack");
if (ob->query_temp("apply/strength") > 1800)
ob->set_temp("apply/strength",1800);
if (ob->query_temp("apply/intelligence") > 1800)
ob->set_temp("apply/intelligence",1800);
if (ob->query_temp("apply/constitution") > 1800)
ob->set_temp("apply/constitution",1800);
if (ob->query_temp("apply/dexerity") > 1800)
ob->set_temp("apply/dexerity",1800);
if (ob->query_temp("apply/attack") > 1800)
ob->set_temp("apply/attack",1800);
if (ob->query_temp("apply/defense") > 1800)
ob->set_temp("apply/defense",1800);
if (ob->query_temp("apply/damage") >28000)
ob->set_temp("apply/damage",28000);
if (ob->query_temp("apply/armor") > 28500)
ob->set_temp("apply/armor",28500);
if (ob->query_temp("apply/dodge") > 1800)
ob->set_temp("apply/dodge",1800);
if (ob->query_temp("fight/dodge") > 1800)
ob->set_temp("fight/dodge",1800);
	if (attack>200) attack = 200;
                        def = ob->query_temp("apply/defense");
			if (def>200) def = 200;
	level = ob->query_skill(skill)/3;
dodgea=ob->query_temp("fight/dodge");
if (dodgea> 200) dodgea=200;
exp=(int)ob->query("combat_exp");
if ((int)ob->query("combat_exp")> 100000000) exp=100000000;

	if( !level ) return exp / 2;
    if (level > 500) level = 500;

dexa=ob->query_dex();
if (dexa > 200) dexa=200;
stra=ob->query_str() + ob->query_temp("str")/2;
if (stra > 200) stra=200;

	switch(usage) 
	{
		case SKILL_USAGE_ATTACK:
			level += attack;
			break;
		case SKILL_USAGE_DEFENSE:
			//level = 1;
			level += def;
			if (ob->is_fighting() && skill="dodge" )
			level = level + dodgea;
			else 
			
			break;
	}
/*	if( !level ) return exp / 2;
    if (level > 500) level = 500;
dexa=ob->query_dex();
if (dexa > 200) dexa=200;
stra=ob->query_str() + ob->query_temp("str")/2;
if (stra > 200) stra=200;
*/
//if (level > 100) level=100;


if (dexa > 200) dexa=200;
if (stra > 200) stra=200;
//if ((power + exp) <100) power=100;

if (userp(ob) && (int)ob->query("combat_exp")> 8000000)
		power = (level / 8)*level*level;
else
		power = (level / 5)*level*level;

	if (usage == SKILL_USAGE_ATTACK)
		return (power + exp) / 30 * dexa;
	return (power + exp)
		/30 * (skill == "dodge"?dexa:stra);
	if (usage == SKILL_USAGE_ATTACK)
		return (power + exp) / 30 * stra;
	else
		return (power + exp) / 30 * stra;

  }

// do_attack()
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
varargs int do_attack(object me, object victim, object weapon, int attack_type, string attack_msg, string damtype)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result,mweaponn,vweaponn;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp,n,cstra,ccona,dexa;
	int damage, damage_bonus, defense_factor,damages,wounds,attack;
	int wounded = 0;
	int flag = 0;
	//int nwdamage;
	object vweapon,nweapon;

	if (!living(me)) return 0;
	if (!me) return 0;
        if (!victim) return 0;

if (victim->query_temp("weapon"))
{
        vweapon = victim->query_temp("weapon");
}
// �����ֳ�ת�� start
//	player=users();
// �����ֳ�ת�� end
	if (me->query_skill_mapped("parry") == "douzhuan-xingyi"
	&& ((!weapon && !vweapon) || ((weapon && vweapon)
	&& weapon->query("skill_type") == vweapon->query("skill_type"))))
		flag = 1;

	if (!living(me)) return 0;
	if (!me) return 0;
        if (!victim) return 0;
if (!victim->query_condition("killer") && environment(me)->query("no_fight")) return 0;
if (!victim->query_condition("killer") && environment(victim)->query("no_fight")) return 0;
	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
// (0) Choose skills.
	if (flag) {
if( flag && userp(me) && victim ) 
	victim->set_temp("last_damage_from", me);

		foo = me;
		me = victim;

	}
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);

	if ( sizeof(prepare) == 0) attack_skill = "unarmed";
	if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
	if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
	if ( weapon ) attack_skill = weapon->query("skill_type");
	if (flag && !me->query_skill_mapped(attack_skill)) {
		me = foo;
		flag = 0;
		prepare = me->query_skill_prepare();
		if (!prepare) prepare = ([]);
		if ( sizeof(prepare) == 0) attack_skill = "unarmed";
		if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
		if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
		if ( weapon ) attack_skill = weapon->query("skill_type");
	}
	// (1) Find out what action the offenser will take.
		me->prepare_skill("sword");	
		me->prepare_skill("blade");	
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();
		action = me->query("actions");
		if( !mapp(action) ) {
me->map_skill(attack_skill);
		me->reset_action();
			CHANNEL_D->do_channel( this_object(), "sys",
				sprintf("%s(%s)%s: �书Ϊ�� ϵͳ�Զ����� = %O",
					me->name(1), me->query("id"), attack_skill,me->query("actions", 1)));
        //return combat_action[random(sizeof(combat_action))];

//        return combat_action[random(sizeof(combat_action))];
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "��\n";
	else
		result = "\n" + "������"+action["action"] + "!\n"; 
       if(stringp(attack_msg)) result = "\n" + attack_msg + "\n";
	// (2) Prepare AP, DP for checking if hit.
//        if (martial_skill = me->query_skill_mapped(attack_skill))
//                limb = SKILL_D(martial_skill)->query_attack_limb(me, victim);

        if (! limb)
        {
                limbs = victim->query("limbs");
                if (! arrayp(limbs))
                {
                        limbs = ({ "����" });
                        victim->set("limbs", limbs);
                }
                limb = limbs[random(sizeof(limbs))];

        }



if (weapon)
{
mweaponn=weapon->query("skill_type");
}
if (vweapon)
{
vweaponn=vweapon->query("skill_type");
}
if (mweaponn=="" || !mweaponn) 
{
mweaponn="none";
}
if (vweaponn=="" || !vweaponn)
{
 vweaponn="none";
}


	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	
	        if (member_array(limb, danger_limbs) != -1) /* ��Σ�ղ�λ��������  */
                ap -= ap / 10;                      /* ���еĿ����Լ�С10% */

	if( ap < 1) ap = 1;
	if (userp(me) && intp(action["dodge"]))
	me->set_temp("fight/dodge", action["dodge"]);

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	if( victim->is_busy() ) dp /= 3;
	if(userp(me) && random(me->query("int",1)) > (victim->query("int,1")/2)) dp=dp/2;
	if(userp(victim) && random(victim->query("int",1)) > (me->query("int,1")*2)) dp=dp*2;
	// (3) Fight!
//�������
if (mweaponn=="sword" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="throwing") ) dp=dp/2;
if (mweaponn=="blade" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="sword") ) dp=dp/2;
if (mweaponn=="dagger" && (vweaponn=="none" || vweaponn=="blade" || vweaponn=="sword"  || vweaponn=="throwing" || vweaponn=="whip") ) dp=dp/2;
if (mweaponn=="axe" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="blade" || vweaponn=="sword") ) dp=dp/2;
if (mweaponn=="hammer" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="sword" || vweaponn=="none") ) dp=dp/2;
if (mweaponn=="club" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="hammer") ) dp=dp/2;
if (mweaponn=="staff" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="axe") ) dp=dp/2;
if (mweaponn=="none" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="axe") ) dp=dp/2;
if (mweaponn=="throwing" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="hammer") ) dp=dp/2;
if (mweaponn=="whip" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="none") ) dp=dp/2;
//���ּ�ǿ
if (vweaponn=="none" && victim->query("apply/damage"))
{
if (mweaponn="sword" || mweaponn="blade" || mweaponn="dagger" || mweaponn="hammer"  || mweaponn="whip")
{
if (victim->query("apply/damage",1) >= 600) dp=dp*2;
else if (victim->query("apply/damage",1) >= 400) dp=dp+dp/2;
else if (victim->query("apply/damage",1) >= 200) dp=dp+dp/3;
}
}	

		if (userp(me) && me->query_temp("xmud") && victim)
{
                       tell_object(me, "$tname" +
                                        victim->query("name") + "$tqi" +
                                        victim->query("qi") + "$tmqi" +
                                        victim->query("max_qi")+ "$tjing"+victim->query("jing")+ "$tmjing"+victim->query("max_jing")+"$#\n");

		}

		if (userp(victim) && victim->query_temp("xmud") && me)
{
                       tell_object(victim, "$tname" +
                                        me->query("name") + "$tqi" +
                                        me->query("qi") + "$tmqi" +
                                        me->query("max_qi")+ "$tjing"+me->query("jing")+ "$tmjing"+me->query("max_jing")+"$#\n");

		}

if (mweaponn=="none" && me->query("combat_exp",1)>=victim->query("combat_exp",1)	 ) ap=ap+ap/2;

	if( random(ap + dp) < dp )
	{ // Does the victim dodge this hit?
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
		damage = RESULT_DODGE;
if ( userp(victim) && random(3)==0 && me->query("combat_exp",1) > victim->query("combat_exp",1)/3 ) victim->improve_skill("dodge", 1);
	} 
	else {
	//	(4) Check if the victim can parry this attack.
	    pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
		if( victim->query_temp("weapon") ) 
		{
			if( !weapon ) pp *= 2;
		} else 
		{
			if( weapon ) pp /= 2;
		}

		if( victim->is_busy() ) pp /= 3;
		if( pp < 1 ) pp = 1;

		if( random(ap + pp)< pp ) 
		{	parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.
if ( userp(victim) && random(3)==0 && me->query("combat_exp",1) > victim->query("combat_exp",1)/3 ) victim->improve_skill("parry", 1);
			result += SKILL_D("parry")->query_parry_msg(weapon);
			damage = RESULT_PARRY;
		} else 
		{//	(5) We hit the victim and the victim failed to parry

if ( victim->query("qi",1) >=5 && userp(me) && random(3)==0 && victim->query("name")!="ľ��"  && victim->query("name")!="ͭ��")
{
cstra=me->query("int");
if (cstra>=60) cstra=60;
if (victim->query("max_qi",1)/victim->query("qi",1)>=4)
{
if (me->query("combat_exp",1)<8000000 && victim->query("combat_exp",1) >= me->query("combat_exp",1)/2)
{
me->add("potential",2);
me->add("combat_exp",3);
}
me->add("potential",1);
me->add("combat_exp",1);
if (attack_skill) me->improve_skill(attack_skill, (random(cstra)+1));
}
}			attack = 1;
			damage = me->query_temp("apply/damage");
if (me->query_temp("apply/strength") > 1800)
me->set_temp("apply/strength",1800);
if (me->query_temp("apply/intelligence") > 1800)
me->set_temp("apply/intelligence",1800);
if (me->query_temp("apply/constitution") > 1800)
me->set_temp("apply/constitution",1800);
if (me->query_temp("apply/dexerity") > 1800)
me->set_temp("apply/dexerity",1800);
if (me->query_temp("apply/attack") > 1800)
me->set_temp("apply/attack", 1800);
if (me->query_temp("apply/defense") >  1800)
me->set_temp("apply/defense", 1800);
if (me->query_temp("apply/damage") >  28000)
me->set_temp("apply/damage", 28000);
if (me->query_temp("apply/armor") >  28500)
me->set_temp("apply/armor", 28500);
if (me->query_temp("apply/dodge") > 1800)
me->set_temp("apply/dodge",1800);
if (me->query_temp("fight/dodge") > 1800)
me->set_temp("fight/dodge",1800);
			if ( damage > 1888 ) damage = 1888;
			damage = (4*damage + random(damage)) / 5;
			
			if (!weapon)
      {
      if( action["damage"] )
			damage += 1+action["damage"]*3;//��ʱ�ر�
      damage += me->query_str()*2;
      if (!weapon && me->query("armor/hands"))
			damage += me->query("apply/damage",1)*2;

      //if( action["damage"] && me->query("armor/hands"))
      //damage += action["damage"];
}

		    if (weapon)
			damage += me->query_skill(attack_skill) * damage / 500;
cstra=me->query_str();
if (cstra > 800) cstra =800;
			damage_bonus = cstra * 2;
dexa=random(6);
if (damage>30 && random(3)==0)
{
if (dexa==0 && (int)random(victim->query("str")) >= (int)me->query("str")/2) damage=damage/2;
if (dexa==1 && (int)random(victim->query("con")) >= (int)me->query("con")/2) damage=damage/2;
if (dexa==2 && (int)random(victim->query("dex")) >= (int)me->query("dex")/2) damage=damage/2;
if (dexa==3 && (int)random(me->query("kar")) >= (int)victim->query("kar")/2) damage=damage+(int)(88+(me->query("kar")*10));
if (dexa==4 && (int)random(me->query("per")) >= (int)victim->query("per")/2) damage=damage+(int)(88+(me->query("per")*10));
if (dexa==5 && (int)random(me->query("int")) >= (int)victim->query("int")/2) damage=damage+(int)(88+(me->query("int")*10));
//message_vision(CYN"\n$N����Ч��"+dexa+"��\n"NOR,me);
}
			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
				if( force_skill = me->query_skill_mapped("force") ) {
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					if( intp(foo) )
					{
				if (foo>600) foo=600;	
				}
					else if( intp(foo) ) damage_bonus += foo;
				}
			}

            damage_bonus += me->query_skill(attack_skill) * damage_bonus / 1000;
			if( weapon ) damage_bonus -= damage_bonus/3 ; 
			if( martial_skill = me->query_skill_mapped(attack_skill) ) {
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
					if( intp(foo) )
					{
				if (foo>600) foo=600;	
				}

				else if(intp(foo) ) damage_bonus += foo;
			}
			// Let weapon or monster have their special damage.
			if( weapon ) 
			{
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			} else 
			{

			if ( objectp(nweapon = me->query_temp("armor/hands")) && !weapon) {
 //tell_object(me, HIW "����"+nweapon->query("name")+"����Ч��\n" NOR);
	foo =  nweapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
else
{
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
}
			}

			if( martial_skill = victim->query_skill_mapped("dodge") ) {
				foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if( martial_skill = victim->query_skill_mapped("parry") ) {
				foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
			    if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

                if( martial_skill = victim->query_skill_mapped("force") ) {
				foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
/*
			if (foo = victim->query_temp("armor/cloth")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/armor")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/boots")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/head")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			if (foo = victim->query_temp("armor/shield")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

*/
			if (foo = victim->query_temp("armor/cloth")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/armor")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/boots")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}

			if (foo = victim->query_temp("armor/head")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}
			if (foo = victim->query_temp("armor/shield")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}

			if (foo = victim->query_temp("armor/hands")  && weapon ) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}
			
			if (foo = victim->query_temp("armor/neck")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}			

			if (foo = victim->query_temp("armor/surcoat")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}			

			if (foo = victim->query_temp("armor/waist")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}
			
			if (foo = victim->query_temp("armor/wrists")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}			
			if( damage_bonus > 0 )
			damage += (4*damage_bonus + random(damage_bonus))/5;
			if( damage < 0 ) damage = 0;
			// Let combat exp take effect
ccona=victim->query_con();
if (ccona > 800) ccona=800;
if (damage< 1) damage=1;
if (ccona<1) ccona=1;
			damage = damage * 20 / ( ccona + 16);
//�������ϵͳ
if (victim->query("race")!="Ұ��")
{
if (mweaponn=="sword" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="throwing") ) damage=damage*2;
if (mweaponn=="blade" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="sword") ) damage=damage*2;
if (mweaponn=="dagger" && (vweaponn=="none" || vweaponn=="blade" || vweaponn=="sword"  || vweaponn=="throwing" || vweaponn=="whip") ) damage=damage*2;
if (mweaponn=="axe" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="blade" || vweaponn=="sword") ) damage=damage*2;
if (mweaponn=="hammer" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="sword" || vweaponn=="none") ) damage=damage*2;
if (mweaponn=="club" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="hammer") ) damage=damage*2;
if (mweaponn=="staff" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="axe") ) damage=damage*2;
if (mweaponn=="none" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="axe") ) damage=damage*2;
if (mweaponn=="throwing" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="hammer") ) damage=damage*2;
if (mweaponn=="whip" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="none") ) damage=damage*2;

//���ּ�ǿ
if (vweaponn=="none" && victim->query("apply/damage"))
{
if (mweaponn="sword" || mweaponn="blade" || mweaponn="dagger" || mweaponn="hammer"  || mweaponn="whip")
{
if (victim->query("apply/damage",1) >= 600) damage=damage/2;
else if (victim->query("apply/damage",1) >= 400) damage=damage-damage/2;
else if (victim->query("apply/damage",1) >= 200) damage=damage-damage/3;
}
}	

}	



if (damage>10)
{
if (userp(me) && me->query("5zhuan") ) damage=damage*4+10;
else if (userp(me) && me->query("4zhuan")) damage=damage*3+10;
else if (userp(me) && me->query("zhuanbest")) damage=damage*2+10;
else if (userp(me) && me->query("zhuanshen")) damage=damage+damage/2+10;	
	
	
if (userp(victim) && victim->query("5zhuan") ) damage=damage-damage/1.5;
else if (userp(victim) && victim->query("4zhuan")) damage=damage-damage/2;
else if (userp(victim) && victim->query("zhuanbest")) damage=damage-damage/3;
else if (userp(victim) && victim->query("zhuanshen")) damage=damage-damage/4;
}

		    if (mweaponn=="none" )
			{
			damage += me->query_str()*6;
			if (me->query("armor/hands"))
			damage += me->query("apply/damage",1)*2;
	
      }
      else
      {
      damage += me->query_int();
      damage += me->query_con();
      damage += me->query_dex()*2;
      }	



if (victim->is_busy() && !victim->query_temp("pending/exercise"))
{
dexa=victim->query_busy();
if (dexa >=3)
{
if (dexa>=2) dexa=(int)dexa/2;
if (dexa>=20) dexa=20;
if (dexa <= 1) dexa=1;
victim->start_busy(dexa);
}
}

if (userp(me) && me->query("str") && me->query("age") >=18 )
	{
		
		dexa=me->query("age",1);
		if (dexa >30) dexa=30;
		cstra= me->query("str",1)*dexa;
		if (!userp(me) && cstra >2800) cstra=2800;
		if (cstra>5000) cstra=5000;
	damage += cstra;
	}
	
if (victim->query("dex") && victim->query("age") >=18 )
	{
		
		dexa=victim->query("age",1);
		if (dexa >30) dexa=30;
		cstra= victim->query("dex",1)*dexa;
		if (!userp(victim) && cstra >2800) cstra=2800;
		if (cstra>5000) cstra=5000;

	if (damage >=cstra)
	{
	damage -=cstra;
	}
	else
	{
	damage =1;
	}
	
	}
 
                         // ���ݹ����Ĳ�λӰ���˺�
                        if (! undefinedp(limb_damage[limb]))
                                {
                                
		if (userp(me) && me->query("env/combat"))
                        tell_object(me, HIW "( ��λ:" +
                                        limb + HIW "���" +
                                        limb_damage[limb] + "% ԭʼ:"+damage+"����:"+(damage * limb_damage[limb] / 100)+"��\n" NOR);
damage = (damage * limb_damage[limb] / 100);
}                                       
                                        
			damage = victim->receive_damage("qi", damage, me);
			if( random(damage) > (int)victim->query_temp("apply/armor") && ( (me->is_killing(victim->query("id"))) 
				&& ((!weapon) && !random(4) || weapon && !random(2) )
			    || ((!weapon) && !random(7) || weapon && !random(4) ) )  )
			{
				// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("qi",damage - (int)victim->query_temp("apply/armor"), me);
				wounded = 1;
			}
		result += damage_msg(damage, action["damage_type"]);
		damages = damage;
		wounds= damage - (int)victim->query_temp("apply/armor");
if (damages <0) damages=0;
if (wounds <0) wounds=0;



		if (userp(me) && (me->query("env/combat_show") || me->query_temp("xmud")))
                        tell_object(me, HIW "( ���" +
                                        victim->query("name") + HIW "���" +
                                        damages + "���˺���" +
                                        wounds + "�㴴�ˡ�)\n" NOR);
                if (userp(victim) && (victim->query("env/combat_show") || victim->query_temp("xmud")))
                        tell_object(victim, HIG "( ���ܵ�" +
                                        me->query("name") + HIG + damages + "���˺���" +
                                        wounds + "�㴴�ˡ�)\n" NOR);		

		}
	} 
//if( flag && userp(me) && victim ) 
	//victim->set_temp("last_damage_from", foo);

	result = replace_string( result, "$l", limb );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "��ָ" );

	message_combatd(result, me, victim );


 if (attack == 1)
                {
                        int pers;

                        switch(limb)
                        {
                        // ͷ�������˻���һЩ��
                        case "ͷ��":
                        case "����":
                                damage /= 4;
                                if (damage < 1)
                                        damage = 1;
                                if (damage > 8000)
                                        damage = 8000;
                                victim->receive_damage("jing", damage, me );
                                pers = victim->query("jing")*100/victim->query("max_jing");
                                if (pers <= 30)
                                        tell_object(victim, head_damage_me_msg[2]);
                                else if (pers <= 70)
                                        tell_object(victim, head_damage_me_msg[1]);
                                else
                                        tell_object(victim, head_damage_me_msg[0]);
                                break;
                        // ������Щ��λ�������ܵ��񵴡�
                        case "�ؿ�":
                        case "����":
                        case "С��":
                                if (victim->query("max_neili") && victim->query("neili"))
                                {
                                        string report_limb_msg;

                                        damage /= 4;
                                        if (damage < 1)
                                                damage = 1;
                                        if (damage > 10000)
                                                damage = 10000;
                                        if (victim->query("neili") <= damage)
                                                victim->set("neili", 0);
                                        else
                                                victim->add("neili", -damage);
                                        if (damage <= 500)
                                                report_limb_msg = body_damage_me_msg[0];
                                        else if (damage <= 1000)
                                                report_limb_msg = body_damage_me_msg[1];
                                        else
                                                report_limb_msg = body_damage_me_msg[2];
                                        report_limb_msg = replace_string(report_limb_msg, "$l", limb);
                                        tell_object(victim, report_limb_msg);
                                }
                                break;
                        }
                }

	if ( wizardp(me) && me->query("env/combat") )
	{
	if( damage > 0 )
		{
			// tell_object(me, HIG "( �������" +
                        //                mweaponn + HIG + vweaponn + "\n" NOR);		

			
			tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
				ap/100, dp/100, pp/100, damage));

			tell_object(victim, sprintf( GRN "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
				ap/100, dp/100, pp/100, damage));
		}
			else
			{tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d\n" NOR,
				ap/100, dp/100, pp/100));
			tell_object(victim, sprintf( GRN "AP��%d��DP��%d��PP��%d\n" NOR,
				ap/100, dp/100, pp/100));
			}
	}
	
	if( damage > 0 ) {
		report_status(victim, wounded);
		if( victim->is_busy() ) victim->interrupt_me(me);
		if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) &&
		victim->query("qi")*2 <= victim->query("max_qi")) 
		{
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			fight_reward(me, victim);
			fight_penalty(me, victim);		
			if (me->query("race") == "����") {

if (userp(me) && userp(victim))
	{
			if( query_ip_name(victim)!=query_ip_name(me) )
			me->add_temp("mpjobn4",1);
	}	

if (userp(me) && userp(victim) && (me->query_temp("hdjoblb")=="��ս" || victim->query_temp("hdjoblb")=="��ս") )
{
addnl(me,"exp",3000+random(888));
addnl(me,"score",200);
addnl(victim,"exp",2000+random(888));
addnl(victim,"score",100);
if (me->query_temp("hdjoblb")=="��ս")
{
me->delete_temp("hdjoblb");
me->delete_temp("hdjobtg");
me->delete_temp("hdjobsc");	
me->clear_condition("taskjob_busy");
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
}	
if (victim->query_temp("hdjoblb")=="��ս")
{
victim->delete_temp("hdjoblb");
victim->delete_temp("hdjobtg");
victim->delete_temp("hdjobsc");	
victim->set_temp("tjobstart",0);
victim->delete_temp("tjobstart");
}
}	
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
			} else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, victim);			
/*// �����ֳ�ת�� start
			result = winner_msg[random(sizeof(winner_msg))];
			result = replace_string(result,  "$P", me->name());
			result = replace_string(result,  "$N", me->name());
			result = replace_string(result,  "$n", victim->name());
			result = replace_string(result,  "$p", victim->name());
			if ((string)environment(me)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);
// �����ֳ�ת�� end*/
		}
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);


}

//	fight()
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
void fight(object me, object victim)
{
	object ob;
	string result;
// �����ֳ�ת�� start
//	player=users();
// �����ֳ�ת�� end
	if( !living(me) ) return;
	
	if( !victim ) return;
	if( !me ) return;
	
        if (userp(me) && environment(me)->query("no_fight")) return;
        if( me->query_temp("combat_yield") && userp(me) && userp(victim)
                ) return;
	// If victim is busy or unconcious, always take the chance to make an attack.


			 if ((random(4)==0 || wizardp(me)) && userp(me))
{
switch (random(2))
	{
		case 0:
		if ( (me->query("max_qi") > me->query("eff_qi") || me->query("eff_qi") > me->query("qi"))
		&& random(2)==0 && (int)me->query_temp("ana_t/reqi")>=1  && (int)me->query_skill("force",1)>=1 ) {
			message_vision(HIR"ֻ��$N����������������ȫ�����ܵ����ƺ����˺ܶ࣡\n"NOR, me);
			if (me->query("eff_qi",1) < me->query("max_qi",1))
			me->add("eff_qi",  50+((int)me->query_temp("ana_t/reqi")*2)*me->query_skill("force")/100);
			
			if (me->query("eff_qi") > (me->query("max_qi")*10))
				me->set("eff_qi", me->query("max_qi"));
			
			if (me->query("qi",1) < me->query("max_qi",1))
			me->add("qi", 50+((int)me->query_temp("ana_t/reqi")*2)*me->query_skill("force")/150);
			
			if (me->query("qi") > (me->query("eff_qi")*10))
				me->set("qi", me->query("eff_qi"));
		}
		break;
		case 1:
		if ( (me->query("max_jing") > me->query("eff_jing") || me->query("eff_jing") > me->query("jing"))
		&& random(2)==0 && (int)me->query_temp("ana_t/rejing") >=1  && (int)me->query_skill("force",1)>=1 ) {
			message_vision(HIY"ֻ��$N��˫�ۿ���֮�������֣������ʱ����\n"NOR, me);
			if (me->query("eff_jing",1) < me->query("max_jing",1))
			me->add("eff_jing",  50+((int)me->query_temp("ana_t/rejing")*2)*me->query_skill("force")/100);
			
			if (me->query("eff_jing") > (me->query("max_jing")*10))
				me->set("eff_jing", me->query("max_jing"));
			
			if (me->query("jing",1) < me->query("max_jing",1))
			me->add("jing", 50+((int)me->query_temp("ana_t/rejing")*2)*me->query_skill("force")/150);
			
			if (me->query("jing") > (me->query("eff_jing")*10))
				me->set("jing", me->query("eff_jing"));
		}
		break;
	}
}	
		

	if( victim->is_busy() || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		if( me && victim) do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian")
                || (me->query("double_attack") && !objectp(me->query_temp("weapon"))) 
                || me->query_temp("double_attack"))
		{
		if (me->query("double_attack") && sizeof(me->query_skill_prepare()) < 2)
			message_vision(CYN"\n$N˫�ַ�ʹ������쳣�����������������Ƶģ�\n"NOR,me);
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		   if (userp(me) && random(2)==0) 
		   {
		   victim->receive_wound("qi", (random(me->query_str())+10), me);
		}
		   me->delete_temp("action_flag");
	     	}

	// Else, see if we are brave enough to make an aggressive action.
		} else if( me->query_temp("guarding")||
					random( (int)me->query_dex()  ) > random( (int)victim->query_dex() )) 
		{	me->set_temp("guarding", 0);
			if( !victim->is_fighting(me) ) victim->fight_ob(me);  
			if(me && victim) do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);


		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian")
                || (me->query("double_attack") && !objectp(me->query_temp("weapon"))) 
                || me->query_temp("double_attack"))
		{
		if (me->query("double_attack") && sizeof(me->query_skill_prepare()) < 2)
			message_vision(CYN"\n$N˫�ַ�ʹ������쳣�����������������Ƶģ�\n"NOR,me);
		   me->set_temp("action_flag",1);
		   if(me && victim) 
		   {
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
				   if (userp(me) && random(2)==0) 
		   {
		   victim->receive_wound("qi", (random(me->query_str())+10), me);
		}

		}
		   
		   me->delete_temp("action_flag");
	     	}

	// Else, we just start guarding.
	} else 
	{
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
// �����ֳ�ת�� start
/*		result = guard_msg[random(sizeof(guard_msg))];
		result = replace_string(result,  "$P", me->name());
		result = replace_string(result,  "$N", me->name());
		result = replace_string(result,  "$n", victim->name());
		result = replace_string(result,  "$p", victim->name());
		if ((string)environment(me)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);*/
// �����ֳ�ת�� end
		return;
	}
	return;
}

//	auto_fight()
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;
	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);
	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if( !userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 ) return;

	if( shen > (int)me->query("score") 
	&&	!wizardp(obj) ) {
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
			+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
			+ "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	if(	me->query_temp("owner") == obj->query("id")	// be trained
	||	obj->query_temp("owner") == me->query("id") 	// be trained
	)	return;

	// We found our hatred! Charge!
	if (me->query("race") == "����") {
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	} else message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
        if (!userp(me))
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
// �����ֳ�ת�� start
//	player=users();
// �����ֳ�ת�� end
	switch(event) {
		case "dead":
message_vision( NOR"\n$N��ž����һ�����ڵ��ϣ���������˿��Ѫ��ʹ��������˼��¾����ˡ�\n\n" NOR, ob);
// �����ֳ�ת�� start
//			if ((string)environment(ob)->query("short") == "��̨")
//			for (userno=0; userno<sizeof(player); userno++)
//			    if ((player[userno])->query_temp("view_leitai"))
//				tell_object(player[userno], "\n"+ob->name()+"��ž����һ�����ڵ��ϣ���������˿��Ѫ��ʹ��������˼��¾����ˡ�\n");
// �����ֳ�ת�� end
			break;
		case "unconcious":
			message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
// �����ֳ�ת�� start
//			if ((string)environment(ob)->query("short") == "��̨")
//			for (userno=0; userno<sizeof(player); userno++)
//			    if ((player[userno])->query_temp("view_leitai"))
//				tell_object(player[userno], "\n"+ob->name()+"����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n");
// �����ֳ�ת�� end
			break;
		case "revive":
		        if(ob->query("blind") || ob->query("race") != "����")
			     message_vision("\n$N����һ����Ť���˼��£������˹�����\n\n", ob);
			else if(ob->query("mute"))
			     message_vision("\n$N���������˹����������۾�վ����ҡ��ҡͷ��\n\n", ob);
			else message_vision("\n$N���Ӷ��˶������������˼��������ѹ�����\n\n", ob);
// �����ֳ�ת�� start
//			if ((string)environment(ob)->query("short") == "��̨")
//			for (userno=0; userno<sizeof(player); userno++)
//			    if ((player[userno])->query_temp("view_leitai"))
//				tell_object(player[userno], "\n"+ob->name()+"���������۾��������˹�����\n\n");
// �����ֳ�ת�� end
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	int gain,gain1;
	int bls,zhenfa=0;
	object env;
	string vmark;
	string temp;
	string str,killerid,info,infot;
	string msg="Ī����������ˡ�";
	mapping quest, actions;
	int exp, pot, score, bonus,factor;
	int student_num;
	// Call the mudlib killer apply.
	killer->killed_enemy(victim);
	env = environment(victim);

	if(objectp(env))
	if ( env->query("no_death_penalty")) 
	{
	victim->set_temp("no_death_penalty",1);
	return;
	}
	
if (killer)
{
		if (userp(killer) && killer->query_temp("xmud") && victim)
{
                       tell_object(killer, "$tname" +
                                        "��" + "$tqi" +
                                        "0" + "$tmqi" +
                                        "0"+ "$tjing"+"0"+ "$tmjing"+"0"+"$#\n");
		}

}
	
if (env && environment(victim)->query("no_fight")
&& killer && victim->query_condition("killer"))
{
log_file("log", "��NF��ROOM����ͨ��������" + base_name(environment(victim)) +"\n", 1);
log_file("log", "�������" + killer->query("id") + killer->query("name")+"\n", 1);
log_file("log", "��������" + victim->query("id") + victim->query("name")+"\n", 1);
}
if (env && environment(victim)->query("no_fight")
&& killer && !victim->query_condition("killer"))
{
log_file("log", "��NF��ROOM��������������" + base_name(environment(victim)) +"\n", 1);
log_file("log", "�������" + killer->query("id") + killer->query("name")+"\n", 1);
log_file("log", "��������" + victim->query("id") + victim->query("name")+"\n", 1);
}

if (killer)
{
killer->remove_all_enemy(victim);
killer->remove_all_killer(victim);

if (killer->query("id")=="xun bu")
{
killer->remove_all_enemy();
killer->remove_all_killer();
}
}

if (mapp(victim->query("killer_reward")) && userp(killer))
{
   BG_D->killer_rewardboss(killer, victim, victim->query("killer_reward"));
//log_file("log", "��ʼ������" + base_name(environment(victim)) +"\n", 1);
}

	if( userp(killer) || userp(victim) ) 
	{
 FAMILY_D->family_kill(killer, victim);
}

	if( userp(victim)) 
	{
/*		if (userp(killer) && killer->query_condition("killer"))
{
        	killer->add("qiushi/times",1);
		killer->add("qiushi/totaltime",killer->query("qiushi/howlong"));
		killer->set("qiushi/inage",killer->query("mud_age"));
        	killer->set("startroom","/d/death/qiushi");
                killer->set("qiushi/howlong",180);
                killer->move("/d/death/qiushi");
		killer->apply_condition("killer", 800 +
			killer->query_condition("killer"));
		killer->apply_condition("tongji_poison", 800);

		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("ͨ����%s���ؽ������ҡ�", killer->name(1), killer->name()));
}*/
		if ( victim->query_condition("killer") && userp(killer))
		zhenfa=1;
		else if(!victim->is_killing(killer->query("id")))
		{
		killer->add("PKS", 1);
		if (userp(killer))
{
//		killer->apply_condition("killer", 120 +
//			killer->query_condition("killer"));
					if (killer->query_temp("kill_other/"+victim->query("id"))) {
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name()));
						killer->apply_condition("killer",
							800 + killer->query_condition("killer") * 3 / 2);
if ((int)victim->query("combat_exp") < (int)killer->query("combat_exp")/2)
                                                //killer->apply_condition("tongji_poison", 800);

                                                victim->apply_condition("nokill", 800);
					} else if (victim->query_temp("kill_other/"+killer->query("id")))
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%s��������ɱ���ˡ�",
								victim->name(1), killer->name()));
					else {
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%sʧ�ְ�%sɱ���ˡ�",
								killer->name(), victim->name(1)));
						killer->apply_condition("killer",
							800 + killer->query_condition("killer"));
if ((int)victim->query("combat_exp") < (int)killer->query("combat_exp")/2)
                                                //killer->apply_condition("tongji_poison", 800);
					victim->apply_condition("nokill", 800);
					}
					killer->delete_temp("kill_other/"+victim->query("id"));
					victim->delete_temp("kill_other/"+killer->query("id"));
					killer->delete_temp("other_kill/"+victim->query("id"));
					victim->delete_temp("other_kill/"+killer->query("id"));

}
		}
if (killer->query("id")=="xun bu")
{
killer->remove_all_enemy();
killer->remove_all_killer();
}
victim->remove_all_enemy();
victim->remove_all_killer();
if (!victim->query_condition("killer"))
{
		victim->clear_condition();
}
	   // CHANNEL_D->do_channel(this_object(), "rumor",str);
if (killer->query("id")!=victim->query("id"))
{
		victim->add("shen", -(int)victim->query("shen") / 10);
		if (victim->query("combat_exp")>1200000)
{
		if (victim->query("max_neili")>1000)
		{
			victim->add("max_neili", -50);
		}
}
		if (victim->query("combat_exp")>500000 ||
		victim->query_condition("killer"))
{
		victim->clear_condition();
		victim->add("combat_exp", -(int)victim->query("combat_exp") / 500);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
		((int)victim->query("learned_points") - (int)victim->query("potential"))/5 );
		victim->skill_death_penalty();
}
		victim->delete("vendetta");
		if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
                victim->set("killbyname",killer->query("id"));
		victim->save();
}
		bls = 10;
		if(objectp(killer))
		{
			msg="��"+killer->name(1);
			actions = killer->query("actions");
			switch(actions["damage_type"]) {
			case "����":
		    case "����":
				msg+="�����ˡ�";
				break;
			case "����":
				msg+="�����ˡ�";
				break;
			case "����":
				msg+="�����ˡ�";
				break;
			case "����":
				msg+="�����ˡ�";
				break;
			default:
				msg+="ɱ���ˡ�";
			}
		}
		if (zhenfa==1)
{
		victim->apply_condition("killer", 0);
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("ͨ����%s��%s�͵������ˡ�", victim->name(1), killer->name()));

                if (victim->query("combat_exp") > 800000
                && victim->query("combat_exp") > killer->query("combat_exp")/3)
{
addnl(killer,"exp",600);
addnl(killer,"score",500);
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s�Ľ������������!!��",  killer->name()));
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s�õ��˹ٸ��Ľ���!", killer->name(), killer->name()));
}
}
		else 
{
		if ( victim->query_condition("killer"))
{
                victim->apply_condition("killer", 0);		

}
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s"+msg, victim->name(1)));
		//�ٸ���ʼͨ���ﷸ��
		write_file("/log/static/KILLRECORD",sprintf("%s   ɱ����   %s on %s\n", killer->name(1),victim->name(1), ctime(time()) ));
}
	} else {
		killer->add("MKS", 1);
		bls = 1;
	}


	if (userp(killer) && killer->query("combat_exp") < victim->query("combat_exp"))
	killer->add("shen", -(int)victim->query("shen") / 10);

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

	if(     ( (int)killer->query("combat_exp") < victim->query("combat_exp"))
		&& (victim->query_condition("sexman")))
	{
		tell_object(killer,"��ϲ�㣡��Ϊ���ֳ���һ����\n");
		exp = 100 + random(500);
		pot = 50 + random(100);
		score = 50 + random(100);
addnl(killer,"exp",exp);
addnl(killer,"score",score);
                killer->add("shen",50);
		killer->set("quest", 0 );
	}
// ������ɱ������ 
info = read_file("/data/npc/menpai.o");
infot = read_file("/data/npc/menpai1.o");

if (userp(killer) && killer->query("family/family_name") == info
&& victim->query("family/family_name") == infot
&& !killer->query_condition("menpai_kill")
&& info
&& infot
)
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
{
if (userp(victim))
{
if ((int)killer->query("combat_exp")/3 < victim->query("combat_exp")
&& !killer->query_condition("menpai_kill"))
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
addnl(killer,"exp",exp);
addnl(killer,"score",score);

tell_object(killer,HIR"��ϲ�㣡�����˱���֮�У�\n"NOR);
killer->apply_condition("menpai_kill",3);
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);

						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

}
}
else {
exp=random(200)+110;
pot=exp/2;
score=exp/3;
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);
						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

addnl(killer,"exp",exp);
addnl(killer,"score",score);

tell_object(killer,HIR"��ϲ�㣡�����˱���֮�У�\n"NOR);
killer->apply_condition("menpai_kill",3);
}
}
}

//����
if (userp(killer) && killer->query("family/family_name") == infot
&& victim->query("family/family_name") == info
&& !killer->query_condition("menpai_kill")
&& info
&& infot
)
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
{
if (userp(victim))
{
if ((int)killer->query("combat_exp")/3 < victim->query("combat_exp")
&& !killer->query_condition("menpai_kill"))
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);
						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

addnl(killer,"exp",exp);
addnl(killer,"score",score);

tell_object(killer,HIR"��ϲ�㣡�����˱���֮�У�\n"NOR);
killer->apply_condition("menpai_kill",3);
}
}
else {
exp=random(200)+110;
pot=exp/2;
score=exp/3;
addnl(killer,"exp",exp);
addnl(killer,"score",score);

tell_object(killer,HIR"��ϲ�㣡�����˱���֮�У�\n"NOR);
killer->apply_condition("menpai_kill",3);
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);
						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

}
}
}
	if (userp(victim))
	{
		return;
	}

	if( interactive(killer) && (quest = killer->query("quest"))
		&& (quest["quest_type"]=="ɱ")
		&& ( (int)killer->query("task_time") >= time())
		&&(quest["quest"]==victim->query("name")))
	{
		tell_object(killer,"��ϲ�㣡���������һ������\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+25;
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2)+15;
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=victim->query("quest_factor");
		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
                exp=exp/2+1;
  if (exp < 90) exp=88+random(22);
if (!killer->query("zhuanshen") && killer->query("combat_exp",1)<=12000000 ) exp=exp*5;              
                addnl(killer,"exp",exp);
                addnl(killer,"score",score);

		bonus = (int)killer->query("shen");
		if(bonus >= 0)
			bonus += score;
		else
			bonus -= score;
		killer->set("shen", bonus);
		
		if ((int)killer->query_temp("menpaikill")==1)
		{
		killer->add_temp("menpaijob",1);
		killer->delete_temp("menpaikill");	
		}
		killer->set("quest", 0 );
	}
	
}
//ɱ����

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}



