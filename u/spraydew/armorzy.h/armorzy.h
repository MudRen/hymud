int ob_hit(object ob, object me, int damage)
{
   int neili,a;
   int n,sharpness;
object weapon;
string msg1;
sharpness=query("sharpness");
msg1="";
//message_vision(HIW"ɱ��ֵ:"+damage+HIW"��\n"NOR, me,ob);
if (!sharpness) sharpness=0;
if (random(sharpness) > 1 && random(8)==0)
{

damage=damage-(sharpness*20);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", sharpness* 10);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", sharpness * 10);
if (damage <0) damage=0;
message_vision(CYN"$N���ϵ�"+query("name")+CYN"һ�����������⣬��ʱ��$n" CYN "�Ĺ��������˺ܶ࣡\n"NOR, me,ob);
 return damage;
}
else if (random(2)==0)
{
        switch (random(18) )
        {
        case 0:
                if (query("wtypeA") >0)
{
if(me->is_busy()) me->start_busy(1);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
{
me->add("eff_qi", query("wtypeA") * 20);
}
message_vision(HIY"$N���ϵ�"+query("name")+HIY"���һ����$N" HIY "��������Ѩ��һ���ͨ��\n"NOR, me,ob);
 return damage;
}
        case 1:
                if (query("wtypeB") >0)
{
if(!ob->is_busy()) ob->start_busy(query("wtypeB")+2);
message_vision(CYN"$N���ϵ�"+query("name")+CYN"�̹�һ����$n" CYN "����������ľ�����Ĺ���һ�����ж�һ�٣�\n"NOR, me,ob);
 return damage;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeC") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeC") * 50);
message_vision(GRN"$N���ϵ�"+query("name")+GRN"ˮ��һ����$N" GRN "�������õ��˻ֵã�\n"NOR, me,ob);
 return damage;
}
        case 3:
                if (query("wtypeD") >0)
{
                ob->receive_damage("qi", query("wtypeD") * 50);
                ob->receive_wound("qi", query("wtypeD") * 50);
message_vision(RED"$N���ϵ�"+query("name")+RED"���һ����$n" RED "���һ�� ����$n���������ˣ�\n"NOR, me,ob);
 return damage;
}
        case 4:
                if (query("wtypeE") >0)
{
                ob->add("neili",-(query("wtypeE")*80));
                if(!ob->is_busy()) ob->start_busy(2);
message_vision(YEL"$N���ϵ�"+query("name")+YEL"����һ����$n" RED "���һ�� �����᲻�����ˡ�\n"NOR, me,ob);
 return damage;
}
        case 5:
                if (query("wtypeF") >0)
{
damage=damage/query("wtypeF");
if (damage <0) damage=0;
me->add("neili",(query("wtypeF")*50));
message_vision(HIM"$N���ϵ�"+query("name")+HIM"����һ��磬$N" HIM "������Ȧ�籣��������\n"NOR, me,ob);
 return damage;
}

        case 6:
                if (query("wtypeG") >0)
{
if (ob->query_temp("apply/dodge",1) >= 0)
		ob->add_temp("apply/dodge", -(8 * query("wtypeG")));
if (ob->query_temp("apply/defense",1) >= 0)
		ob->add_temp("apply/defense", -(8 * query("wtypeG")));

//if (ob->query_temp("apply/dodge",1) < 0) ob->set_temp("apply/dodge",0);
//if (ob->query_temp("apply/defense",1) < 0) ob->set_temp("apply/defense",0);
		
		ob->start_busy(random(query("wtypeG")) + 2);
message_vision(HIW"$N���ϵ�"+query("name")+HIW"�׹�һ����$n" HIW "ֻ��������һɬ��\n"NOR, me,ob);
 return damage;
}
        case 7:
                if (query("wtypeH") >0)
{
if (me->query_temp("apply/dodge",1) <= (query("wtypeH")*6))
		me->add_temp("apply/dodge", (6 * query("wtypeH")));
if (me->query_temp("apply/defense",1) <= (query("wtypeH")*6))
		me->add_temp("apply/defense", (6 * query("wtypeH")));
message_vision(HIB"$N���ϵ�"+query("name")+HIB"���һ�֣�$N" HIB "�ķ����ٶȿ��˺ܶ࣡\n"NOR, me,ob);
 return damage;
}

        case 8:
                if (query("wtypeI") >0)
{
if (me->query_temp("apply/attack",1) <= (query("wtypeI")*6))
		me->add_temp("apply/attack", (6 * query("wtypeI")));
if (me->query_temp("apply/damage",1) <= (query("wtypeI")*6))
		me->add_temp("apply/damage", (6 * query("wtypeI")));
message_vision(WHT"$N���ϵ�"+query("name")+WHT"������յĹ���$N" WHT "�Ĺ����ٶȿ��˺ܶ࣡\n"NOR, me,ob);
 return damage;
}


        case 9:
                if (query("wtypeJ") >0)
{
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
message_vision(YEL"$N���ϵ�"+query("name")+YEL"������صĹ��󣬷���һ���ɫ������$n" YEL "ֻ����Ѫһ��������\n"NOR, me,ob);
 return damage;
}
        case 10:
                 if (query("wtypeK") >0)
{

//if( (int)ob->query("neili") >0  )
//               ob->add("neili", -query("wtypeK") * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )
                me->add("neili", query("wtypeK") * 60);
message_vision(HIC"$N���ϵ�"+query("name")+HIC"�������������֮���������õ��˻ָ���\n"NOR, me,ob);
 return damage;
}

        case 11:
                if (query("wtypeL") >0)
{

//if( (int)ob->query("eff_qi") >0  )
//                ob->add("eff_qi", -query("wtypeL") * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeL") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeL") * 50);


//if( (int)ob->query("eff_jing") >0  )
                //ob->add("eff_jing", -query("wtypeL") * 30);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeL") * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeL") * 30);                
message_vision(HIR"$N���ϵ�"+query("name")+HIR"ħ��һ�֣����������õ��˻ָ�����\n"NOR, me,ob);
 return damage;
                                                                                                                         
}


      case 12:
                if (query("wtypeA") >0 && (query("armor_prop/intelligence") >0 && query("armor_prop/karey") >0))
{
if (random(3)==0)
{
	me->add("combat_exp", random(query("wtypeA",1))+1);
msg1=query("name") + HIG"���һ����"+me->query("name")+"��ʵս����õ������� "NOR;
}
if (query("wtypeC") >0 && ((int)ob->query("combat_exp",1) >= (int)me->query("combat_exp",1)))
{
//ob->start_busy(query("wtypeC") + 2);
//ob->apply_condition(du[random(sizeof(du))], query("wtypeC")*3);
//msg1=msg1+ob->query("name")+HIY"��������һ�����ҵĻ�ɫ���"NOR;
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )  me->add("neili", query("wtypeC") * 80);
msg1=msg1+me->query("name")+HIY"��������һ��ˮɫ�Ĺ�â��"NOR;
}         
message_vision(query("name")+ HIY "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}


      case 13:
                if (query("wtypeB") >0 && (query("armor_prop/karey") >0 && query("armor_prop/percao") >0))
{
if (random(3)==0)
{
me->add("potential", random(query("wtypeB",1))+1);
msg1=query("name") + HIG"���һ����"+me->query("name")+"��Ǳ�ܵõ������� "NOR;
}
if (query("wtypeD") >0 && ((int)ob->query("combat_exp",1) <= (int)me->query("combat_exp",1)))
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeD") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeD") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeD") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeD") * 50);         
msg1=msg1+me->query("name")+RED"��������һ�����ɫ�������Ĺ�â��"NOR;


