mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n,sharpness,damage;
object weapon;
string msg1,msg2,msg3;
sharpness=query("sharpness");
if (!sharpness) sharpness=0;
msg1="";
if (random(sharpness) > 1 && random(9)==0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", (sharpness*2) * 10);

                victim->receive_damage("qi", (sharpness*2) * 10,me);
                victim->receive_wound("qi", (sharpness*2) * 10,me);
                return RED "$N" HIY "����"+query("name")+RED"һ�����������⣬��ʱ��$n"
                       RED "���ˣ���Ѫ˳��$n����ֱ��������\n" NOR;
}
else if (random(6)==0)
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
                me->add("eff_qi", (query("wtypeB")*2) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", (query("wtypeB")*2) * 50);
                return query("name")+ CYN "�̹�һ����$N" CYN "�����ľ����������"
                       "ʹ$N" CYN "������õ��˻ָ���\n" NOR;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", (query("wtypeC")*2) * 30);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", (query("wtypeC")*2) * 30);
                victim->start_busy(3);
                return query("name")+ GRN "ˮ��һ����$N" GRN "����ɫ��һЩ"
                       "$n�е�һ����������ܶ����ˣ�\n" NOR;
}
        case 3:
                 if (query("wtypeD") >0)
{

                victim->receive_damage("qi", (query("wtypeD")*2) * 50,me);
                victim->receive_wound("qi", (query("wtypeD")*2) * 50,me);
                return query("name")+ RED "���һ����$n" RED "���һ�� ����"
                       "$n���������ˣ�\n" NOR;
}
        case 4:
                if (query("wtypeE") >0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )
                me->add("neili", (query("wtypeE")*2) * 60);
                return query("name")+ GRN "����һ����$N" GRN "����һů����Ԫ���ֵ��˲��١�\n" NOR;                                           
 }
        case 5:
                if (query("wtypeF") >0)
{
damage = 15 * (query("wtypeF")*2) ;
if (victim->query_temp("apply/dodge",1) >= 0)
		victim->add_temp("apply/dodge", -(8 * query("wtypeF")));
if (victim->query_temp("apply/defense",1) >= 0)
		victim->add_temp("apply/defense", -(8 * query("wtypeF")));
//if (victim->query_temp("apply/dodge",1) < 0) victim->set_temp("apply/dodge",0);
//if (victim->query_temp("apply/defense",1) < 0) victim->set_temp("apply/defense",0);

victim->start_busy(random(query("wtypeF")) + 1);
		if ((int)victim->query("qi")+10 > damage)
		victim->receive_wound("qi", damage,me);
                
                return query("name")+ HIM "����һ��磬�����ڿ��е�����֮���а�Χ��$n��$n" HIM "ֻ���粽���У�\n" NOR;
}
        case 6:
                if (query("wtypeG") >0)
{

			damage = 30 * (query("wtypeG")*2) ;
if ((int)victim->query("neili")+10 > (damage*30))
		victim->add("neili", -damage*30);
if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage,me);
                return query("name")+ HIW "����һ���ף�һ������������$n��$n" HIW "ֻ����ȫ����ʹ���飡\n" NOR;
}
        case 7:
                if (query("wtypeH") >0)
{
damage = 10 * (query("wtypeH")*2) ;
if (victim->query_temp("apply/attack",1) >= 0)
		victim->add_temp("apply/attack", -(8 * query("wtypeH")));
if (victim->query_temp("apply/parry",1) >= 0)
		victim->add_temp("apply/parry", -(8 * query("wtypeH")));
//if (victim->query_temp("apply/attack",1) < 0) victim->set_temp("apply/attack",0);
//if (victim->query_temp("apply/parry",1) < 0) victim->set_temp("apply/parry",0);

victim->start_busy(random(query("wtypeH")) + 1);
		if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage,me);
                return query("name")+ HIB "����һ��磬���һ��������$n��$n" HIB "ֻ��������ԣ�\n" NOR;

}
        case 8:
                if (query("wtypeI") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", (query("wtypeI")*2) * 20);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", (query("wtypeI")*2) * 20);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")  )
                me->add("eff_jing", (query("wtypeI")*2) * 20);
