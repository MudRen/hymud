//���񽣷�
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$Nһ�� ��������⡹",
        "ֻ��$N��������Ծ��,һ�� ������չ�᡹",
        "$Nʹ�� ��ӥ�����ա�",
        "$NƮȻ������һʽ ��������졹",
        "$N��������Ծ��,�������ּ�ת��һ�� �����񳯷",
        "$N����������һ�� ��ԧ��Ϸˮ��",
});

string* skill_tail =({
        "������$w��������,�ó�һ���׹�ֱ��$n��$l",
        "��$w����һ������,������������,ֱȡ$n��$l",
        "���������ּ�ת,�ε�$nͷ��Ŀѣ",
        "������$w��ò����س�����$n��Χ.",
        "��������ˮ������$nȫ��",
        "������$w���������֮��һ������Ⱥ�ۡ�",
});

mapping *action = ({
   ([  "action": "$Nһ��"+BLINK""+HIC"������չ�᡹"NOR",����$w��������,�ó�һ���׹�ֱ��$n��$l",
     "dodge":     10,
     "damage":     340,
     "damage_type":   "����"
   ]),
([ "action":"ֻ��$N��������Ծ��,һ��"+BLINK""+HIM"��ӥ�����ա�"NOR",������ˮ,һйǧ��,����$nȫ��",
     "dodge":     30,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"$NƮȻ����,����$w΢΢���,ɲ�Ǽ������Ž�,�ִ�$wȫ��Ÿ���λ,����һ��"+BLINK""+HIG"��������졹"NOR".\n",
     "dodge":     10,
     "damage": 335,
     "damage_type":   "����"
   ]),
   ([ "action":
"$N��ָ�ᵯ����,$w����һ������,������������,ֱȡ$n��$l,ȴ��һ��"+BLINK""+HIY"���ۼ�������"NOR".\n",
     "dodge":     30,
     "damage": 345,
     "damage_type":   "����"
   ]),
  ([  "action":      
 "$Nһ��"+BLINK""+HIB"�������ƶˡ�"NOR",���⻮������ԲȦ,�������,�������.\n",
     "dodge":     30,
     "damage": 340,
     "damage_type":   "����"
   ]),
  ([   "action": 
"$N����$w������ҵػ���һ����,ƽƽ����$n��$l,���ǰ��񽣷�֮"+BLINK""+HIW"��������⡹"NOR".\n",
     "dodge":     30,
     "damage":     350,
     "damage_type":   "����"
   ]),
  ([ "action": 
"$Nһʽ"+BLINK""+RED"���ž���Ѫ��"NOR",����$w��ת,��Ϊһ��Ѫ��,��ò����س�����$n��Χ.\n",
     "dodge":     30,
     "damage":     330,
     "damage_type":   "����"
   ]),
   ([ "action": 
"$N��������Ծ��,�������ּ�ת,�ε�$nͷ��Ŀѣ,����һ��"+BLINK""+HIR"�����ﱨ����"NOR".\n",
     "dodge":     30,
     "damage":     335,
     "damage_type":   "����"
   ]),
   ([ "action": "$Nһ����Х,���ΰεض���,����һ��"+BLINK""+HIB"����Ӱ������"NOR",����ֱ��$nͷ��",
      "dodge": 30,
      "damage": 450,
      "damage_type": "����"
]),
 ([ "action":
 "$N����$wһ��,����ɢ��ʮ�����ɫϼ��,��ס��$nȫ��,����һ��"+BLINK""+HIG"����ȸ������"NOR"",
     "dodge": 30,
     "damage": 435,
    "damage_type": "����"
]),
([ "action": "$Nһ��"+BLINK""+HIC"������ѧ�ࡹ"NOR",����$w��һ�����벻���ķ�λֱ��$n������",
    "dodge": 30,
    "damage": 445,
    "damage_type": "����"
]),
(["action":
 "$N����$wһ��,���طֳ�һ����Ӱ,��������ͬʱ����$n���,����"+BLINK""+HIM"��ԧ��Ϸˮ��"NOR"",
  "dodge": 30,
  "damage": 450,
  "damage_type": "����"
]),
});

int valid_learn(object me)
{
   object ob;

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취����\n");


   if( (string)me->query_skill_mapped("force")!= "honghua-shengong")
     return notify_fail("���񽣷�������Ϻ컨�񹦲�����.\n");


if ((int)me->query_skill("youlong-shenfa", 1) < 200)
                 return notify_fail("��������� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("benlei-shou", 1) < 200)
                 return notify_fail("��ı����� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("heisha-zhang", 1) < 200)
                 return notify_fail("��ĺ�ɰ�� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("qiuge-dao", 1) < 200)
                 return notify_fail("�������ߵ� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("zhuihun-jian", 1) < 200)
                 return notify_fail("���׷�������  ��򲻹����޷�ѧ��\n");                                             
if ((int)me->query_skill("luohua-jian", 1) < 200)
                 return notify_fail("����仨ʮ����  ��򲻹����޷�ѧ��\n");                                             



   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
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
         
         level   = (int) me->query_skill("bainiao-jian",1);
         lvl = (int)me->query_skill("bainiao-jian", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        
              if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취����\n");

   if( (string)me->query_skill_mapped("force")!= "honghua-shengong")
     return notify_fail("���񽣷�������Ϻ컨�񹦲�����.\n");


if ((int)me->query_skill("youlong-shenfa", 1) < 200)
                 return notify_fail("��������� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("benlei-shou", 1) < 200)
                 return notify_fail("��ı����� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("heisha-zhang", 1) < 200)
                 return notify_fail("��ĺ�ɰ�� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("qiuge-dao", 1) < 200)
                 return notify_fail("�������ߵ� ��򲻹����޷�ѧ��\n");
if ((int)me->query_skill("zhuihun-jian", 1) < 200)
                 return notify_fail("���׷�������  ��򲻹����޷�ѧ��\n");                                             
if ((int)me->query_skill("luohua-jian", 1) < 200)
                 return notify_fail("����仨ʮ����  ��򲻹����޷�ѧ��\n");             
   if( (int)me->query("qi") < 30
   ||   (int)me->query("neili") < 33 )
    return notify_fail("���������������,û�а취��ϰ���񽣷�.\n");
   me->receive_damage("qi", 30);
   me->add("neili", -13);
//  write("�㰴����ѧ����һ����񽣷�.\n");
   return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bainiao-jian/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        string msg;
        int ap,dp;
        int i;
        object target;


       level   = (int) me->query_skill("bainiao-jian",1);
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("honghua-shengong",1);

damage= (int) me->query("neili",1)/20;
damage2=random(me->query_skill("bainiao-jian",1))+50;
//        target = me->select_opponent();
if (damage > 1600) damage=1600;

        weapon = me->query_temp("weapon");
if (random (6)==0 && me->query_skill_mapped("force") == "honghua-shengong")
{
        if( userp(victim) && (random(10)==1 || random(level) > 150))
        {
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return RED "��һ��׷��!!����$N�������ˣ�����$w��ָ������$n������·!\n" NOR;
        }
if (damage_bonus < 60) damage_bonus=60;
        if( random(8)==1 || random(level) > 50 ||  (int)me->query_temp("kongming")  )
        {

        victim->receive_wound("qi", damage_bonus );     
        return RED "�������׶�!!����$N�����������������Ƽ��������ϼ�⣬��$n������ס!!\n" NOR;
  }
}
else
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "honghua-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("bainiao-jian",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+30);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}



}