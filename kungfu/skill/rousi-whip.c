//
#include <ansi.h>
inherit SKILL;

#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";

string* skill_head =({
        "$N�������ˣ�ʹ��һ�� �����ϡ�",
        "$N�������ܣ�һʽ [����]",
        "$N����һ�ϣ�ʹ�� [����]",
        "$N��ȻһЦ��һʽ ��֧�ϡ�",
        "$N����Ծ��ʹ�� [����]",
});
string* skill_tail =({
        "������$w��Ϊһ���������$n��$l��",
        "������$w��������Ӱ����$n��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��ɣ�������㺮�⡣",
        "��$w���Ҽ缱˦��󣬶��ػ���$n$l��",
});

mapping *action = ({
   ([   "action":
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪��һ��"+BLINK""+HIM"�����ϡ�"NOR"����Ȼ����$n�ĺ���",
     "dodge":     5,
                "parry":                10,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"����Ծ��$ņ��һ����������$N����$w��������Ӱ��"+BLINK""+HIC"[����]"NOR"�ѽ�$n����",
     "dodge":     15,
                "parry":                25,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w����һ��������$w�����һ��,һʽ"+BLINK""+HIG"[����]"NOR"���εĴ���$n������",
     "dodge":     10,
                "parry":                15,
     "damage":     335,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����һ����˿������û������������Ӻ����������������ˣ���$n����Ʈ������������һ��"+BLINK""+HIW"[����]"NOR"",
     "dodge":     10,
                "parry":                5,
     "damage":     350,
     "damage_type":   "����"
   ]),
   ([   "action":
"ͻȻ֮�䣬$N����һ��һ�Σ��������ɣ�ʹ��һ��"+BLINK""+HIB"��֧�ϡ�"NOR"��$w���Ҽ缱˦��󣬶��ػ���$n$l����������������ʸ�ö���",
     "dodge":     20,
                "parry":                30,
     "damage":     345,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

	if ((int)me->query("max_neili") < 800)
		return notify_fail(HIC"�������������\n"NOR);

	if ((int)me->query_skill("chuanyun-shou", 1) < 250)
		return notify_fail(HIC"��Ĵ��Ʋ�����\n"NOR);

	if ((int)me->query_skill("tianchang-zhang", 1) < 250)
		return notify_fail(HIC"����쳤�Ʋ�����\n"NOR);
	if ((int)me->query_skill("lingxu-bu", 1) < 250)
		return notify_fail(HIC"������鲽������\n"NOR);
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"��İ����ķ�������\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"��ĺ�ɽ����������\n"NOR);	
	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("��˿�ֱޱ�����ϰ����ķ���������\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("���������һ�ѱ��Ӳ������޷���\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�������������������˿�ֱޡ�\n");
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"��İ����ķ�������\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"��ĺ�ɽ����������\n"NOR);	
	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("��˿�ֱޱ�����ϰ����ķ���������\n");		
		
	me->receive_damage("qi", 35);
	me->add("neili", -20);
	return 1;
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("rousi-whip",1);
         lvl = (int)me->query_skill("rousi-whip", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string func)
{
return __DIR__"rousi-whip/" + func;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("baiyun-xinfa", 1);

        
            if ( random(8) == 0 || random(level) > 180){
         if (random(3)==0  && !ob->is_busy()) ob->start_busy(2);
         msg = HIG"$N��������ķ����³�һ����Ѫ!!��\n"NOR;
         msg += GRN"$N���˺ö���!!��\n"NOR;
if ((int)me->query("qi")<=(int)me->query("max_qi")*2)
{
             me->add("qi",(level+100));
             me->add("eff_qi",(level+100));
}
msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
        int i;
        object target;

        level   = (int) me->query_skill("rousi-whip",1);	
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("whip",1);
        level2= (int) me->query_skill("huiyan-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("rousi-whip",1))+50;

if (damage > 1600) damage=1600;

if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "baiyun-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("rousi-whip",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

