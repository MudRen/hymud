// snowsword. �����ѩ�轣����

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$N�������ˣ�ʹ��һ�� �������ջ�Ӧפ",
        "$N�������ܣ�һʽ ��������ƽɳ",
        "$Nʹ�� �ܻ�Ⱦ����˪��",
        "$N��ȻһЦ��һʽ ˪ӡ������Ҳ��",
        "$Nһ����ת��ʹ�� �粨������֦��",
});
string* skill_tail =({
        "������$w��Ϊһ���������$n��$l��",
        "������$w��Ϊһ���������$n��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��ɣ�������㺮�⡣",
        "����ʱһ������Ʈ��$n",
});


mapping *action = ({
        ([      "action":
"$Nʹһ��"+BLINK""+HIB"���������ջ�Ӧפ��"NOR+"������$w��Ϊһ���������$n��$l",
                "dodge":                15,
                "parry":                10,
                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N������ת��ʹ��"+BLINK""+HIG"����������ƽɳ��"NOR+"��һ�������н���������ɨ��$n��$l",
                "dodge":                35,
                "parry":                15,
                "damage":               340,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һЦ��һʽ"+BLINK""+HIY"���ܻ�Ⱦ����˪�ۡ�"NOR+"���������Ӱ��$nֻ����������������Ϯ����ȴ��֪���������",
                "dodge":                10,
                "parry":                15,
                "damage":               335,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$w����һ����һʽ"+BLINK""+HIW"��˪ӡ������Ҳ�ա�"NOR+"�ó�һ�麮������$n��$nֻ����������������ס��",
                "dodge":                30,
                "parry":                35,
                "damage":               335,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$w��һ����ֻ�������㣬Ʈ��������\n��һ��"+BLINK""+HIR"����ɸ���������硹"NOR+"ֻ����$n�ۻ����ң����ﻹ���м�",
                "dodge":                20,
                "parry":                20,
                "damage":               335,
                "damage_type":  "����"
        ]),
        ([      "action":
"$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n��󣬽���ֱָ$n�ĺ��أ�����һʽ"+BLINK""+MAG"�����㸡���»ƻ衹"NOR+"",  
                "dodge":                35,
                "parry":                35,
                "damage":               340, 
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������ܣ�һʽ"+BLINK""+HIC"���粨������֦����"NOR+"����ɫ��ţ����ƴ�����һ��������ˮ�����������Ľ���ֱָ$n��������",
                "dodge":                35,
                "parry":                310,
                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$N����$w����һ����һʽ��˪ӡ������Ҳ�ա��ó�һ�麮������$n��$nֻ����������������ס��"NOR,
                "dodge":                30,
                "parry":                35,
                "damage":               335,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$N����$w��һ����ֻ�������㣬Ʈ������������$n��$l"NOR,
                "dodge":                30,
                "parry":                35,
                "damage":               435,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n��󣬽���ֱָ$n�ĺ���"NOR,
                "dodge":                30,
                "parry":                35,
                "damage":               335,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$Nһʽ���粨������֦��������ɫ��ţ����ƴ�����һ�����������ˮ����������"NOR,  
                "dodge":                35,
                "parry":                35,
                "damage":               450, 
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;


    
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취�����ѩ�轣����\n");

//        if( (string)me->query_skill_mapped("force")!= "moonforce")
//                return notify_fail("���ѩ�轣�������������ɽ��Ů���Բ���ķ���������\n");

        if ((int)me->query_skill("bitao-shengong", 1) < 220)
                return notify_fail("��ġ������ķ������̫ǳ��\n");

        if ((int)me->query_skill("zhuyue-whip", 1) < 120)
                return notify_fail("��ġ����±޷������̫ǳ��\n");
                

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("snowsword",1);
         lvl = (int)me->query_skill("snowsword", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100
        ||      (int)me->query("neili") < 30 )
                return notify_fail("�����������������û�а취��ϰ���ѩ�轣����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -3);
//        write("�㰴����ѧ����һ����ѩ�轣����\n");
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"snowsword/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("bitao-shengong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("snowsword",1))+50;
if (damage > 1600) damage=1600;
if (me->is_busy()) return;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "bitao-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
		return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;

}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("snowsword",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}
