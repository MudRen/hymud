// wushen-jian.c ��ɽ����
// �ɺ�ɽ���ϸǽ�����ܽ�ؽ�����ʯ�޽�����ף�ڽ�����������
// ����һ������B+����е��ѧ��

#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 
mapping *action = ({
([      "action" : "$Nһ�С���ҶƮƮ����$w�ƻ�������������������˷�������$n",
        "force"  : 110,
        "attack" : 35,
        "dodge"  : 20,
        "parry"  : 25,
        "damage" : 143,
        "lvl"    : 0,
        "skill_name" : "��ҶƮƮ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ˮ�и�Ƽ����������ָ������$n��$n�������ֱܷ�$w����·",
        "force"  : 155,
        "attack" : 43,
        "dodge"  : 25,
        "parry"  : 14,
        "damage" : 51,
        "lvl"    : 10,
        "skill_name" : "�и�Ƽ",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ����ƮȻֱȥ����$w��һ������������һ�ɺ�������$n��$l",
        "force"  : 178,
        "attack" : 48,
        "dodge"  : 28,
        "parry"  : 24,
        "damage" : 162,
        "lvl"    : 20,
        "skill_name" : "ƮȻֱȥ",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С�ǧ�ﲻ���С�������$w����һ�Ž���������$n��$l",
        "force"  : 211,
        "attack" : 53,
        "dodge"  : 22,
        "parry"  : 24,
        "damage" : 184,
        "lvl"    : 30,
        "skill_name" : "ǧ�ﲻ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����Ĩ���������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force"  : 238,
        "attack" : 69,
        "dodge"  : 28,
        "parry"  : 35,
        "damage" : 195,
        "lvl"    : 50,
        "skill_name" : "����Ĩ��",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С����˺�ȥ��������������ɫ�������Ĵ���$n��$l",
        "force"  : 268,
        "attack" : 73,
        "dodge"  : 38,
        "parry"  : 15,
        "damage" : 110,
        "lvl"    : 80,
        "skill_name" : "���˺�ȥ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����￴������������ָ������$n��$n�������ֱܷ�$w����·",
        "force"  : 255,
        "attack" : 71,
        "dodge"  : 25,
        "parry"  : 24,
        "damage" : 208,
        "lvl"    : 90,
        "skill_name" : "���￴��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ������ɽ�չȡ���$w��һ������������һ�ɺ�������$n��$l",
        "force"  : 270,
        "attack" : 78,
        "dodge"  : 18,
        "parry"  : 19,
        "damage" : 223,
        "lvl"    : 110,
        "skill_name" : "��ɽ�չ�",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С�Ⱥ�ɾۻ᡹������$w����һ�Ž���������$n��$l",
        "force"  : 291,
        "attack" : 103,
        "dodge"  : 23,
        "parry"  : 28,
        "damage" : 241,
        "lvl"    : 130,
        "skill_name" : "Ⱥ�ɾۻ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ƮƮ�����������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force"  : 283,
        "attack" : 91,
        "dodge"  : 22,
        "parry"  : 25,
        "damage" : 255,
        "lvl"    : 140,
        "skill_name" : "ƮƮ����",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С�ǧɽ��ˮ��������������ɫ�������Ĵ���$n��$l",
        "force"  : 300,
        "attack" : 97,
        "dodge"  : 28,
        "parry"  : 37,
        "damage" : 258,
        "lvl"    : 150,
        "skill_name" : "ǧɽ��ˮ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ȥ���˼䡹��$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force"  : 328,
        "attack" : 118,
        "dodge"  : 25,
        "parry"  : 27,
        "damage" : 270,
        "lvl"    : 160,
        "skill_name" : "ȥ���˼�",
        "damage_type" : "����"
]),
([      
        "action" : "$N��ת����$w�������Ŀ������" HIR "ף�ڽ���" NOR
                   "�����ӵ����쾡�£����������$n",
        "force" : 430,
        "attack": 147,
        "dodge" : 96,
        "parry" : 128,
        "damage": 290,
        "skill_name" : "ף�ڽ���",
        "lvl"    : 180,
        "damage_type" : "����",
]),
([ 
        "action" : "$N���н���ͻ�֣���ʱ���Ⱪ�����ѽ���" HIM "ܽ�ؽ�"
                   "��" NOR "��ʹ����ֱ��$n��$l",
        "force" : 420,
        "attack": 154,
        "dodge" : 118,
        "parry" : 120,
        "damage": 310,
        "skill_name" : "ܽ�ؽ���",
        "lvl"    : 200,
        "damage_type" : "����",
]),
([
        "action" : "$N��$wһ�ӣ���Хһ���ڿն���һʽ��" HIY "������"
                   "��" NOR "����$w��ָ��$n$l",
        "force" : 420,
        "attack": 156,
        "dodge" : 100,
        "parry" : 120,
        "damage": 323,
        "skill_name" : "�����ϸ�",
        "lvl"    : 220,
        "damage_type" : "����",
]),
([
        "action" : "$N��Хһ��������$w���$n���ۣ�ͻȻ����ת������" HIG 
                   "ʯ�޽���" NOR "���ľ��跢�ӵ��˼���",
        "force" : 430,
        "attack": 160,
        "dodge" : 120,
        "parry" : 140,
        "damage": 348,
        "skill_name" : "ʯ�޽���",
        "lvl"    : 250,
        "damage_type" : "����",
]),
([
        "action" : "$N����$w��·����������������֣�һ����" HIW "��������"
                   NOR "����������Ʈ���ʹ�˳���",
        "force" : 480,
        "attack": 180,
        "dodge" : 140,
        "parry" : 160,
        "skill_name" : "��������",
        "damage": 360,
        "lvl"    : 300,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if (me->query("int") < 30)
                return notify_fail("���������Բ��㣬�޷�������ң���񽣷���\n");
 
        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ�������޷�ѧϰ��ң���񽣷���\n");

        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("��Ļ����ڹ����̫ǳ���޷�ѧϰ��ң���񽣷���\n");

        if ((int)me->query_skill("dodge", 1) < 120)
                return notify_fail("��Ļ����ڹ����̫ǳ���޷�ѧϰ��ң���񽣷���\n");

        if ((int)me->query_skill("sword", 1) < 120)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ��ң���񽣷���\n");

        if ((int)me->query_skill("yunlong-bian", 1) < 200)
                return notify_fail("��������޷���򲻹����޷�ѧϰ��ң���񽣷���\n");
        if ((int)me->query_skill("yunlong-jian", 1) < 200)
                return notify_fail("�����������򲻹����޷�ѧϰ��ң���񽣷���\n");
        if ((int)me->query_skill("yunlong-shengong", 1) < 200)
                return notify_fail("��������񹦻�򲻹����޷�ѧϰ��ң���񽣷���\n");
        if ((int)me->query_skill("yunlong-shou", 1) < 200)
                return notify_fail("��������ֻ�򲻹����޷�ѧϰ��ң���񽣷���\n");
        if ((int)me->query_skill("yunlong-zhua", 1) < 200)
                return notify_fail("�������צ��򲻹����޷�ѧϰ��ң���񽣷���\n");                                                                
        if ((int)me->query_skill("yunlong-shenfa", 1) < 200)
                return notify_fail("�����������򲻹����޷�ѧϰ��ң���񽣷���\n");                                                                


       if (((int)me->query_skill("bazhen-zhang", 1)) < 200)
               return notify_fail("��İ��������̫���ˡ�\n");
               
       if (((int)me->query_skill("houquan", 1)) < 200)
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shenfa", 1)) < 200)
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)) < 200)
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");

       if (((int)me->query_skill("wuhu-duanmendao", 1)) < 200)
               return notify_fail("����廢���ŵ�̫���ˡ�\n");



        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("wushen-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ң���񽣷���\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        int lvl,i;

        lvl = me->query_skill("wushen-jian", 1);
        weapon = me->query_temp("weapon");      


        if (! me->query_temp("weapon")) return 0;

    if (me->query("neili") < 300
           || me->query_skill_mapped("sword") != "wushen-jian"
           || random(3) != 1)
{
if (random(2)==0)
{
        if (lvl < 130 || lvl / 2 + random(lvl) < (int)victim->query_skill("dodge", 1) ||
            me->query("neili") < 150 ||
            me->query_skill("dodge", 1) < 180 ||
            me->query_skill("force", 1) < 150 ||             
            victim->is_busy() )
                 return 0;
        message_vision(HIW "\n$N" HIW "����" + weapon->name() + HIW "��Ȼ��ת������ͻ"
                       "�֣�ɲ�Ǽ��ѽ�$n" HIW "��·ȫ��������\n" NOR, me, victim); 
         victim->receive_wound("qi", (random(lvl)/2+2) / 2, me);
        victim->start_busy(2);
}
                     return 0;
}


        switch(random(4))
        {
           case 1:
              if (damage_bonus / 5 > victim->query_con() || random(5)==0)
              {
                  
                  victim->receive_wound("qi", (random(lvl)/2+1) , me);
                  
                  return random(2) ? HIW "$N" HIW "һ��������ɲ�Ǽ佣����ɣ�$n" HIW
                                     "���϶�ʱ��Ѫ��ӿ��\n" NOR:
                                     HIW "$N" HIW "����һת��һ��ƽƽ����$n" HIW "Ҫ��"
                                     "��������ͨ��һ������ȴ�̲��ż����ɱ�š�\n" NOR;
             }
             break;

          case 2:
             if ((random(me->query_skill("sword") / 2) + me->query_skill("sword")
                 > victim->query_skill("dodge")) || random(5)==0)
             {
                  weapon = me->query_temp("weapon");
                  if (!victim->is_busy())
                  victim->start_busy(3);
                  return   HIC "$N" HIC "������Ȼ��죬����" + weapon->name() + HIC "�����Ŀ��"
                           "��$n" HIC "�����ڽ���֮�С�\n" NOR;
             }
             break;

          case 3:
             if ( random(3) == 1 && !me->is_busy() && !me->query_temp("wsj")  && !me->query_temp("perform_wushenjian/qian") )
             {
                weapon = me->query_temp("weapon");
                message_vision(HIM "\n$N" HIM "��Хһ�����ڿն���" + weapon->name() + "��"
                             "�������һ����������̼佣����ɢ������������������"
                             "������Ӱ������$n" HIM "ȫ��\n" NOR, me, victim);
                me->set_temp("wsj",1);
                for (i = 0; i < 5; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                
                }                
                me->delete_temp("wsj");
             }
             break;                        

          default:
                return 0;
       }
     

        return 1;                         
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("wushen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������Ŀǰû�а취��ϰ��ң������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("��������������޷���ϰ��ң������\n");
        
        me->add("qi", -50);
        me->add("neili", -82);
        return 1;
}








string perform_action_file(string action)
{
        return __DIR__"wushen-jian/" + action; 
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 8000)	damage2=8000;
msg = HIR"$N"+HIR+"$N���־۳ɻ�צ״! ����Ѫ��ץ��һ��ץס$n��"+ xue_name[random(sizeof(xue_name))] +NOR;
           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}


           return j;
}      
