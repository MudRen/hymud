mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n,sharpness,damage;
object weapon;
string msg1,msg2,msg3;
sharpness=query("sharpness");
if (!sharpness) sharpness=0;
msg1="";
if (random(sharpness) > 1 && random(8)==0)
{

                victim->receive_damage("qi", sharpness * 10);
                victim->receive_wound("qi", sharpness * 10);
                return RED "$N" HIY "����"+query("name")+RED"һ�����������⣬��ʱ��$n"
                       RED "���ˣ���Ѫ˳��$n����ֱ��������\n" NOR;
}
else if (random(3)==0)
{
        switch (random(18) )
        {

        case 0:
                if (query("wtypeA") >0)
{
                if (! victim->is_busy())
                victim->start_busy(query("wtypeA") + 2);
                return query("name")+HIY"���һ����������$n��˫�ۣ�"
                       "$n" HIY "ֻ��ͷ��Ŀѣ���������ʣ�\n" NOR;
}
        case 1:
                if (query("wtypeB") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeB") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeB") * 50);
                return query("name")+ CYN "�̹�һ����$N" CYN "�����ľ����������"
                       "ʹ$N" CYN "������õ��˻ָ���\n" NOR;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeC") * 30);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeC") * 30);
                victim->start_busy(3);
                return query("name")+ GRN "ˮ��һ����$N" GRN "����ɫ��һЩ"
                       "$n�е�һ����������ܶ����ˣ�\n" NOR;
}
        case 3:
                 if (query("wtypeD") >0)
{

                victim->receive_damage("qi", query("wtypeD") * 50);
                victim->receive_wound("qi", query("wtypeD") * 50);
                return query("name")+ RED "���һ����$n" RED "���һ�� ����"
                       "$n���������ˣ�\n" NOR;
}
        case 4:
                if (query("wtypeE") >0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )
                me->add("neili", query("wtypeE") * 60);
                return query("name")+ GRN "����һ����$N" GRN "����һů����Ԫ���ֵ��˲��١�\n" NOR;                                           
 }
        case 5:
                if (query("wtypeF") >0)
{
damage = 15 * query("wtypeF") ;
if (victim->query_temp("apply/dodge",1) >= 0)
		victim->add_temp("apply/dodge", -(8 * query("wtypeF")));
if (victim->query_temp("apply/defense",1) >= 0)
		victim->add_temp("apply/defense", -(8 * query("wtypeF")));
//if (victim->query_temp("apply/dodge",1) < 0) victim->set_temp("apply/dodge",0);
//if (victim->query_temp("apply/defense",1) < 0) victim->set_temp("apply/defense",0);

victim->start_busy(random(query("wtypeF")) + 1);
		if ((int)victim->query("qi")+10 > damage)
		victim->receive_wound("qi", damage);
                
                return query("name")+ HIM "����һ��磬�����ڿ��е�����֮���а�Χ��$n��$n" HIM "ֻ���粽���У�\n" NOR;
}
        case 6:
                if (query("wtypeG") >0)
{

			damage = 30 * query("wtypeG") ;
if ((int)victim->query("neili")+10 > (damage*30))
		victim->add("neili", -damage*30);
if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage);
                return query("name")+ HIW "����һ���ף�һ������������$n��$n" HIW "ֻ����ȫ����ʹ���飡\n" NOR;
}
        case 7:
                if (query("wtypeH") >0)
{
damage = 10 * query("wtypeH") ;
if (victim->query_temp("apply/attack",1) >= 0)
		victim->add_temp("apply/attack", -(8 * query("wtypeH")));
if (victim->query_temp("apply/parry",1) >= 0)
		victim->add_temp("apply/parry", -(8 * query("wtypeH")));
//if (victim->query_temp("apply/attack",1) < 0) victim->set_temp("apply/attack",0);
//if (victim->query_temp("apply/parry",1) < 0) victim->set_temp("apply/parry",0);

victim->start_busy(random(query("wtypeH")) + 1);
		if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage);
                return query("name")+ HIB "����һ��磬���һ��������$n��$n" HIB "ֻ��������ԣ�\n" NOR;

}
        case 8:
                if (query("wtypeI") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeI") * 20);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeI") * 20);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")  )
                me->add("eff_jing", query("wtypeI") * 20);
if( (int)me->query("jing") < (int)me->query("max_jing")  )
                me->add("jing", query("wtypeI") * 20);
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", query("wtypeI") * 30);
                return query("name")+ WHT "������յĹ���$N" WHT "ȫ����ɫ�����˱仯\n" NOR;

}
        case 9:
                if (query("wtypeJ") >0)
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
                return query("name")+ YEL "������صĹ��󣬻�ɫ������ӵ��ϳ��ְ�Χ��$n��$n" YEL "ֻ����Ѫһ��������\n" NOR;
}
        case 10:
                if (query("wtypeK") >0)
{

		if (objectp(weapon = victim->query_temp("weapon"))) {
			if (random(query("weapon_prop/damage")) > weapon->query("weapon_prop/damage") / 2
			&& random(me->query("str")) > victim->query("str") / 2
			&& random(6)==0) {
				victim->start_busy(random(query("wtypeK")) + 3);
					message_vision(HIW"ֻ�������ѡ���һ�����죬$N���е�" + weapon->query("name") + HIW"�Ѿ���" + query("name") + HIW"��Ϊ���أ�\n"NOR, victim);
					weapon->unequip();
					weapon->move(environment(victim));
					weapon->set("name", "�ϵ���" + weapon->query("name"));
					weapon->set("value", 0);
					weapon->set("weapon_prop", 0);
					victim->reset_action();
}
}

if( (int)victim->query("neili") >0  )
                victim->add("neili", -query("wtypeK") * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )
                me->add("neili", query("wtypeK") * 60);

                return query("name")+ HIC "�������������֮����$n" HIC "˫��һ��������ȫ�������������֮�������ˣ�\n" NOR;
}
        case 11:
                if (query("wtypeL") >0)
{

if( (int)victim->query("eff_qi") >0  )
                victim->add("eff_qi", -query("wtypeL") * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeL") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeL") * 50);


