// 闪电术

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	kee, damage, spells;

	message_vision(HIC "\n一个闪电向$N"HIC"的头上打来，\n" NOR, obj);
	spells = me->query_skill("spells");


                damage = (int)me->query_skill("boss-ai", 1)*10;
                damage = damage + random(damage);
	if(damage < 0) damage = 10;
	if( random(me->query("combat_exp"))> (int)obj->query("combat_exp")/3) {

		message_vision(RED "正打在了$N"RED"的头上！\n" NOR, obj);
               		obj->receive_damage("qi", damage,me);
               		obj->receive_wound("qi", damage,me);
               		obj->receive_damage("jing", damage/2,me);
               		obj->receive_wound("jing", damage/3,me);

 		COMBAT_D->report_status(obj);

       		}
	else 
			message_vision(RED "但被$N"RED"躲过了！\n" NOR, obj);
	return 1;
	
}
int perform(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;

        if ((int)me->query_condition("boss-ai"))
                return notify_fail(WHT"现在不能使用。\n"NOR);



	msg = YEL "$N"YEL"脚踩五芒星，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
	msg = msg + HIC "猛地双手一挥，天上打下无数闪电！\n\n" NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->apply_condition("boss-ai",1);
	return 1;
}

