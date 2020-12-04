//�Ϻ����� �Ͷ���� buddha-stick
//by junhyun@sk_sjsh
//2002.5.11

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        HIR"$N������ţ�ʹ��һ�� �ҷ�ȱ�"NOR,
        HIR"$N�����ķ���ƽƽһ�� ��շ�ħ"NOR,
        HIR"$N����һת����Ȼһ�� ��������"NOR,
        HIR"$N���˷�����ͻȻһ�� �����ǻ�"NOR,
        HIR"$N�Թ�����������һ�� ��ͷ�ǰ�"NOR,
        HIR"$N�Ų�������һ������ �Ⱥ��ն�"NOR,

});

string* skill_tail =({
        RED"������$w�ƿ�֮������������$n�ҽ�������"NOR,
        RED"������$n������ԼԼ��������������"NOR,
        RED"��Խ��$n��࣬����$w�籩������$n��"NOR,
        RED"��Ӳ������$n��໬��������$wɨ��$n��$l��"NOR,
        RED"����������$n�����Ѩ�����$n��æ���ҡ�"NOR,
        RED"������$w��������Ӱ�ӣ��Ӱ���л���$n��"NOR,
});

mapping *action = ({
        ([      "name":                 "�ҷ�ȱ�",
                "action":
"$N������ţ�ʹ��һ��"+BLINK""+HIY"���ҷ�ȱ���"NOR+"������$w�ƿ�֮������������$n�ҽ�����",
                "dodge":                45,
     "parry":   10,
                "damage":               365,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��շ�ħ",
                "action":
"$N�����ķ���ƽƽһ��"+BLINK""+HIY"����շ�ħ��"NOR+"������$n������ԼԼ��������������",

                "dodge":                110,
     "parry":     10,
                "damage":               385,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$N����һת����Ȼһ��"+BLINK""+HIY"���������꡹"NOR+"��Խ��$n��࣬����$w�籩������$n",
                "dodge":                110,
     "parry":   20,
                "damage":              375,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����ǻ�",
                "action":
"$N���˷�����ͻȻһ��"+BLINK""+HIW"�������ǻ���"NOR+"��Ӳ������$n��໬��������$wɨ��$n��$l",
                "dodge":               110,
     "parry":   15,
                "damage":               335,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ͷ�ǰ�",
                "action":
"$N�Թ�����������һ��"+BLINK""+HIB"����ͷ�ǰ���"NOR+"����������$n�����Ѩ�����$n��æ����",
                "dodge":                115,
     "parry":     15,
                "damage":               360,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�Ⱥ��ն�",
                "action":
"$N�Ų�������һ������"+BLINK""+HIB"���Ⱥ��նɡ�"NOR+"������$w��������Ӱ�ӣ��Ӱ���л���$n",
                "dodge":                115,
     "parry":   10,
                "damage":               350,
                "damage_type":  "����"
        ]),   
       ([      "name":                 "�������޸�",
                "action":
"$N�������ˣ�����$wӭ��һ��������$n��ͷ�������ҽ�����",
                "dodge":                115,
		"parry":	10,
                "damage":               535,
                "damage_type":  "����"
        ]),
        ([      "name":                 "̸Ц�����",
                "action":
"$N���쳤Ц����Ҳ������һ�С�̸Ц�������������һ����$n��ͷ����",
                "dodge":                10,
		"parry":		10,
                "damage":               525,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�¶�������",
                "action":
"$Nһ��������Խ��$nͷ��������$w�ո���Բ��������һ������$n$l",
                "dodge":                110,
		"parry":	20,
                "damage":               535,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����Ͼ�¯",
                "action":
"$Nһ���޺ȣ���һ���������Ͼ�¯����\n����$nһ�֮�䣬$N����$w���Ǻ�Х������ɨ��$n��$l",
                "dodge":               110,
		"parry":	15,
                "damage":               525,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������һ�",
                "action":
"$Nʹ����������һ᡹���Ų����ԣ���һ������һ����\n���$n��æ���ң��мܲ���",
                "dodge":                115,
		"parry":		5,
                "damage":               530,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "����׹Ǿ�",
                "action":
"$N����������ƣ�����$wת����糵һ�㣬\nһ�������Ӱ���л���$n����",
                "dodge":                115,
		"parry":	10,
                "damage":               520,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "ǧ��������",
                "action":
"$N����$wһ������Ϊǧ���ϼ�⣬\n����$nĿѣ��ҡ֮ʱ����һ����ϼ����գ�\n$w�ѵ���$n��$l����һ���и����ã�������ǧ�������",
                "dodge":                110,
		"parry":	20,
                "damage":               500,
                "damage_type":  "����"
        ]),
	([	"name":			"Ǭ��һ��",
		"action":	"$N������$wӭ��һ�ӣ��ó���ǧ��Ӱ�������������߾ٹ�����
$w��׼$n�����ž�������ȥ����һ��Ҫ�Ǵ��У����������޽���Ҳ����һ��",
		"parry":	30,
		"dodge":	50,
		"damage":	600,
		"damage_type":  "����"
	]),
});


int valid_learn(object me)
{
        object ob;
     if( (string)me->query_skill_mapped("force")!= "zhanzhuang-gong")
     return notify_fail("�Ͷ����������ƽ����վ׮����������\n");

if ((int)me->query_skill("zhanzhuang-gong", 1) < 200)
		 return notify_fail("���վ׮����򲻹����޷�ѧ�������֡�\n");
	if ((me->query_skill("boluomi-hand", 1) < 200) )
		return notify_fail("��Ĳ������ֻ�򲻹���\n");
	if ((me->query_skill("jingang-strike", 1) < 200) )
		return notify_fail("��Ĵ������ƻ�򲻹���\n");

        if( (int)me->query("max_neili") < 550 )
                return notify_fail("�������������û�а취���Ͷ������
����Щ���������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("���������һ�����Ӳ�����������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="club"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("buddha-club",1);
         lvl = (int)me->query_skill("buddha-club", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 50
        ||      (int)me->query("neili") < 50 )
                return notify_fail("�����������������û�а취��ϰ�Ͷ������\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
//        write("��Ĭ���ţ���ϰ��һ���Ͷ������\n");
        return 1;
}


string perform_action_file(string action)
{
	return __DIR__"buddha-club/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("zhanzhuang-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("buddha-club",1))+50;
if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "zhanzhuang-gong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("buddha-club",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}