//ob->start_busy(query("wtypeD") + 2);
//ob->apply_condition(du[random(sizeof(du))], query("wtypeD")*3);
//msg1=msg1+ob->query("name")+RED"��������һ�����ҵĻ��ɫ���"NOR;

}         
message_vision(query("name")+ CYN "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

      case 14:

                if (query("wtypeE") >0 && (query("armor_prop/defense") >0 && query("armor_prop/neili") >0)  && (int)me->query("shen") > 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeE") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeE") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeE") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeE") * 50);         
msg1=msg1+me->query("name")+YEL"��������һ����ص������Ĺ�â��"NOR;
if (query("wtypeI") >0  && (int)ob->query("shen") < 0)
{
ob->start_busy(query("wtypeI") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeI")*3);
msg1=msg1+ob->query("name")+WHT"��������һ������������"NOR;

}         
message_vision(query("name")+ YEL "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

      case 15:
                if (query("wtypeF") >0 && (query("armor_prop/jing") >0 && query("armor_prop/damage") >0)  && (int)me->query("shen") < 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeF") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeF") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeF") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeF") * 50);         
msg1=msg1+me->query("name")+HIM"��������һ����ˬ��΢�磡"NOR;

if (query("wtypeJ") >0  && (int)ob->query("shen") > 0)
{
ob->start_busy(query("wtypeJ") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
msg1=msg1+ob->query("name")+HIY"��������һ������������"NOR;

}         
message_vision(query("name")+ HIM "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR, me,ob);
return damage;
}

      case 16:
                if (query("wtypeG") >0 && (query("armor_prop/damage") >0 && query("armor_prop/jingli") >0) && (string)me->query("gender") != "Ů��")
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeG") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeG") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeG") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeG") * 50);         
msg1=msg1+me->query("name")+HIW"��������һ�����׵Ĺ�â��"NOR;
if (query("wtypeK") >0 && (string)ob->query("gender") != "����")
{
ob->start_busy(query("wtypeK") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeK")*3);
msg1=msg1+ob->query("name")+RED"��������һ������������"NOR;

}         
message_vision(query("name")+ HIC "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

      case 17:
                if (query("wtypeH") >0 && (query("armor_prop/armor") >0 && query("armor_prop/defense") >0) && (string)me->query("gender") != "����")
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeH") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeH") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeH") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeH") * 50);   
msg1=msg1+me->query("name")+HIB"��������һ������Ĺ�â��"NOR;
if (query("wtypeL") >0  && (string)ob->query("gender") != "Ů��")
{
ob->start_busy(query("wtypeL") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeL")*3);
msg1=msg1+ob->query("name")+HIR"��������һ��ħ��������"NOR;

}         
message_vision(query("name")+ HIB "ͨ��һ��������������ɫ��â�������:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

       }
}

  return damage;
}