//wuyue-club ������ǹ
/*
������ǹ    dodge  0    parry  -10    damage  25
����������Ʒɻ��ĳ���ǹ�����а��۲���֮��
���������мܣ�����Ҳ����С��
*/

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$Nʹ��һ�� ��̩ɽѹ����",
        "$N���㾫�񣬺�һ�� ���������ơ�",
        "$Nһ������ʹ���� �����Ϫ�ơ�",
        "$N��̬���У�һ�� ���������ڡ�",
        "$N��ǹ��һ��ͻȻһ�� ��̫�Ҳη�",
        "$Nһ�����������ǹ��������һ�� ���������ա�",
});

string* skill_tail =({
        "������$w��$n��ͷ����ֱɨ��������",
        "������$w�������޵ش���$n$l��",
        "��$N����$w�������ٴ���$n��$l��",
        "������$w����ػ���$n��$l��",
        "��ǹǹ����$nҪ����",
        "������$w����һ������ֱ��$n$l��",
});

mapping *action = ({
        ([      "action":
"$Nʹһ��"+BLINK""+HIM"��̩ɽѹ����"NOR"������$w��$n��ͷ����ֱɨ������",
                "damage":               340,
                "dodge":                15,
                "parry":                15,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���㾫�񣬶���$w��һ��"+BLINK""+HIC"���������ơ�"NOR"����$n",
                "damage":               340,
                "dodge":                15,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$w�������ٴ���$n��$l����һ��"+BLINK""+HIG"�����Ϫ�ơ�"NOR"",
                "damage":               345,
                "dodge":                10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N һ�����������ǹ��������һ��"+BLINK""+HIB"���������ڡ�"NOR"��ǹǹ����$nҪ��",
                "damage":               350,
                "dodge":                10,
                "parry":                15,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$Nһ������ʹ��"+BLINK""+HIY"��̫�Ҳη�"NOR"������$w����һ������ֱ��$n$l",
                "damage":               340,
                "dodge":                10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N�ڿշ�������ǹ��һ��$wֻ��$n$l������һ��"+BLINK""+HIW"���������ա�"NOR"",
                "damage":               340,
                "dodge":                5,
                "parry":                25,
                "damage_type":  "����"
        ]),
});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("�������������û�а취��������ǹ��\n");

if( (string)me->query_skill_mapped("force")!= "hanbing-zhenqi")
     return notify_fail("���뺮����������ѧ��\n");

if ((int)me->query_skill("hanbing-zhenqi", 1) < 200)
                 return notify_fail("��ĺ���������򲻹����޷�ѧ��\n");

        if( me->query_skill("zhongyuefeng", 1) < 200)
                return notify_fail("������������Ϊ������\n");

        if( me->query_skill("songshan-jian", 1) < 200)
                return notify_fail("�����ɽ��彣��Ϊ������\n");

        if( me->query_skill("songshan-sword", 1) < 200)
                return notify_fail("�����ɽ������Ϊ������\n");
                
        if( me->query_skill("fuguanglueying", 1) < 200)
                return notify_fail("��ĸ�����Ӱ��Ϊ������\n");

        if( me->query_skill("poyun-hand", 1) < 200)
                return notify_fail("�����������Ϊ������\n");
                
        if( me->query_skill("songyang-strike", 1) < 200)
                return notify_fail("��Ĵ���������Ϊ������\n");           

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
         
         level   = (int) me->query_skill("wuyue-spear",1);
         lvl = (int)me->query_skill("wuyue-spear", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        object ob;
      if( (string)me->query_skill_mapped("force")!= "hanbing-zhenqi")
     return notify_fail("���뺮����������ѧ��\n");

if ((int)me->query_skill("hanbing-zhenqi", 1) < 200)
                 return notify_fail("��ĺ���������򲻹����޷�ѧ��\n");
        if( me->query_skill("zhongyuefeng", 1) < 200)
                return notify_fail("������������Ϊ������\n");

        if( me->query_skill("songshan-jian", 1) < 200)
                return notify_fail("�����ɽ��彣��Ϊ������\n");

        if( me->query_skill("songshan-sword", 1) < 200)
                return notify_fail("�����ɽ������Ϊ������\n");
                
        if( me->query_skill("fuguanglueying", 1) < 200)
                return notify_fail("��ĸ�����Ӱ��Ϊ������\n");

        if( me->query_skill("poyun-hand", 1) < 200)
                return notify_fail("�����������Ϊ������\n");
                
        if( me->query_skill("songyang-strike", 1) < 200)
                return notify_fail("��Ĵ���������Ϊ������\n");           

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("���������һ��ǹ������ǹ����\n");
        if( (int)me->query("qi") < 30 
        ||    (int)me->query("neili") < 50  )
                return notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -35);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"wuyue-spear/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("hanbing-zhenqi",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("wuyue-spear",1))+50;
if( random(8)==0 
     && me->query_skill("wuyue-spear",1) > 290) {
        victim->start_busy(3);
        victim->apply_condition("cold_poison", victim->query_condition("cold_poison") + random(4));
        return HIC"$nͻȻȫ��һ�䣡�޷��������������˼��صĺ���������\n"NOR;
}

if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "hanbing-zhenqi")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("wuyue-spear",1)) > 50 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("wuyue-spear",1);
        level2= (int) me->query_skill("wuyue-spear",1);
        skill = me->query_skill("wuyue-spear", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("wuyue-spear",1);
damage2= (int) ob->query("neili",1)/10;
if (random(6)==0 && level2>=290 && (me->query_skill_mapped("club") == "wuyue-spear"))
{
j = -damage/2; 
if (damage2> 5000)      damage2=5000;
msg = HIC"$N"+HIC+"ʹ���������� !$nȫ��һ�䣡�޷������� \n" +NOR;
ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
  ob->start_busy(3);
           message_vision(msg, me, ob);
  
}


           return j;
}      