//sanban, �޵�����
//created 6-10-97 pickle
 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg,targetrude;
        object weapon;
        int success,hurt,diff,damage;
        int myexp=(int)me->query("combat_exp")/5000;
        int mylev=(int)me->query_skill("hammer");
        int mystr=(int)me->query("str")+(int)(me->query_skill("unarmed")/10-2);
        int mykar=(int)me->query_kar();
        int targetlev, targetstr,targetkar,targetexp,targeteffkee;
        int myskill;
                object *inv, obj, obj1;
        int mypot,tapot;
        string str;
        int i, temp_dodge,temp_spells;
        
        string *hitone = ({
        "$n��ͼ����ܿ�����Ϊʱ���������ڼ��ϣ�����һ����ɼ��ǵ��˿ڣ�\n",
        "$n�߾����б�����ͼ�ܿ���������ס$N�����ƣ�������³�һ����Ѫ��\n",
        "$n�Թ�Ϊ�أ���ȥ�Ʋ�����������Ƶ�$N�ش��Ի�����������$n������һ���˿ڡ�\n",
        });
        string *missone = ({
        "$n����һ�����󴸴���һ�󾢷�����ն�£���û�˵�$n�ֺ���\n",
        "$n�߾����б��з���һ�ܣ�ֻ����������һ�����죬$N�޴��ѱ�������\n",
        "$n���˴����ƣ�������$N�������Ƶ�$N���ò��ش��Ա�����һ�ơ����ϡ��ʹ���ա�\n",
        });
        string *hittwo = ({
        "$n�ƺ�û�о���Σ�գ�˳��һ����������������֮����Ϊʱ���������Ѷ���һ�����糤���˿ڣ�\n",
        "$nû���$N�������֮�죬��æ��ͷ���ܣ����޷��㿪�������л���Ƥ��������\n",
        "$n������Ȼ�������������ط������ϱ����һƬƤ����Ȼ�˵ò��ᣡ\n",
        });
        string *misstwo = ({
        "$n�Դ�΢΢һ�࣬�ܹ���$N�Ĺ��ơ�\n",
        "$n�ƺ������ϵ���һ�У�˳���ڴ�����һ�ƣ����˿�ȥ��\n",
        "�ۿ�����Ҫ��$n�Դ������Դ���ͻȻ��$nʹ�������ţ����ֵ����˸��ա�\n",
        });
        string *hitthree = ({
        "$n�ƺ��ѱ����������������������˵�������ɢɢ��һ�ᣬ���󴸺����ڼ�ͷ��\n",
        "$n��׼���ƣ������б�����ȥ�������������ģ�����ͷ��û��ڳ�Ѫ����Ȼ���˲��ᣡ\n",
        "$n�ۼ�������������ͼ��ͷ�ܹ��������ϴ�������������$n���ϸ���һ��ƬƤ�⣡\n",
        });
        string *missthree = ({
        "$n�ƺ�������֪����·����δ������������ƮƮ�رܿ��ˡ�\n",
        "$n�ۼ��㲻�����У���æ�ڵ���һ������Ȼ�ܵ��Ǳ�����˿��û�����ˡ�\n",
        "$n��������Σ�գ��й�ֱ������$N��ȥ����Ȼ�����л����ˡ�\n",
        });
        string *hit=({
        RED"$N����Ҳ���㳢�����޵����񴸵�������\n"NOR,
        RED"���޵�����һ���ǳɣ�$n�����˸����ֲ�����������Ϊ���£�\n"NOR,
        RED"$N��Ц������ƾ����㱾�£�Ҳ�����Ҷ���\n"NOR,
        });
        string *miss;
  
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�޵����񴸲������źÿ��ģ�ֻ�ܶ�ս������ʩ�á�\n");
        targetrude=RANK_D->query_self_rude(target);
        targetexp=(int)target->query("combat_exp")/5000;
        targetlev=(int)target->query_skill("parry");
        targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
        targetkar=(int)target->query_kar();
        myskill=(int)me->query_skill("frht-hammer",1);
        
        miss=({
        BLU"$n������Ц����"+targetrude+"��˵���޵������ж�������������һ����Ҳ��������\n"NOR,
        BLU"$n��Цһ������$N��м��˵��������㱾�£�"+targetrude+"��û�������\n"NOR,
        BLU"$n�����Ц��������ʲô���£������ó����ɣ�\n"NOR,
        });

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("��ʹ����ڤ����!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 200)
                return notify_fail("�����ڤ����������������\n"); 

       if(me->query("jing")<500)
                return notify_fail("��ľ������㣬��������Ӷ�һ���󴸡�\n");


        if(me->query_skill("frht-hammer",1)<100)
                return notify_fail("��������书������Ϥ���޷�һ���ǳɵ�ʹ����\n");
        if(me->query("max_neili") < 1000 || me->query("neili")<500)
                return notify_fail("����������㣬��������Ӷ�һ���󴸡�\n");
        msg = CYN "$Nһ�����ȣ����ϣ��������Ͷ��䣡����һ���ǳɣ�\n\nֻ��һ����Ӱ��������ֱ��$n���ţ�\n" NOR;
        if( random(mylev+targetlev+mystr*3+targetstr*3) > (targetlev+targetstr*3))
        {
                msg += hitone[random(sizeof(hitone))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage=15+random(mykar/3);
        }
        else msg+=missone[random(sizeof(missone))];
        msg+=CYN"\n$N���Ѿ�������˳���Դ�β���ּ⵶����$n���ţ�\n"NOR;
        if( random(myexp+targetexp+mylev+targetlev) > (targetexp+targetlev))
        {
                msg += hittwo[random(sizeof(hittwo))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage+=15+random(mykar/3);
        }
        else msg+=misstwo[random(sizeof(misstwo))];
        msg+=CYN"\n$NѸ�����׵ط�ת��ͷ������$n�Դ�������ȥ��\n"NOR;
        if(random(myexp+targetexp+mykar*10+targetkar*10)>(targetexp+targetkar))
        {
                msg+=hitthree[random(sizeof(hitthree))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage+=15+random(mykar/3);
        }
        else msg+=missthree[random(sizeof(missthree))];
        diff=3-success;
        if (diff<0) diff = 0;
        if (success) hurt=damage*hurt/success;
        else hurt=0;
        me->add("neili", -(50*success));
        targeteffkee=(int)target->query("eff_qi",1);
        if (targeteffkee> 18000) targeteffkee=18000;
        
        target->receive_wound("qi", targeteffkee*hurt/100,me);
        target->receive_damage("qi", targeteffkee*(damage-hurt)/100,me);
        if(success)
        {
                //me->start_busy(2);
                msg+=hit[random(sizeof(hit))];
        }       
        else
        {
                //me->start_busy(3);
                msg+=miss[random(sizeof(miss))];
        }
        message_vision(msg, me, target);
        if(success && me->query_temp("jjftop") && living(target))
        {
                target->receive_damage("qi", targeteffkee*(damage-hurt)/40,me);
                msg=HIG"$N�е��������࣬���а崸˳�ƻذ⣬һ������$n��\n$n��ʱ������Ѫ��ģ���������ڵ��ϣ�\n";
                message_vision(msg, me, target);
        }
 
 if (myskill> 500 || !userp(me))
{
    message_vision(HIC"\n$N���㾫�񣬴��һ��������$n������ȫ��һ����\n"NOR, me, target);

        mypot=(int)me->query_skill("hammer",1);
        mypot=mypot*mypot*mypot/2 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry",1);
        tapot=tapot+(int)target->query_skill("dodge",1)/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

//      write("mypot " + mypot + ", tapot " +tapot+ "\n");

        if( random( mypot+tapot )/1000 > tapot/1000 ) 
        {

                inv = all_inventory(target);
                i = sizeof(inv);

                if ( i < 1 ) 
                {
                        message_vision(HIR"$N������������������ţ�\n"NOR, target);
                        damage = 100+(int)me->query("jiali")
                        + (int)me->query_skill("hammer",1) + (int)me->query_skill("frht-hammer",1);
                        target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage,me);

                        COMBAT_D->report_status(target);
                } 
                else 
                {
                        if(target->query_temp("armor")||target->query_temp("weapon")) 
                        {
                                if( target->query_temp("armor") ) 
                                {
                                        for (i=1; i < sizeof(inv); i++ ) 
                                        {
                                                obj = inv[i];
if (!obj->query("systemmake") && !obj->query("ownmake"))
{
                                                if( obj->query("equipped") != "worn" ) continue;
                                                obj->delete("equipped");
                                                obj->set("value", 0);
                                                //obj->set("No_Wear", 1);
                                                message_vision(HIY"$N���ϵ�$n����ķ��飡\n"NOR, target,obj);
                                                temp_dodge=(int)obj->query("armor_prop/dodge",1);
                                                temp_spells=(int)obj->query("armor_prop/armor",1);
                                                if (temp_dodge)
                                                target->add_temp("apply/dodge",-temp_dodge);
                                                if (temp_spells)
                                                target->add_temp("apply/armor",-temp_spells);
                                                                                                
                                                obj->set("name", "�����"+obj->query("name"));
}
                                        }
                                }
                                if (target->query_temp("weapon")) 
                                {
                                	
                                        obj=target->query_temp("weapon");
if (!obj->query("systemmake") && !obj->query("ownmake"))
{
                                        obj->unequip();
                                        obj->set("value", 0);
                                        message_vision(HIW "ֻ������ž����һ����$N���е�" + obj->name()+ "�Ѿ���Ϊ���أ�\n" NOR, target);
                                        obj->set("name", "�ϵ���" + obj->query("name"));
                                        obj->set("weapon_prop", 0);
                                        obj->set("armor_prop", 0);                                                              
                                        //obj->move(environment(target));
                                       // call_out("remove_broken_cloth",random(300)+60,obj);
}
                                target->receive_damage("qi",(int)me->query_skill("frht-hammer",1),me); 
                                target->receive_wound("qi",(int)me->query_skill("frht-hammer",1),me); 
                                }
//                        target->delete_temp("armor");
//                        target->delete_temp("apply");
                        } 
                        else 
                        {
                                message_vision(HIR"$N������������������ţ�\n"NOR, target);
                           
                        damage = (int)me->query("jiali") 
                        + (int)me->query_skill("hammer",1) + (int)me->query_skill("frht-hammer",1);
                                target->receive_damage("qi",damage,me); 
                                target->receive_wound("qi",damage,me); 
                               
                                COMBAT_D->report_status(target); 
                        }
                }
        } 
        else 
        {
                message_vision(HIC"ȴ��$N�㿪�ˣ�\n"NOR, target);
        }

        me->add("neili", -50);
        me->receive_damage("jing", 50);
 
} 


if (myskill> 800)
{
	     message_vision(HIY"\n$N��ָ$n�ߺ޵��������Ҳ��ʶ���С�����ԡ���һ��˵�գ�$N���˵���������ģ�ʹ�������츲�ء���\n\n"NOR,me,target);
                
        mypot=(int)me->query_skill("frht-hamer");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot || !living(target) ) 
{       
        
         message_vision(HIR"ֻ��$nӲ�����Ľ�ס$N�⼼���У��ٸк�ͷһ��[��]��һ���³�һ����Ѫ��\n\n"NOR,me, target);  
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("qi",(random(me->query_skill("hammer")*3/2)+ (int)me->query_skill("frht-hammer",1)),me);
         COMBAT_D->report_status(target);
                
         if (target->query("eff_qi")< -100 || !living(target))  
 {str=target->name()+"��"+me->name()+"�ġ����츲�ء����������Ƕ��޴�Ѱ�١�";
         CHANNEL_D->do_channel(me, "rumor",str);
         me->delete_temp("last_channel_msg");}
        else {if ( random(2)==0 )
              message_vision(HIR"$N����$n���˲��ᣬ��ʤ׷�����ֳ�һ�������Ƹ��ꡱ��$n���߻�������������һ�롣\n"NOR,me,target);
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("qi",(random(me->query_skill("parry")*3/2)+ (int)me->query_skill("frht-hammer",1)),me);
         COMBAT_D->report_status(target);
              target->start_busy(2);
             }
          
}        
     
         else  {message_vision(HIC"$Nʶ�ƴ��У����˵����������Ӳ�Ӵ˾��У�\n"NOR, target);
                me->start_busy(2);
               }
               
        me->add("neili", -50);
        me->receive_damage("jing", 50);
	
	
}		
	


        me->start_busy(3);
        
        return 1;
}

