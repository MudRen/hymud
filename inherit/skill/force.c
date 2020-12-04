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
			if( damage < 20 ) return "$N�ܵ�$n�����������ƺ�һ����\n";
			else if( damage < 60 ) return "$N��$n���������𣬡��١���һ������������\n";
			else if( damage < 90 ) return "$N��$N������һ���ؿ������ܵ�һ���ش�����������������\n";
			else if( damage < 100 ) return "$N��$n������һ����ǰһ�ڣ��������ɳ�������\n";
                        else return "$N��$n������һ��ֻ�����������ϣ���Ѫ�������������˹�ȥ������\n";
		}
		
		
		
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	//damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	//if( random(me->query_skill("force")) < damage )
		return damage;
}
