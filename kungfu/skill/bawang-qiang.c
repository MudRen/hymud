// bawang-qiang.c ������ǹ����
//modified by bird at /07/13/2004
//Ϊ���ð���ǹ��ת������ѧ


inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N���㾫��ʹ��һ�� ӭ�������� ",
        "$N����һ����һʽ ����Ѱ��",
        "$N�������ߣ����Ǻ���һ��ת����æ��ʹ��һ�� �ٻ�������",
        "$Nһ���粽��ʹһ�� ���߳���",
                "$Nһ��ǹ��,ʹ��һ�� ����ǹ",
});
string* skill_tail =({
        "������$w��������$n���ţ���ɤ��ǰ�ġ�",
        "������$wһͦ����$n$l��",
        "������$w�������ٴ���$n��$l��",
        "������$w��ɣ�������㺮�⡣",
        "������$w����һ�����������¶��ϼ���$n$l",
});

mapping *action = ({
        ([      "action":
"$Nʹһ��"+BLINK""+HIW"��ӭ����������"NOR"������$w��������$n���ţ���ɤ��ǰ��",
                "damage":               350,
                "dodge":                5,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���㾫�񣬶���$w��һ��"+BLINK""+HIG"������Ѱ�ߡ�"NOR"����$n$l",
                "damage":               340,
                "dodge":                15,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ���粽��ʹһ��"+BLINK""+HIC"����ɽ��ˮ��"NOR"������$w�������ٴ���$n��$l",
                "damage":               345,
                "dodge":                20,
                "parry":                10,
                "damage_type":  "����"
        ]),
         ([      "action":
"$Nһ��ǹ�ѣ�ž����һ������"+BLINK""+HIM"�����ǹ����"NOR"���������ң�����ʵʵ����$nȫ��Ҫ��",
                "damage":               345,
                "dodge":                10,
                "parry":                15,
                "damage_type":  "����"
        ]),
         ([      "action":
"ֻ��$Nһ��б�磬ʹ��"+BLINK""+HIR"���ٻ������ơ�"NOR"������$w����һ�����������¶��ϼ���$n$l",
                "damage":              355,
                "dodge":                20,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����һ��������$w�����벻���ĽǶȴ���$n��$l��\n��һ��"+BLINK""+HIB"�����߳�����"NOR"�������磬�����ޱ�",
                "damage":               335,
                "dodge":                5,
                "parry":                25,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"+BLINK""+MAG"������Ͷ���ơ�"NOR"������б�ɣ��Ӳ���ͻ��һǹ������$n$l",
                "damage":               440,
                "dodge":                15,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������ߣ����Ǻ���һ��ת����æ��ʹ��һ��"+BLINK""+RED"������ǹ��"NOR"��$wһͦ����$n$l",
                "damage":               450,
                "dodge":                10,
                "parry":                20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

       if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("���̫���񹦻��̫ǳ��\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("����ð���ǹ�����֮����һʱ��������ᡣ\n");

        if(me->query_skill("sumi-jian", 1) < 150)
                return notify_fail("������޽���Ϊ�������޷�������\n");

        if(me->query_skill("huanhe-dao", 1) < 150)
                return notify_fail("����Ӻյ���Ϊ�������޷�������\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("���������һ��ǹ������ǹ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="club") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("bawang-qiang",1);
         lvl = (int)me->query_skill("bawang-qiang", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object

 weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("club",1);
        level2= (int) me->query_skill("taixuan-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("bawang-qiang",1))+50;
if (damage > 1600) damage=1600;
 if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "taixuan-gong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("bawang-qiang",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
else 
        if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>190 
        ) {
        victim->receive_wound("qi", (random(level)+80));
return random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                   "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                   HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                   "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
}


}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("�����������������\n");

    if( (string)me->query_skill_mapped("force")!= "taixuan-gong")
     return notify_fail("����̫���񹦲���ѧ��\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("����ð���ǹ�����֮����һʱ��������ᡣ\n");

        if(me->query_skill("sumi-jian", 1) < 150)
                return notify_fail("������޽���Ϊ�������޷�������\n");

        if(me->query_skill("huanhe-dao", 1) < 150)
                return notify_fail("����Ӻյ���Ϊ�������޷�������\n");
   me->receive_damage("qi", 32);
   me->add("neili", -6);

   return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bawang-qiang/" + action;
}