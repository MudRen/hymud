// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"one",
		"action":		"$NÉÏÇ°Ò»²½£¬ÊÖÖĞ$w¶¾Éß°ã´ÌÏò$nµÄ$l",
		"dodge":		50,
		"damage":		270,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"two",
		"action":		"$NÉíĞÎÒ»×ª£¬·´ÊÖÒ»»Ó£¬ÊÖÖĞ$w´ÌÏò$nµÄ$l",
		"dodge":		50,
		"damage":		220,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"three",
		"action":		"$nÑÛÇ°Ò»»¨£¬$NÊÖÖĞµÄ$wÒÑ¾­Ñ¸½İÎŞ±ÈµÄ´ÌÏò$nµÄ$l",
		"dodge":		40,
		"force" :		100,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"four",
		"action":		"$NÖ»¹¥²»ÊØ£¬ÊÖÖĞ$wÒ»¶¶£¬Íù$nµÄ$l´Ì³öÒ»½£",
		"dodge":		40,
		"damage":		240,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"five",
		"action":		"$NµÄ¡¸×óÊÖ½£·¨¡¹Ö»ÓĞ[31m´Ì[37m£¬¼òµ¥¶øÓĞĞ§µØÍù$nµÄ$l´ÌÈ¥",
		"dodge":		60,
		"damage":		280,
		"force" :		100,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"six",
		"action":		"$NÊÖÖĞ$wÖ±Ö¸$n$l£¬·¢³ö±ÆÈË½£ÆøÉÁµç°ã´ÌÈ¥",
		"dodge":		20,
		"damage":		220,
		"damage_type":	"´ÌÉË"
	]),
});

int valid_learn(object me)
{
	object ob;


	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»°Ñ½£²ÅÄÜÁ·½£·¨¡£\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30
	||	(int)me->query("neili") < 5 )
		return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓĞ°ì·¨Á·Ï°×óÊÖ½£¡£\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	//write("Äã°´ÖøËùÑ§Á·ÁËÒ»±é×óÊÖ½£·¨¡£\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\nÄãÍ»È»¾õµÃÒ»¹É¶ñÆø³åÉÏĞÄÍ·£¬Ö»¾õµÃÏëÉ±ÈË....\n\n" NOR);
		me->add("bellicosity", 10);
	} else
		me->add("bellicosity", 1);
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -20;
}

string perform_action_file(string action)
{
        return __DIR__"lefthand-sword/" + action;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        string name, weapon;
        

	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(4)==0 ) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return "Ö»ÌıÒ»Éù²Òº¿£¬Ò»¹ÉÏÊÑª´Ó$nµÄÉË¿ÚÅç³ö£¡\n" ;	
}
}