//�粨ʮ���� fengbo-cha.c

/*
�粨ʮ����    dodge  0    parry  -5    damage  25
�������ر�֮���������������Ϊ�еȡ�
*/

//pickle, not changed yet, please try to be compatible. 

// �����ѳ˻ƺ�ȥ���˵ؿ���ƺ�¥
// �ƺ�һȥ������������ǧ�ؿ�����
// �紨��������������������������
// ��ĺ��غδ�ȥ���̲�����ʹ�˳�

// ���������ˣ�����������
// ����һҶ�ۣ���û�粨��

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$Nһ�� ������Ұ",
        "$N˫��һ�𣬷���һ�� ��������",
        "$Nһ������ʹ��һ�� �����ĺ�",
        "$Nһ��������Х��ʹ�� ��Ծ����",
        "$Nʹ�� ˫��Ϸ��",
        "$N��$n����֮�ʣ�һ�� �����»�",
});

string* skill_tail =({
        "������$w�д��ż������������ͷ�����ؾ���$n���˹�ȥ��",
        "����$n��ͷ�����Ĵ��˹�ȥ��",
        "������$wбб�ش���$n��$l��",
        "������$wһ���ɨ��ֱ��$n��",
        "��ֱ���$n�ڽں��ˡ�",
        "������$wƮ�첻����$n��ʱ��æ���ң�",
});

