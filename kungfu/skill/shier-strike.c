// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// daodao
// »ğÉÕ
// [1;33m»î·ğ[2;37;0m
// 5184811
// ÄĞĞÔ
// strike
// ºŞÌìÊ®¶şÕÆ
#include <ansi.h>





inherit SKILL;

////////////////////////////////

mapping *action = ({
// ZHAOSHI :0

([
"action" :"$NË«Ä¿Î¢Õö£¬×óÊÖËæÒâÒ»»Ó£¬·¢³öÒ»µÀÖ¸¾¢Ö±È¡$nÑÊºí¡£ÕıÊÇ¡¸Ò»ºŞ²ÅÈËÎŞĞĞ¡¹",
"force" :60,
"damage" :40,
"damage_type": "ÄÚÉË",
"lvl" : 0,
"skill_name" : "Ò»ºŞ²ÅÈËÎŞĞĞ"
]),
// ZHAOSHI :1

([
"action" :"$NÓÒÊÖÊ³Ö¸¡¢ÖĞÖ¸Á¬µ¯£¬Éä³öÒ»½ğÒ»À¶Á½µÀÖ¸¾¢£¬Ö±±¼$nĞØ¿Ú´óÑ¨¡£´ËÄË¡¸¶şºŞºìÑÕ±¡Ãü¡¹",
"force" :90,
"damage" :60,
"damage_type": "ÄÚÉË",
"lvl" : 1,
"skill_name" : "¶şºŞºìÑÕ±¡Ãü"
]),
// ZHAOSHI :2

([
"action" :"$NÉíĞÎÒ»ÉÁ£¬×óÊÖÈı¸öÊÖÖ¸¿ÛÏò$nºóÄÔ¡£¡¸ÈıºŞ½­ÀË²»Ï¢¡¹",
"force" :120,
"damage" :80,
"damage_type": "ÄÚÉË",
"lvl" : 2,
"skill_name" : "ÈıºŞ½­ÀË²»Ï¢"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ºŞÌìÊ®¶şÕÆ"+"±ØĞë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"ºŞÌìÊ®¶şÕÆ"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("shier-strike",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
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
	return RED"$NÊ¹ÓÃÁËÕ¶ÏÉ¾ö!!$nÍ»È»ĞØ¿ÚÒ»Í´ÏÊÑª¿ñ±¼!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(victim))
	victim->add("neili", -victim->query("neili")/8);
        if (!userp(victim))
         victim->add("neili", -500);
	return HIY"$NÊ¹ÓÃÁËÆÆÏÉ¾ö!!$nÍ»È»ÄÚÁ¦ÏûÊ§!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!victim->is_busy())
	victim->start_busy(4);
	return HIY"$NÊ¹ÓÃÁËÂÒÏÉ¾ö!!$nÍ»È»ÊÖÃ¦½ÅÂÒ!\n"NOR;
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
return HIG"$NÊ¹ÓÃÁËÎŞÉÏÃîÏÉ¾ö!!$NÈ«ÉíµÄÉËºÃÁËºÜ¶à!\n"NOR;
} 
        if (damage < 100) return 0;

        if (random(damage) > victim->query_str() && random(3)==0) 
        {
                victim->receive_wound("qi", random(damage)+50);
                return  HIW "ÄãÌıµ½¡¸¿¦àê¡¹Ò»ÉùÇáÏì£¬ÒÑ±»$NËù·¢É±Æø´ìÉË£¬$n¶ÙÊ±ÑªÃ°ÈıÕÉ£¡£¡£¡\n" NOR;
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

	result = HIY"$nÊ¹ÓÃÁËÃîÏÉ¾ö!!$nÈ«ÉíµÄÉËºÃÁËºÜ¶à!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!ob->is_busy() )
ob->start_busy(2);
	result = HIY"$nÊ¹ÓÃÁË¶¯ÏÉ¾ö!!$nÍ»È»¶¯×÷ÓÖ¿ìÁË!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	result = HIY"$nÊ¹ÓÃÁËÒøÏÉ¾ö!!$nÍ»È»ÄÚÁ¦»Ö¸´ÁË!\n"NOR;
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
	result = HIY"$nÊ¹ÓÃÁËÎŞÉÏÃîÏÉ¾ö!!$nÈ«ÉíµÄÉËºÃÁËºÜ¶à!\n"NOR;
}     
else
 if ( random(6)==1)
        {
                damage=damage/3;
                if (damage <30) damage=30;
                switch (random(4))
                {
                case 0:
                        result = HIW "$n" HIW "Ãæº¬Î¢Ğ¦£¬ÇáÇáÒ»¸ñ£¬ÒÑ½«Ìì"
                                            "ÏÂËùÓĞ½ø¹¥ÕĞÊıÈ«²¿·âËÀ¡£\n" NOR;
                       //break;
                case 1:
                        result = HIW "$n" HIW "Ã¼Í·Î¢Î¢Ò»Öå£¬¶¯Ò²²»¶¯£¬½«"
                                            "$N" HIW "Õğµ½Ò»±ß¡£\n" NOR;
                        //break;
                case 2:
                        //result = HIW "$n" HIW "ÉíĞÎÎ¢Î¢Ò»¶¶£¬ÒÑ½«$N" HIW 
                                            "ÆÈÍËÖÁÕÉĞí¿ªÍâ¡£\n" NOR;
                        //break;
                default:
                        result = HIW "$n" HIW "Ò»ÉùÇáºß£¬ÉíĞÎÎ¢Î¢Ò»¶¯£¬ÒÑ"
                                            "Æ®È»Ô¶È¥£¬Ê¹$N" HIW "µÄ½ø¹¥È«ÎŞÓÃ´¦¡£\n" NOR;
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
