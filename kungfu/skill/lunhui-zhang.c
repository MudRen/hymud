
//���ֻ��ȡ�lunhui-zhang.c
//2001 by lestat

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        HIW"$N������ţ���ɫׯ�ϣ�һ�� ��Ӧ��ˬ"NOR,
        HIW"$N�Ϻ�һ����ʹ��һʽ ���޽���"NOR,
        HIW"$N����һ�� ��ͷ�ǰ�"NOR,
        HIW"$N����һ�ݣ�һʽ �ڽ�����"NOR,
        HIW"$N��������һ�� �ٶ��ֻ�"NOR,
        HIW"$N��¶ϼ�⣬ʹ��һ�� �ȹ��ն�"NOR,
});
string* skill_tail =({
        WHT"������$w����ֱ�룬�ɴ�$n$l��"NOR,
        WHT"������$w�������ֵ�����$n��"NOR,
        WHT"��ֱ��$n��"NOR,
        WHT"������$w����ǧ�ֱ��$w����"NOR,
        WHT"������һ�ݣ�����$wֱ��$n��$l��"NOR,
        WHT"��$n��ʱ��æ���ң�$w��Ҫ�䵽$l�ϡ�"NOR,
});

mapping *action = ({
        ([      "name":                 "��Ӧ��ˬ",
                "action":
"$N������ţ���ɫׯ�ϣ�һ��"+BLINK""+HIR"����Ӧ��ˬ��"NOR"����$w����ֱ�룬�ɴ�$n$l",
     "dodge":     30,
     "parry":                30,
     "damage":     300,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���޽���",
                "action":
"$N����$wһ����ʹ��"+BLINK""+HIB"�����޽�����"NOR"������һ����Ӱ����ԼԼ���������޵���$nѹ��",
     "dodge":     30,
     "parry":                30,
     "damage":     200,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ͷ�ǰ�",
                "action":
"ֻ��$N����$w���ᣬ���ص��������"+BLINK""+HIM"����ͷ�ǰ���"NOR"����Ʈ�ݣ�\n$n�ۼ��ȷ�Ϯ��������֪����Ǻ�",
     "dodge":     30,
     "parry":                30,
     "damage":     300,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ڽ�����",
                "action":
"$N���һ��������$w��$n��ͷ���䣬����δ�����ѽ�$n������·��������һ��"+BLINK""+HIC"���ڽ����ӡ�"NOR"",
     "dodge":     30,
     "parry":                30,
     "damage":     500,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�����ֻ�",
                "action":
"$N����$w������һ�ݣ�һ��"+BLINK""+HIW"�������ֻ֡�"NOR"��$n���벻���ĵط��̳���$n��ʱ�����޴룬�Ǳ����",
     "dodge":     30,
     "parry":                30,
     "damage":     500,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�ٶ��ֻ�",
                "action":
"$N����ͻ��ɷ������������$w������$n$l���䣬����"+BLINK""+RED"���ٶ��ֻء�"NOR"�����ֿ��ֺ�",
     "dodge":     30,
     "parry":                30,
     "damage":     500,
                "damage_type":  "����"
        ]), 
        ([      "name":   "�ɽ�",
    "action" : HIW"\n$NĬ����ţ����е�$w��һ�㵭���İ���ֱֱ����$n����ǰ�����һ���������ɽ١���"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "����"
	]),
	([      "name":   "����",
    "action" : HIW"\n$N����$wһ�񣬰�ɫ������Ȼ����ȫ������֮��������ڶ�ʽ�����ѡ���Ȼ�ĳ���"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "����"
	]),
	([      "name":   "�ɶ�",
    "action" : HIW"\n$N������$w������˷�ľ�������ӿ������\n���ɶ�һʽ֮�����Լ���Ҷ���Ҳ������ʨ�Ӻ𡱣�"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "����"
	]),
	([      "name":   "�ȹ��ն�",
    "action" : HIC"\n$N������������ͷ�ǰ����������߳߾���ӿ����\n�����ӷ������������Ϲ����ջ������ȹ��նɡ����ȶ�����"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "����"
	]),  
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������������û�а취ѧ�ֻ��ȣ�����������������ɡ�\n");

     if( (string)me->query_skill_mapped("force")!= "zhanzhuang-gong")
     return notify_fail("������ƽ����վ׮����������\n");

if ((int)me->query_skill("zhanzhuang-gong", 1) < 200)
		 return notify_fail("���վ׮����򲻹����޷�ѧ�������֡�\n");
	if ((me->query_skill("wuxiang-finger", 1) < 200) )
		return notify_fail("��������ָ��򲻹���\n");
	if ((me->query_skill("ruying-leg", 1) < 200) )
		return notify_fail("�����Ӱ�����Ȼ�򲻹���\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("���������һ�����Ȳ���ѧ�ֻ��ȡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("lunhui-zhang",1);
         lvl = (int)me->query_skill("lunhui-zhang", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 35 )
                return
notify_fail("�����������������û�а취��ϰ�ֻ��ȡ�\n");
        me->receive_damage("qi", 20);
        me->add("neili", -25);
        //write("�㰴����ѧ����һ���ֻ��ȡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"lunhui-zhang/" + action;
}






mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("zhanzhuang-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("lunhui-zhang",1))+50;
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
      if( random(me->query_skill("lunhui-zhang",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

