// questlist.c
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string *jm1=({
"��δ��ʼ",
"ҹ̽�̼ұ� ������ˮ��",
"��ɽС��ͤ ��սԬ����",
"���������� �������Ż�",
"�Ǿ����˷� սʤ���ũ",
"���������� ս�ܶ���",
"ս���۵�ʤ �ñ�������",
});

string *jm2=({
"��δ��ʼ",
"�ػ������� �����ǿ��",
"������ʷ� �ȳ�������",
"�ⴳ������ ���������",
"�ܴ��ڸ��� ���������",
});
string *jm3=({
"��δ��ʼ",	
"�������ɽ �����ǽ���",
"���ֺڼ��� �ȳ�������", 
"���仨��ˮ ��Ѫ����ɮ",
"����Ůˮ�� ɱѪ����ɮ",
"����ܵ��� �����Ǳ���",
});
string *jm4=({
"��δ��ʼ",	
"��̽����ɽ ��ɽ��Ѱ��",
"���Ĵ���� ��ս�ȶ���",
"���������� ��ս������",
"����̽Ľ�� ���Ľ�ݸ�",
"ʶ������� ��ؤ�����",
"����ң��� ��ܶ�����",
"����ɽͯ�� ����ʮ����",
"̽���Ļʹ� սʤ����ˮ",
"�¶������� ��˫����ս",
"����ɹ��� �ܵн��Ƿ�",
});
string *jm5=({
"��δ��ʼ",	
"������ľ�� ���÷����",
"�Ա������� ����ͽ�",
"Ѱ��ɳ�߶� ʤ�һ���ͽ",
"�����л��� ս��ŷ����",
"�һ���̽�� Ӯ��������",
"½��ׯ�Ƶ� ��ܽ����",
"����ͽ��ս ��һ�ƴ�ʦ",
"����ɽ̽�� ����������",
"������Σ�� �����״��",
"�ڻ�ɽ�۽� ����ѧ���",
});
string *jm6=({
"��δ��ʼ",	
"ɱͷ�ǻ�ʤ ��ս����ʤ",
"��ս�´ﺣ ����������",
"���߲��Թ� �ܽ��ϻ���",
"��߲��Թ� ����������",
"ʶ����ҿ� ��ܼ�����",
});

string *jm7=({
"��δ��ʼ",	
"Ӫ��ìʮ�� �پȰ�����",
"����ػ��� ��ׯ������",
"��ɱ���ݻ� ����˫����",
"����̽���� ʶ�Ƽٻʺ�", 
"���������� ��ܺ����",
"��������� ��ɱ������",
"�����ر߽� ����������",
"����ʮ���� ����屦��",
});
string *jm8=({
"��δ��ʼ",	
"��������� ��������",
"�ø����ھ� �پ���ƽ֮",
"����ﲮ�� �Ǿ�С����",
"����˼���� Լ��������",
"Ѱ��ҩ���� �ܽ�������", 
"�ܵ���׷ɱ ����������",
"���ܷ�÷ׯ �Ǿ�������",
"������Ⱥ�� �ȳ���ӯӯ",
"ҹ̽��ľ�� ɱ��������",
"��ɽ����� ����������",
"��������� �ܿ�����а",
});
string *jm9=({
"��δ��ʼ",	
"��ͤ����� ����̩���",
"Ӳ������ׯ �ưٻ���ȭ",
"���Ȼ���ͩ ����կ�ᱦ",
"��ɱ������ ����������",
"���ݾȻʵ� ��ܳ¼���",
});

string *jm10=({
"��δ��ʼ",	
"��ȫ����� ȫ��ܻ���",
"�����Ī�� ����½��˫",
"�����ִ�� ������ʤ��",
"�������� �ȳ���ǧ��",
"���������� ɱ����־��",
"�������� �������ؽ�",
"�Ǵ�����̶ ̽����ȵ�",
"�ȳ�С���� ɱ���ַ���",
});
string *jm11=({
"��δ��ʼ",	
"Ѱ�������� �������̾�",
"ս�ض��İ� �ȴ�����",
"�ȳ�ʯ���� ��ܱ���ʯ",
"Ӳ�������� ��ܰ�����",
"���ͷ����� ����ڵ���",
});
string *jm12=({
"��δ��ʼ",	
"���𵺽��� �̳����޼�",
"�ػ��䵱�� ��������", 
"��������� ��������",
"�����̽��� ����������",
"̽������ׯ �ú�����ҩ",
"�������ߵ� �ܲ�˹��ʹ",
"̽������ ����ڤ����",
"�������ɮ ɱ����С��",
});
string *jm13=({
"��δ��ʼ",	
"���ɱ����� ������ѩ��",
"�γ����߽� ɱ�о�����",
"�嶾��̽�� ��ܺ�����",
"���������� ���Ԭ��־",
"��ܻ�̫�� ŭɱ�ܻ���",
});

