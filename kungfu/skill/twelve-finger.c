// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// yjws
// 一剑风
// 桃花岛第二代弟子
// 18846103
// 男性
// finger
// 恨天十二指
#include <ansi.h>





inherit SKILL;

////////////////////////////////

mapping *action = ({
// ZHAOSHI :0

([
"action" :"$N双目微睁，左手随意挥出一指，正是恨天十二指第一式「一恨才人无行」。只见一道劲气从指尖射出，直取$n的咽喉。",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "一恨才人无行"
]),
// ZHAOSHI :1

([
"action" :"$N先是右手食指一弹射出一道金色指劲，接着中指一弹一道蓝色指劲射出。只见蓝色指劲竟然后发先至，瞬间超越金色指劲。两道劲力一前一后向着$n袭来。",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "二恨红颜薄命"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"恨天十二指"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"恨天十二指"+"。\n");
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
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
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
	return RED"$N使用了斩仙决!!$n突然胸口一痛鲜血狂奔!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->add("neili", -victim->query("neili")/8);
        if (!userp(victim))
         victim->add("neili", -500);
	return HIY"$N使用了破仙决!!$n突然内力消失!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!victim->is_busy())
	victim->start_busy(4);
	return HIY"$N使用了乱仙决!!$n突然手忙脚乱!\n"NOR;
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
return HIG"$N使用了无上妙仙决!!$N全身的伤好了很多!\n"NOR;
} 
        if (damage < 100) return 0;

        if (random(damage) > victim->query_str() && random(3)==0) 
        {
                victim->receive_wound("qi", random(damage)+50);
                return  HIW "你听到「喀嚓」一声轻响，已被$N所发杀气挫伤，$n顿时血冒三丈！！！\n" NOR;
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

	result = HIY"$n使用了妙仙决!!$n全身的伤好了很多!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!ob->is_busy() )
ob->start_busy(2);
	result = HIY"$n使用了动仙决!!$n突然动作又快了!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	result = HIY"$n使用了银仙决!!$n突然内力恢复了!\n"NOR;
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
	result = HIY"$n使用了无上妙仙决!!$n全身的伤好了很多!\n"NOR;
}     
else
 if ( random(6)==1)
        {
                damage=damage/3;
                if (damage <30) damage=30;
                switch (random(4))
                {
                case 0:
                        result = HIW "$n" HIW "面含微笑，轻轻一格，已将天"
                                            "下所有进攻招数全部封死。\n" NOR;
                       //break;
                case 1:
                        result = HIW "$n" HIW "眉头微微一皱，动也不动，将"
                                            "$N" HIW "震到一边。\n" NOR;
                        //break;
                case 2:
                        //result = HIW "$n" HIW "身形微微一抖，已将$N" HIW 
                                            "迫退至丈许开外。\n" NOR;
                        //break;
                default:
                        result = HIW "$n" HIW "一声轻哼，身形微微一动，已"
                                            "飘然远去，使$N" HIW "的进攻全无用处。\n" NOR;
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
