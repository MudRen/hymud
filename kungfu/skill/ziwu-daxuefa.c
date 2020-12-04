#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
mapping *action = ({
([      "action":"$N����һչ��ʩ��һ�С�Ыβ�롹������$w��������$n��$l",
        "force" : 30,
        "attack": 15,
        "dodge" : 10,
        "parry" : 12,
        "damage": 25,
        "lvl"   : 0,
        "skill_name" : "Ыβ��",
        "damage_type" : "����"
]),
([      "action":"$Nһ��߳�ȣ�$w���������£�ʩһ�С���ü�̡���$n��$l��ȥ",
        "force" : 53,
        "attack": 21,
        "dodge" : 12,
        "parry" : 13,
        "damage": 37,
        "lvl"   : 10,
        "skill_name" : "��ü��",
        "damage_type" : "����"
]),
([      "action":"$N����һԾ��������$wʹ������⾢������������������$n$l",
        "force" : 71,
        "attack": 24,
        "dodge" : 15,
        "parry" : 22,
        "damage": 45,
        "lvl"   : 20,
        "skill_name" : "��⾢",
        "damage_type" : "����"
]),
([      "action":"$N����$w�����һ�Σ���Ȼʹ��һ�С��ط������ơ���쬵Ĵ���$n$l",
        "force" : 98,
        "attack": 35,
        "dodge" : 15,
        "parry" : 13,
        "damage": 54,
        "lvl"   : 40,
        "skill_name" : "�ط�������",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ����ת�����ơ�������$w�����Ẉ̂���������$n��ȥ",
        "force" : 140,
        "attack": 46,
        "dodge" : 11,
        "parry" : 9,
        "damage": 65,
        "lvl"   : 60,
        "skill_name" : "��ת������",
        "damage_type" : "����"
]),
([      "action":"$N����ʩչ��һ�С��������ơ������е�$w������$n������Ѩ",
        "force" : 90,
        "attack": 15,
        "dodge" : 10,
        "parry" : 20,
        "damage": 25,
        "lvl"   : 70,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action":"$N��������һ�С���÷ӳѩ����$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 130,
        "lvl"   : 90,
        "skill_name" : "��÷ӳѩ",
        "damage_type" : "����"
]),
([      "action":"$N��ǰ����һ�����������ս�⣬����$wʹ����׷����硹������$n�ĵز�Ѩ",
        "force" : 170,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 235,
        "lvl"   : 120,
        "skill_name" : "׷�����",
        "damage_type" : "����"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ�����ɻ��ڴ���ź����������$n������Ѩ",
        "force" : 190,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 240,
        "lvl"   : 180,
        "skill_name" : "�ɻ��ڴ�",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ������ӱޡ������������Ӱ��$w��$n�����ȥ",
        "force" : 240,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 250,
        "lvl"   : 200,
        "skill_name" : "����ӱ�",
        "damage_type" : "����"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�����̨�۾�����һ�ʿ���һ�ʵع���$n",
        "force" : 260,
        "attack": 65,
        "dodge" : 15,
        "parry" : 50,
        "damage": 260,
        "lvl"   : 220,
        "skill_name" : "��̨�۾�",
        "damage_type" : "����"
]),
([      "action":"$Nʹ��һ�С�Ⱥɽ��Ӱ��ͦ���й�ֱ�����ʼ��������;��Ȼת�����ϱ���޷�",
        "force" : 280,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 275,
        "lvl"   : 260,
        "skill_name" : "Ⱥɽ��Ӱ",
        "damage_type" : "����"
]),
([      "action":"$N����б��һ�ʣ�һ�С����׾��ơ�����ź����ʷ磬��$n��Χ����",
        "force" : 310,
        "attack": 75,
        "dodge" : 25,
        "parry" : 64,
        "damage": 290,
        "lvl"   : 280,
        "skill_name" : "���׾���",
        "damage_type" : "����"
]),
([      "action":"$N��������һ�С������־���$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 300,
        "lvl"   : 300,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N��ǰ����һ�����������ս�⣬ʹ���������־�������$n�ĵز�Ѩ",
        "force" : 170,
        "attack": 40,
        "dodge" : 15,
        "parry" : 32,
        "damage": 315,
        "lvl"   : 320,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ�����ˡ��־����$n������Ѩ",
        "force" : 190,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 320,
        "lvl"   : 330,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�����־������������Ӱ��$w��$n�����ȥ",
        "force" : 240,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 350,
        "lvl"   : 350,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬��Ȼ�ӳ����롹�־�����$n",
        "force" : 260,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 360,
        "lvl"   : 380,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$Nʹ��һ�С������־�ͦ���й�ֱ�����ʼ��������;��Ȼת������",
        "force" : 280,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 415,
        "lvl"   : 400,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N����б��һ�ʣ�һ�С��ԡ��־�����ź����ʷ磬��$n��Χ����",
        "force" : 310,
        "attack": 75,
        "dodge" : 5,
        "parry" : 64,
        "damage": 420,
        "lvl"   : 420,
        "skill_name" : "���־�",
        "damage_type" : "����"
]),
([      "action":"$N����һչ��ʩ��һ�С��������ơ���$w��������$n��$l",
        "force" : 30,
        "attack": 15,
        "dodge" : 10,
        "parry" : 12,
        "damage": 435,
        "lvl"   : 430,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action":"$Nһ��߳�ȣ�$w���������£�ʩһ�С�����Х����$n��$l��ȥ",
        "force" : 53,
        "attack": 21,
        "dodge" : 12,
        "parry" : 13,
        "damage": 447,
        "lvl"   : 450,
        "skill_name" : "����Х",
        "damage_type" : "����"
]),
([      "action":"$N����һԾ����$wʹ��һʽ�������С�����������������$n$l",
        "force" : 71,
        "attack": 24,
        "dodge" : 15,
        "parry" : 22,
        "damage": 465,
        "lvl"   : 480,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action":"$N$w�����һ�Σ���Ȼʹ��һ�С�����޾��ơ���쬵Ĵ���$n$l",
        "force" : 98,
        "attack": 35,
        "dodge" : 15,
        "parry" : 13,
        "damage": 501,
        "lvl"   : 500,
        "skill_name" : "����޾���",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�������Ԫ�ơ���$w�����Ẉ̂���������$n��ȥ",
        "force" : 140,
        "attack": 46,
        "dodge" : 11,
        "parry" : 9,
        "damage": 510,
        "lvl"   : 520,
        "skill_name" : "�����Ԫ��",
        "damage_type" : "����"
]),
([      "action":"$Nһ�С�����ʽ��������$w������$n������Ѩ",
        "force" : 90,
        "attack": 15,
        "dodge" : 10,
        "parry" : 20,
        "damage": 525,
        "lvl"   : 550,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action":"$N��������һ�С����ʽ����$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 110,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 530,
        "lvl"   : 570,
        "skill_name" : "���ʽ",
        "damage_type" : "����"
]),
([      "action":"$N��ǰ����һ��������$wʹ��������ʽ��������$n�ĵز�Ѩ",
        "force" : 130,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 555,
        "lvl"   : 580,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ������ѩʽ�����ź����������$n������Ѩ",
        "force" : 150,
        "attack": 50,
        "dodge" : 15,
        "parry" : 35,
        "damage": 540,
        "lvl"   : 590,
        "skill_name" : "��ѩʽ",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�����ʽ�������������Ӱ��$w��$n�����ȥ",
        "force" : 270,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 500,
        "lvl"   : 600,
        "skill_name" : "���ʽ",
        "damage_type" : "����"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�������ʽ����һ�ʿ���һ�ʵع���$n",
        "force" : 280,
        "attack": 65,
        "dodge" : 15,
        "parry" : 50,
        "damage": 510,
        "lvl"   : 620,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action":"$Nһ�С��ɺ�չ�᡹������$w��Ȼ����$nС��",
        "force" : 220,
        "attack": 24,
        "dodge" : 10,
        "parry" : 20,
        "damage": 545,
        "lvl"   : 700,
        "skill_name" : "�ɺ�չ��",
        "damage_type" : "����"
]),
([      "action":"$N���˷�����һ�С�������Ѩʽ��������$w����$n���Ѩ",
        "force" : 250,
        "attack": 40,
        "dodge" : 14,
        "parry" : 30,
        "damage": 560,
        "lvl"   : 740,
        "skill_name" : "������Ѩʽ",
        "damage_type" : "����"
]),
([      "action":"$N����$w��Ȼ��ת��ʹ�����ƿ��ճ���������$n������Ѩ",
        "force" : 280,
        "attack": 60,
        "dodge" : 25,
        "parry" : 32,
        "damage": 575,
        "lvl"   : 760,
        "skill_name" : "�ƿ��ճ�",
        "damage_type" : "����"
]),
([      "action":"$N����$w�������죬ʹ����������ת����$wֱ��$n������Ѩ",
        "force" : 220,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 570,
        "lvl"   : 780,
        "skill_name" : "������ת",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�������⡹������$w������ǧ�����$n�ɻ���ȥ",
        "force" : 360,
        "attack": 70,
        "dodge" : 10,
        "parry" : 45,
        "damage": 580,
        "lvl"   : 800,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action":"$N��ʽ��Ȼ������һ�С�����ɼ���������$w������֮��ֱϮ$wҪѨ",
        "force" : 300,
        "attack": 100,
        "dodge" : 51,
        "parry" : 50,
        "damage": 510,
        "lvl"   : 820,
        "skill_name" : "����ɼ�",
        "damage_type" : "����"
]),
([      "action":"$Nһ�С�����������������$wһ����������$n������Ѩ",
        "force" : 390,
        "attack": 15,
        "dodge" : 10,
        "parry" : 20,
        "damage": 525,
        "lvl"   : 830,
        "skill_name" : "��������",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N��������һ�С��ٳ󵱵�����$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 330,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 530,
        "lvl"   : 840,
        "skill_name" : "�ٳ󵱵�",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N��ǰ����һ�����������ս�⣬����$wʹ������ʱ���ơ�������$n�ĵز�Ѩ",
        "force" : 370,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 535,
        "lvl"   : 860,
        "skill_name" : "��ʱ����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ������î���ġ����ź����������$n������Ѩ",
        "force" : 390,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 540,
        "lvl"   : 880,
        "skill_name" : "��î����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N����Ծ��һʽ���粻���ӡ������������Ӱ��$w��$n�͹�Ѩ�����ȥ",
        "force" : 340,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 550,
        "lvl"   : 900,
        "skill_name" : "�粻����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�����Ԫ���졹��һ�п���һ�еع���$n",
        "force" : 360,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 600,
        "lvl"   : 920,
        "skill_name" : "��Ԫ����",
        "damage_type" : "��Ѩ"
]),
([      "action":"$Nʹ��һ�С���ҫ�ƶ����й�ֱ����$w�������ѣ���;��Ȼת�����ϴ���$n",
        "force" : 380,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 625,
        "lvl"   : 940,
        "skill_name" : "��ҫ�ƶ�",
        "damage_type" : "��Ѩ"
]),
([      "action":"$N����б��һ�У�����һʽ����ɷ��ء�����ź�����������$n��Χ����",
        "force" : 310,
        "attack": 75,
        "dodge" : 15,
        "parry" : 64,
        "damage": 680,
        "lvl"   : 1000,
        "skill_name" : "��ɷ���",
        "damage_type" : "��Ѩ"
]),
});