if( (int)me->query("jing") < (int)me->query("max_jing")  )
                me->add("jing", (query("wtypeI")*2) * 20);
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", (query("wtypeI")*2) * 30);
                return query("name")+ WHT "������յĹ���$N" WHT "ȫ����ɫ�����˱仯\n" NOR;

}
        case 9:
                if (query("wtypeJ") >0)
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*2);
                return query("name")+ YEL "������صĹ��󣬻�ɫ������ӵ��ϳ��ְ�Χ��$n��$n" YEL "ֻ����Ѫһ��������\n" NOR;
}
        case 10:
                if (query("wtypeK") >0)
{

		if (objectp(weapon = victim->query_temp("weapon"))) {
			if (random(query("weapon_prop/damage")) > weapon->query("weapon_prop/damage") / 2
			&& random(me->query("str")) > victim->query("str") / 2
			&& random(6)==0) {
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
				victim->start_busy(random(query("wtypeK")) + 3);
					message_vision(HIW"ֻ�������ѡ���һ�����죬$N���е�" + weapon->query("name") + HIW"�Ѿ���" + query("name") + HIW"��Ϊ���أ�\n"NOR, victim);
					weapon->unequip();
					weapon->move(environment(victim));
					weapon->set("name", "�ϵ���" + weapon->query("name"));
					weapon->set("value", 0);
					weapon->set("weapon_prop", 0);
					victim->reset_action();
}
else
{
victim->receive_wound("qi", (query("wtypeK")) * 20,me);	
}
}
}

if( (int)victim->query("neili") >0  )
                victim->add("neili", -(query("wtypeK")*2) * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )
                me->add("neili", (query("wtypeK")*2) * 60);

                return query("name")+ HIC "�������������֮����$n" HIC "˫��һ��������ȫ�������������֮�������ˣ�\n" NOR;
}
        case 11:
                if (query("wtypeL") >0)
{

if( (int)victim->query("eff_qi") >0  )
                victim->add("eff_qi", -(query("wtypeL")*2) * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", (query("wtypeL")*2) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", (query("wtypeL")*2) * 50);


if( (int)victim->query("eff_jing") >0  )
	victim->receive_wound("jing", -(query("wtypeL")*2) * 30,me);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", (query("wtypeL")*2) * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", (query("wtypeL")*2) * 30);                
return query("name")+ HIR "ħ��һ�֣�$n" HIR "ֻ������Ǻ��������ڶ����������Ƕ������˳�ȥ����\n" NOR;                                                                                                                                        
}


      case 12:
                if (query("wtypeC") >0 && (query("weapon_prop/strength") >0 && query("weapon_prop/neili") >0))
{
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )  me->add("neili", (query("wtypeC")*2) * 150);

msg1=query("name") + HIG"���һ�����ָ���"+me->query("name")+"������ ";

if( (int)victim->query("eff_qi") >0  )
victim->receive_wound("jing", -(query("wtypeC")*2) * 200,me);
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
                me->add("eff_qi", (query("wtypeD")*2) * 150);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", (query("wtypeD")*2) * 150);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", (query("wtypeD")*2) * 130);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", (query("wtypeD")*2) * 130);         
msg1=query("name") + HIG"���һ�����ָ���"+me->query("name")+"������ ";

if (random(10)==0 && !me->query_condition("killer") &&  !me->query_condition("psgc") && (int)victim->query("combat_exp",1) >= (int)me->query("combat_exp",1))
{	
if (!me->query_condition("huaiyun") && !me->query_condition("wudang_guard") && !me->query_condition("mptjob") && !me->query_condition("mjtjob") && !me->query_condition("mp2_kill") && !me->query_condition("guanfu_task") && !me->query_condition("wudu_xunshan")  && !me->query_condition("hu_song")  && !me->query_condition("xhquest")  && !me->query_condition("qztjob")  && !me->query_condition("xsjob")  && !me->query_condition("menggusong")  && !me->query_condition("shaolin_song")  && !me->query_condition("lingjiu_song")  && !me->query_condition("lyjob")  && !me->query_condition("killme")  && !me->query_condition("riyue_guard"))
{
me->clear_condition("anqi_poison");
me->clear_condition("baituo_poison");
me->clear_condition("bat");
me->clear_condition("bing_poison");
me->clear_condition("binghuo");
me->clear_condition("black_poison");
me->clear_condition("broken_arm");
me->clear_condition("canxia");
me->clear_condition("chanchu_poison");
me->clear_condition("chilian_poison");
me->clear_condition("cold_poison");
me->clear_condition("corpse_poison");
me->clear_condition("cuixin_zhang");
me->clear_condition("dashouyin");
me->clear_condition("dragon_poison");
me->clear_condition("emerald_poison");
me->clear_condition("fire_poison");
me->clear_condition("flower_poison");
me->clear_condition("green_blood");
me->clear_condition("hehe");
me->clear_condition("hot_poison");
me->clear_condition("huanyin_poison");
me->clear_condition("ice_poison");
me->clear_condition("iceshock");
me->clear_condition("ill_dongshang");
me->clear_condition("ill_fashao");
me->clear_condition("ill_keshou");
me->clear_condition("ill_kesou");
me->clear_condition("ill_shanghan");
me->clear_condition("ill_zhongshu");
me->clear_condition("insect_poison");
me->clear_condition("juehu_hurt");
me->clear_condition("jy-poison");
me->clear_condition("jy_poison");
me->clear_condition("libie");
me->clear_condition("new_poison1");
me->clear_condition("new_poison2");
me->clear_condition("new_poison3");
me->clear_condition("new_poison4");
me->clear_condition("new_poison5");
me->clear_condition("new_poison6");
me->clear_condition("new_poison7");
me->clear_condition("new_poison8");
me->clear_condition("no_shadow");
me->clear_condition("nx_poison");
me->clear_condition("poison");
me->clear_condition("poison_sandu");
me->clear_condition("qiankun_wound");
me->clear_condition("qiankunyibang");
me->clear_condition("qinghua_poison");
me->clear_condition("qishang_poison");
me->clear_condition("qx_snake_poison");
me->clear_condition("rose_poison");
me->clear_condition("sanpoison");
me->clear_condition("sanxiao_poison");
me->clear_condition("scorpion_poison");
me->clear_condition("shenlong_poison");
me->clear_condition("shenzhao");
me->clear_condition("sl_poison");
me->clear_condition("snake_poison");
me->clear_condition("ss_poison");
me->clear_condition("tiezhang_yang");
me->clear_condition("tiezhang_yin");
me->clear_condition("tmpili_poison");
me->clear_condition("tmqidu_poison");
me->clear_condition("tmzhuihun_poison");
me->clear_condition("unknown");
me->clear_condition("wudoumi-fanshi");
me->clear_condition("wugong_poison");
me->clear_condition("wuhudu_poison");
me->clear_condition("wuxing_poison");
me->clear_condition("x2_poison");
me->clear_condition("x2_sandu");
me->clear_condition("xiezi_poison");
me->clear_condition("xscold_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuantian_han");
me->clear_condition("xx_condition");
me->clear_condition("xx_liandu");
me->clear_condition("xx_poison");
me->clear_condition("xx_sandu");
me->clear_condition("yf_poison");
me->clear_condition("yufeng_poison");
me->clear_condition("yyz_damage");
me->clear_condition("zhizhu_poison");
me->clear_condition("zhua_poison");
me->clear_condition("zimu-zhen");
me->clear_condition("zm_poison");
me->clear_condition("zmqidu_poison");

msg1=msg1+me->query("name")+HIR"���ϵĶ���,���Ƴ����⣡"NOR;
}
}

