// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	me->add("neili", - factor );
	damage = (int)me->query("neili")/20 + 2*factor
		- (int)victim->query("neili")/25;
        if (damage > 10000) damage=10000;
        if (damage <20 ) damage =20;
        if (me->query_temp("armor/hands")) damage=damage/20;
	if( damage < 0 && !me->query_temp("armor/hands")) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			if (damage > me->query("qi",1)/2) damage=me->query("qi",1)/2;
			me->receive_damage( "qi", damage );
			me->receive_wound( "qi", damage/2 );
			if( damage < 20 ) return "$N受到$n的内力反震，闷哼一声。\n";
			else if( damage < 60 ) return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
			else if( damage < 90 ) return "$N被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
			else if( damage < 100 ) return "$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n";
                        else return "$N被$n的内力一震，只觉浑身经脉欲断，气血倒流，几乎晕了过去。！！\n";
		}
		
		
		
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	//damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	//if( random(me->query_skill("force")) < damage )
		return damage;
}