string *jm14=({
"��δ��ʼ",	
"��ս�ڷ�կ �¾����л�",
"���ϳ����� �ɽ����Ƶ�",
"ɱ������ ���˹�̽��",
"���ؽ����� ����ĸ���",
"�ǵú�Կ�� ��սԬ����",
});


void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob, obt;
        string hymsg;
	mapping my;
	string line, str, skill_type,zs,zs1,zs2;
	object weapon;
        int attack_points, dodge_points, parry_points, btmp, t, d, r,money,i,zs3,zs4,money2;
        int a,b,c,hylv;
	seteuid(getuid(me));
        btmp=1;
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
                obt = find_player(arg);
                if ( !obt ) btmp=0;
                if (!ob) ob = obt;
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");


write(HIC"��"+HIY"��������������������������������������������������������������"HIC"��\n"NOR);
write(HIW"��"HIM"�� �� �⴫"HIW"��"HIY+jm1[ob->query("jinyong/book1")]+" ��");	
if ((int)ob->query("jinyong/book1",1)== sizeof(jm1)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 
  

write(HIW"��"HIM"ѩ ɽ �ɺ�"HIW"��"HIY+jm2[ob->query("jinyong/book2")]+" ��");	
if ((int)ob->query("jinyong/book2",1)== sizeof(jm2)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"�� ��   ��"HIW"��"HIY+jm3[ob->query("jinyong/book3")]+" ��");	
if ((int)ob->query("jinyong/book3",1)== sizeof(jm3)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"�� �� �˲�"HIW"��"HIY+jm4[ob->query("jinyong/book4")]+" ��");	
if ((int)ob->query("jinyong/book4",1)== sizeof(jm4)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"���Ӣ�۴�"HIW"��"HIY+jm5[ob->query("jinyong/book5")]+" ��");	
if ((int)ob->query("jinyong/book5",1)== sizeof(jm5)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"����Х����"HIW"��"HIY+jm6[ob->query("jinyong/book6")]+" ��");	
if ((int)ob->query("jinyong/book6",1)== sizeof(jm6)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"¹  ��  ��"HIW"��"HIY+jm7[ob->query("jinyong/book7")]+" ��");	
if ((int)ob->query("jinyong/book7",1)== sizeof(jm7)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"Ц �� ����"HIW"��"HIY+jm8[ob->query("jinyong/book8")]+" ��");	
if ((int)ob->query("jinyong/book8",1)== sizeof(jm8)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"�齣����¼"HIW"��"HIY+jm9[ob->query("jinyong/book9")]+" ��");	
if ((int)ob->query("jinyong/book9",1)== sizeof(jm9)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"�� ���� ��"HIW"��"HIY+jm10[ob->query("jinyong/book10")]+" ��");	
if ((int)ob->query("jinyong/book10",1)== sizeof(jm10)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"��  ��  ��"HIW"��"HIY+jm11[ob->query("jinyong/book11")]+" ��");	
if ((int)ob->query("jinyong/book11",1)== sizeof(jm11)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"����������"HIW"��"HIY+jm12[ob->query("jinyong/book12")]+" ��");	
if ((int)ob->query("jinyong/book12",1)== sizeof(jm12)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"��  Ѫ  ��"HIW"��"HIY+jm13[ob->query("jinyong/book13")]+" ��");	
if ((int)ob->query("jinyong/book13",1)== sizeof(jm13)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIW"��"HIM"ԧ  ��  ��"HIW"��"HIY+jm14[ob->query("jinyong/book14")]+" ��");	
if ((int)ob->query("jinyong/book14",1)== sizeof(jm14)-1) 
write(HIG"����ɡ�\n");
 else
write(HIR"δ��ɡ�\n"); 

write(HIC"��"+HIY"�����������������������߽��Խ����������������"HIC"��\n"NOR);
	return 1;
        
}



int help(object me)
{
	write(@HELP
ָ���ʽ : questlist
           questlist <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ����������߽��������
�������ϵ��趨����� 'help questlist'��

see also : hp
HELP
    );
    return 1;
}