if (query("wtypeB") >0 && ((int)victim->query("combat_exp",1) <= (int)me->query("combat_exp",1)))
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*2);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*2);
msg1=msg1+ victim->query("name") + HIY"ͻȻ���º�ɫѪҺ��\n"NOR;
}         
return query("name")+ RED "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                        
}

      case 14:
                if (query("wtypeI") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/percao") >0) && (string)victim->query("gender") != "Ů��")
{
if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeI")*2) * 200,me);
msg1=msg1+victim->query("name")+HIR"��������һ����ɫ�������⻪��"NOR;

if (query("wtypeE") >0 && ((string)me->query("gender") == "Ů��"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeE")*2) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeE")*2) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeE")*2) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeE")*2) * 50);         
msg1=msg1+query("name") + HIG"��ɫ�����һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ WHT "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                              
}


      case 15:
                if (query("wtypeJ") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/constitution") >0)  && (string)victim->query("gender") != "����")
{
if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeJ")*2) * 200,me);
msg1=msg1+victim->query("name")+HIR"��������һ����ɫ�������⻪��"NOR;


if (query("wtypeF") >0 && ((string)me->query("gender") == "����"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeF")*2) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeF")*2) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeF")*2) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeF")*2) * 50);         
msg1=msg1+query("name") + HIG"��ɫ�����һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ HIB "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                               
}


      case 16:
                if (query("wtypeK") >0 && (query("weapon_prop/dodge") >0 && query("weapon_prop/parry") >0)   && (int)victim->query("shen") < 0)
{

if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeK")*2) * 200,me);
msg1=msg1+victim->query("name")+HIR"��������һ�������������⻪��"NOR;

if (query("wtypeG") >0 &&  (int)me->query("shen") > 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeG")*2) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeG")*2) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeG")*2) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeG")*2) * 50);         
msg1=msg1+query("name") + HIG"���������һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ HIC "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                             
}

      case 17:
                if (query("wtypeL") >0 && (query("weapon_prop/attack") >0 && query("weapon_prop/armor") >0)   && (int)victim->query("shen") > 0)
{
if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeL")*2) * 200,me);
msg1=msg1+victim->query("name")+HIR"��������һ��а���������⻪��"NOR;



if (query("wtypeH") >0  &&  (int)me->query("shen") < 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeH")*2) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeH")*2) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeH")*2) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeH")*2) * 50);         
msg1=msg1+query("name") + HIG"а�������һ�����ָ���"+me->query("name")+"������ ";

}         
return query("name")+ HIG "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR;                                                                                                                                                            
}


        }
        
}        
        return damage_bonus;
}