mapping *action = ({
        ([      "name":                 "�������ѳ˻ƺ�ȥ��",
                "action":
"$N�ƺ���Ѱ��Щʲô������$w����ǰ��̽�����档\n"
"�����ָ֮��������$n��$l��ԭ����"BLINK+HIY"�������ѳ˻ƺ�ȥ��"NOR,
                "dodge":                10,
		"parry":		10,
                "damage":               345,
                "damage_type":  	"����",
		"parry_msg":
"$n�Ӷ�$W������ǰ���˸���Բ�����õ���$N�Ĺ��ơ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���˵ؿ���ƺ�¥��",
                "action":
"$N���β���������$w��һ��"BLINK+HIR"���˵ؿ���ƺ�¥��"NOR"��\n"
"����$n��$l�������ƺ���Ϊ������Ӳ�������������ˮ��������������",
                "dodge":                10,
		"parry":		10,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$n˿����Ϊ���������赭д�ػӲ�һ�̣��Ƶ�$N�����Է���\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���ƺ�һȥ��������",
                "action":
"$N�����������䣬�������ߣ�$næ��׷������������ʱ��\n"
"$N�ڿ���ͻȻ����һʽ"BLINK+HIC"���ƺ�һȥ��������"NOR"ֱָ$n��$l",
                "dodge":                10,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$nһ������$W����$N������һ���������ݿ����ɡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "������ǧ�ؿ����ơ�",
                "action":
"$Nһ����Х�����������Ӱ�����������ƣ��ŵ�$n�ۻ�����\n"
"����"BLINK+HIW"������ǧ�ؿ����ơ�"NOR"��Ϊ���񣬹�Ȼ��һ��ǰ�������ˣ��󲻼����ߵ�����",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$n��$W��÷��겻͸��$N����֮��ֻ�û��С�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���紨������������",
                "action":
"$N����$wһ������һ��"BLINK+HIM"���紨������������"NOR"��Ѹ���ޱȵ���$n�������Ҹ���һ��",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$n������$W���˸�Բ���������������������ˡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���������������ޡ�",
                "action":
"$Nʩ��һ��"BLINK+HIG"���������������ޡ�"NOR"��ֻ��$w�������޵�һ̽��\n"
"��ȥ���ƺ�����$n������紦������֪���ģ�ת˲�����ѵ���$l",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$n�������ؾٲ�һ�����ƺ��������ġ����ȵ����˱����ཻʱ��\n"
"$n$W�Ϻ�Ȼ����һ����������$N���˿�ȥ��\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "����ĺ��غδ�ȥ��",
                "action":
"$N��Цһ��������$w�������ذ�Ӱ������һ����Ũ������$n��\n"
"$n����͸����"BLINK+HIB"����ĺ��غδ�ȥ��"NOR"����·��ʵ�ڲ�֪����м�",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$n���ܲ��ã�ͦ$W����ǰ�մ��������档���п���ƽƽ���棬ȴ��ƽ���н�$N�Ĺ��Ʒ����ˡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���̲�����ʹ�˳",
                "action":
"$n�մ���һ����ȴ��$N����һ�����Ѿ���Ӱȫ�ޡ�$n��δ���ü�ת��\n"
"$N��$w�ѵ������ˡ�����"BLINK+YEL"���̲�����ʹ�˳"NOR"��Ȼ����ޱȣ����˷���ʤ��",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"����",
		"parry_msg":
"$n�ۼ�$N����������æ��һ�С��̲�����ʹ�˳����ת��Ȧ����$N��������һ�ߡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "�����������ˡ�",
                "action":
"$Nŭ߳һ��������$w����ޱȵ���$n��ǰ�����ػ������߻���\n"
"����"BLINK+WHT"�����������ˡ�"NOR"����޷���$nʵ�ڲ�֪�������飬������ʵ",
                "dodge":                35,
		"parry":		35,
                "damage":               450,
                "damage_type":  	"����",
		"parry_msg":
"$n��������$W��ֻ����������һ�����죬���ڽ�$N���˻�ȥ��\n",
		"parry_power":		15,
        ]),
        ([      "name":                 "��������������",
                "action":
"$N����$w�������˸�ԲȦ����һ��"BLINK+CYN"��������������"NOR"������$n��$l��ȥ",
                "dodge":                35,
		"parry":		35,
                "damage":               455,
                "damage_type":  	"����",
		"parry_msg":
"$n�ƺ����г���ͦ����������ԲȦ��$N����͸$n�����ƣ���Ȼ����óȻ������\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "������һҶ�ۡ�",
                "action":
"$N����һ���������������$w�����³�֮�ƣ�һ��"BLINK+MAG"������һҶ�ۡ�"NOR"ֱ��$n��$l",
                "dodge":                10,
		"parry":		30,
                "damage":               455,
                "damage_type":  	"����",
		"parry_msg":
"$n��׼���ƣ���$W��$N�ı����͵㡣ֻ����������һ�����죬��Ȼ��$N�ı��е��˿�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "����û�粨�",
                "action":
"$NͻȻ��������һ�ԣ���������֮������������$n����ʱ��\n"
"$N��������������档����"BLINK+GRN"����û�粨�"NOR"�����ײ淨�ľ��裬\n"
"ʩ���������������Ī�⣬�����ƾ��ˣ�$n��ʱ��֪����",
                "dodge":                35,
		"parry":		35,
                "damage":               460,
                "damage_type":  	"����",
		"parry_msg":
"$n������������$W��������$N����Χκ����֮�ǹ�Ȼ��Ч����$N���˻�ȥ��\n",
		"parry_power":		15,
        ]),
});


int valid_learn(object me)
{
        object ob;


 if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("���뾸���񹦲���ѧ��\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("��ĸ���ն�޵�Ϊ�������޷�������\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("��ı̲�����Ϊ�������޷�������\n");


        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("���������һ������������ѧ�淨��\n");
        return 1;
}

int practice_skill(object me)
{
  if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("�����������������\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("���뾸���񹦲���ѧ��\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("��ĸ���ն�޵�Ϊ�������޷�������\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("��ı̲�����Ϊ�������޷�������\n");
		
   me->receive_damage("qi", 32);
   me->add("neili", -16);

   return 1;
}

int valid_enable(string usage)
{
        return usage=="club"||usage=="parry";
}


string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}
string perform_action_file(string action)
{
	return __DIR__"fengbo-cha/" + action;
}


mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("fengbo-cha",1);
         lvl = (int)me->query_skill("fengbo-cha", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("club",1);
        level2= (int) me->query_skill("jinghai-force",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("fengbo-cha",1))+50;
if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "jinghai-force")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("fengbo-cha",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}


}