int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("���������Ϊ̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("dagger", 1) < 80)
                return notify_fail("��Ļ����̱����̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("dagger", 1) < (int)me->query_skill("ziwu-daxuefa", 1))
                return notify_fail("��Ļ����̱�ˮƽ���ޣ��޷���������������Ѩ����\n");

	if( (string)me->query("family/family_name")!="�㵴��")
return notify_fail("�����书Ҫ���㵴�ɵ��������˲���ѧ��\n");

      if (me->query_skill("three-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������Ž�������!\n");
      
      if (me->query_skill("blood-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�����Ѫ�½�������!\n");

      if (me->query_skill("doomsword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������촵Ѫ��������!\n");

      if (me->query_skill("fy-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�����������ƽ�����!\n");

      if (me->query_skill("siqi-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������潣������!\n");

      if (me->query_skill("qingpingsword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�������ƽ��������!\n");

      if (me->query_skill("sharen-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�����ɱ�˽�������!\n");

      if (me->query_skill("feixian-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������ɽ�������!\n");

    return 1;
}

string query_skill_name(int level)
{
        int i;

        for(i = sizeof(action) - 1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("ziwu-daxuefa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("�����ֵ������޷���ϰ�����Ѩ����\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("������������������Ѩ����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������Ѩ����\n");

        me->receive_damage("qi", 65);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ziwu-daxuefa/" + action;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("ziwu-daxuefa",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( (random(level) > 150 && random(4)==0))
	{
        if (userp(victim))
        if (random(3)==0 && !victim->is_busy()) victim->start_busy(2);
        victim->receive_wound("qi", level,me );	
        return HIR "�������Ѩ!!����$N�������д�Ѩ�� ,$n�������ˣ���֪����!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if(  (random(level) > 80 && random(3)==0 ))
	{

        victim->receive_wound("qi", random(level)+50,me );	
        return HIR "������������һ����Ѫ��$n���������!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("ziwu-daxuefa", 1);

        if( damage < 10 ) return 1;
         
         if ( random(4) == 0 && random(level) > 150){
         if (random(3)==0 && !ob->is_busy()) ob->start_busy(2);
         msg = YEL"$N���˷�����һ�С�������Ѩʽ����������������$n���Ѩ"NOR;
         msg += YEL"�������Ѩ!!����$n�����м�����Ѩ �³�һ����Ѫ!!��\n"NOR;
		ob->receive_damage("qi", level+100,me);
		ob->receive_wound("qi", level+100,me);

if (random(3)==0 && userp(ob) && !ob->is_busy()) ob->start_busy(2);
        if (userp(me) && userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
		ob->receive_damage("qi", ob->query("qi")/12,me);
if (ob->query("eff_qi")/12 > 20)
		ob->receive_wound("qi", ob->query("qi")/12,me);
             
}

msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}