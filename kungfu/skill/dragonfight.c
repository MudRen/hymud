//�����β�����dragonfight.c
// cglaem...12/19/96.
//meipai skill(only dragon related NPCs can use it)

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



string* skill_head =({
        "$N�������ˣ�ʹ��һ�� �P���Ա�",
        "$N�������ܣ�һʽ �������",
        "$N����һ�ϣ�ʹ�� ��������",
        "$N����һЦ��һʽ ����ŭɱ",
        "$N����Ծ��ʹ�� ��������",
});
string* skill_tail =({
        "��˫�ƻ�Ϊһ���������$n��$l��",
        "��˫���������ȭӰ����$n��",
        "��˫�Ʋ�ƫһ�ᣬֱ����$n��$l��",
        "��˫����ɣ�������㺮�⡣",
        "��˫���Ҽ缱˦��󣬶��ػ���$n$l��",
});

mapping *action = ({
	([	"action":
"$N����Ծ��һ�С�����»𡹣�˫������ɽ����֮�ƻ���$n��$l",
		"dodge":		10,
		"parry":		10,
		"force":		150,
		"damage":		350,			
		"damage_type":		"����",
		"weapon" :		"˫��",
		"parry_msg":	"ֻ�������ϡ�һ������$N���ָ�",
	]),
	([	"action":
"$N���˷�����ͻȻ������ǰ����ָ�繳����׼$n��$lһ��ץ�˹�ȥ",
		"dodge":		10,
		"parry":		20,
		"force":		100,
		"damage":		350,	
		"damage_type":		"ץ��",
		"weapon":		"������ָ",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
	([	"action":
"ֻ��$Nһ����˫��������һ��ɨ��$n����һ�С�ſ��Ϸˮ�������Ƿ���ʤ��",
		"dodge":		10,
		"parry":		20,
		"force":		120,
		"damage":		350,				
		"damage_type":		"����",
		"weapon":		"˫��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
	([	"action":
"$N����������ʹ��һ�С���ͼ��Ѩ����Х���к�����ϣ���$nֱײ����",
		"dodge":		10,
		"parry":		10,
		"force":		100,
		"damage":		350,				
		"damage_type":		"ײ��",
		"weapon":		"ȫ��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
            ([	"action":
"ֻ��$Nһ������ڰ�գ�һ�С������ĺ�������δ��������ȫ��������$n",
		"dodge":		0,
		"parry":		20,
		"force":		150,
		"damage":		350,				
		"damage_type":		"����",
		"weapon":		"����",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
            ([	"action":
"$N����һ������$n�������һȭ�����С������������������ף������ޱ�",
		"dodge":		10,
		"parry":		30,
		"force":		180,
		"damage":		550,				
		"damage_type":		"����",
		"weapon":		"ȭͷ",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
});

int valid_learn(object me)
{
   if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("���뾸���񹦲���ѧ��\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("��ĸ���ն�޵�Ϊ�������޷�������\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("��ı̲�����Ϊ�������޷�������\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�����β���������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("dragonfight",1);
         lvl = (int)me->query_skill("dragonfight", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jinghai-force",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("dragonfight",1))+50;
if (damage > 1600) damage=1600;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "jinghai-force")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("dragonfight",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}


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

string perform_action_file(string action)
{
	return __DIR__"dragonfight/" + action;
}