if( (int)victim->query("eff_jing") >0  )
                victim->add("eff_jing", -query("wtypeL") * 30);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeL") * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeL") * 30);                
return query("name")+ HIR "ħ��һ�֣�$n" HIR "ֻ������Ǻ��������ڶ����������Ƕ������˳�ȥ����\n" NOR;                                                                                                                                        
}


      case 12:
                if (query("wtypeC") >0 && (query("weapon_prop/strength") >0 && query("weapon_prop/neili") >0))
{
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )  me->add("neili", query("wtypeC") * 150);

msg1=query("name") + HIG"���һ�����ָ���"+me->query("name")+"������ ";

if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeC") * 200);
msg1=msg1+victim->query("name")+HIR"��������һ�������Ĺ⻪��"NOR;

if (query("wtypeA") >0 && ((int)victim->query("neili") <= (int)me->query("neili")))
{

if (victim->query_temp("apply/attack",1) >= 0)
		victim->add_temp("apply/attack", -(20 * query("wtypeA")));
if (victim->query_temp("apply/parry",1) >= 0)
		victim->add_temp("apply/parry", -(20 * query("wtypeA")));
if (victim->query_temp("apply/dodge",1) >= 0)
		victim->add_temp("apply/dodge", -(20 * query("wtypeA")));
if (victim->query_temp("apply/defense",1) >= 0)
		victim->add_temp("apply/defense", -(20 * query("wtypeA")));
//if (victim->query_temp("apply/attack",1) < 0) victim->set_temp("apply/attack",0);
//if (victim->query_temp("apply/parry",1) < 0) victim->set_temp("apply/parry",0);
//if (victim->query_temp("apply/dodge",1) < 0) victim->set_temp("apply/dodge",0);
//if (victim->query_temp("apply/defense",1) < 0) victim->set_temp("apply/defense",0);
	
	
msg1=msg1+ victim->query("name") + HIY"ͻȻ����һй��"NOR;
}
         
return query("name")+ HIG "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                        
}


      case 13:
                if (query("wtypeD") >0 && (query("weapon_prop/jing") >0 && query("weapon_prop/jingli") >0))
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeD") * 150);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeD") * 150);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeD") * 130);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeD") * 130);         
msg1=query("name") + HIG"���һ�����ָ���"+me->query("name")+"������ ";

if (random(10)==0 && !me->query_condition("killer") &&  !me->query_condition("psgc") && (int)victim->query("combat_exp",1) >= (int)me->query("combat_exp",1))
{	
me->clear_condition();
msg1=msg1+me->query("name")+HIR"���ϵĶ���,���Ƴ����⣡"NOR;
}

if (query("wtypeB") >0 && ((int)victim->query("combat_exp",1) <= (int)me->query("combat_exp",1)))
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
msg1=msg1+ victim->query("name") + HIY"ͻȻ���º�ɫѪҺ��\n"NOR;
}         
return query("name")+ RED "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                        
}

      case 14:
                if (query("wtypeI") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/percao") >0) && (string)victim->query("gender") != "Ů��")
{
if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeI") * 200);
msg1=msg1+victim->query("name")+HIR"��������һ����ɫ�������⻪��"NOR;

if (query("wtypeE") >0 && ((string)me->query("gender") == "Ů��"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeE") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeE") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeE") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeE") * 50);         
msg1=msg1+query("name") + HIG"��ɫ�����һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ WHT "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                              
}


      case 15:
                if (query("wtypeJ") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/constitution") >0)  && (string)victim->query("gender") != "����")
{
if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeJ") * 200);
msg1=msg1+victim->query("name")+HIR"��������һ����ɫ�������⻪��"NOR;


if (query("wtypeF") >0 && ((string)me->query("gender") == "����"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeF") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeF") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeF") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeF") * 50);         
msg1=msg1+query("name") + HIG"��ɫ�����һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ HIB "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                               
}


      case 16:
                if (query("wtypeK") >0 && (query("weapon_prop/dodge") >0 && query("weapon_prop/parry") >0)   && (int)victim->query("shen") < 0)
{

if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypek") * 200);
msg1=msg1+victim->query("name")+HIR"��������һ�������������⻪��"NOR;

if (query("wtypeG") >0 &&  (int)me->query("shen") > 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeG") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeG") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeG") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeG") * 50);         
msg1=msg1+query("name") + HIG"���������һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ HIC "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                             
}

      case 17:
                if (query("wtypeL") >0 && (query("weapon_prop/attack") >0 && query("weapon_prop/armor") >0)   && (int)victim->query("shen") > 0)
{
if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeL") * 200);
msg1=msg1+victim->query("name")+HIR"��������һ��а���������⻪��"NOR;



if (query("wtypeH") >0  &&  (int)me->query("shen") < 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeH") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeH") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeH") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeH") * 50);         
msg1=msg1+query("name") + HIG"а�������һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ HIG "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                            
}


        }
        
}        
        return damage_bonus;
}
