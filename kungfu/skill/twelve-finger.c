// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// yjws
// һ����
// �һ����ڶ�������
// 18846103
// ����
// finger
// ����ʮ��ָ
#include <ansi.h>





inherit SKILL;

////////////////////////////////

mapping *action = ({
// ZHAOSHI :0

([
"action" :"$N˫Ŀ΢������������ӳ�һָ�����Ǻ���ʮ��ָ��һʽ��һ�޲������С���ֻ��һ��������ָ�������ֱȡ$n���ʺ�",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "һ�޲�������"
]),
// ZHAOSHI :1

([
"action" :"$N��������ʳָһ�����һ����ɫָ����������ָһ��һ����ɫָ�������ֻ����ɫָ����Ȼ��������˲�䳬Խ��ɫָ������������һǰһ������$nϮ����",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "���޺��ձ���"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"����ʮ��ָ"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"����ʮ��ָ"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "finger" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("twelve-finger",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
mixed hit_ob(object me, object victim, int damage)
{
        mixed result;

if (me->query("zhuanfinal/1") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->receive_wound("qi", victim->query("qi")/8);
        if (!userp(victim))
         victim->receive_wound("qi", 500);
	return RED"$Nʹ����ն�ɾ�!!$nͻȻ�ؿ�һʹ��Ѫ��!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->add("neili", -victim->query("neili")/8);
        if (!userp(victim))
         victim->add("neili", -500);
	return HIY"$Nʹ�������ɾ�!!$nͻȻ������ʧ!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!victim->is_busy())
	victim->start_busy(4);
	return HIY"$Nʹ�������ɾ�!!$nͻȻ��æ����!\n"NOR;
}
else
if (me->query("5zhuan") && random(2)==0 )
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);

                if (me->query("jing",1) < me->query("max_jing",1) )
                me->add("jing",me->query("max_jing")/8);
                
                if (me->query("neili",1) < me->query("max_neili",1) )
                me->add("neili",me->query("max_neili")/8);

                if (me->query("qi") < me->query("max_qi") )
return HIG"$Nʹ�����������ɾ�!!$Nȫ����˺��˺ܶ�!\n"NOR;
} 
        if (damage < 100) return 0;

        if (random(damage) > victim->query_str() && random(3)==0) 
        {
                victim->receive_wound("qi", random(damage)+50);
                return  HIW "�����������꡹һ�����죬�ѱ�$N����ɱ�����ˣ�$n��ʱѪð���ɣ�����\n" NOR;
        }
}
int ssl(int level){ int i=sizeof(action)-1;  return i;}
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
                       string result;
       int ap, dp;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");

        if( me->is_busy() && random(2)==0)  return damage;


if (me->query("zhuanfinal/4") ==1 && random(3)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	result = HIY"$nʹ�������ɾ�!!$nȫ����˺��˺ܶ�!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!ob->is_busy() )
ob->start_busy(2);
	result = HIY"$nʹ���˶��ɾ�!!$nͻȻ�����ֿ���!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	result = HIY"$nʹ�������ɾ�!!$nͻȻ�����ָ���!\n"NOR;
}
else
if (me->query("5zhuan") && random(2)==0 )
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);

                if (me->query("jing",1) < me->query("max_jing",1) )
                me->add("jing",me->query("max_jing")/8);
                
                if (me->query("neili",1) < me->query("max_neili",1) )
                me->add("neili",me->query("max_neili")/8);

                if (me->query("qi") < me->query("max_qi") )
	result = HIY"$nʹ�����������ɾ�!!$nȫ����˺��˺ܶ�!\n"NOR;
}     
else
 if ( random(6)==1)
        {
                damage=damage/3;
                if (damage <30) damage=30;
                switch (random(4))
                {
                case 0:
                        result = HIW "$n" HIW "�溬΢Ц������һ���ѽ���"
                                            "�����н�������ȫ��������\n" NOR;
                       //break;
                case 1:
                        result = HIW "$n" HIW "üͷ΢΢һ�壬��Ҳ��������"
                                            "$N" HIW "��һ�ߡ�\n" NOR;
                        //break;
                case 2:
                        //result = HIW "$n" HIW "����΢΢һ�����ѽ�$N" HIW 
                                            "�����������⡣\n" NOR;
                        //break;
                default:
                        result = HIW "$n" HIW "һ����ߣ�����΢΢һ������"
                                            "ƮȻԶȥ��ʹ$N" HIW "�Ľ���ȫ���ô���\n" NOR;
                        //break;
                }
        }
if (result) message_vision(result,ob,me);
            return damage;
}


string perform_action_file(string action)
{
        return __DIR__"meskill/" + action;
} //total 178 lines!
