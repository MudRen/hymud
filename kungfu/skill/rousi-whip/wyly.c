//modified by longer

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int calculate_damage(object me, object target, int base_damage, int damge_bonus);

int perform(object me, object target)
{
        object weapon;
        int i,j;
                string msg;
                int damage;
                        int wound,k,damage_bonus,mystr;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「五韵连音」？\n");


if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("请使用白云心法!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("你的白云心法还不够。。。\n"); 
        


        if(!me->is_fighting())
                return notify_fail("「五韵连音」只能在战斗中使用！\n");

        if((int)me->query("neili") < 600 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("qi") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("rousi-whip", 1) < 150)
                return notify_fail("你的柔丝乐鞭级别还不够，无法领会五韵精髓！\n");

               weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
        }

        me->delete("env/brief_message");
        target->delete("env/brief_message");
				        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 1900);
        msg=HIY"$N双手急速挥舞柔丝乐鞭，竟发出隐藏着宇宙最神奇力量的五韵之声"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIW"☆宫☆"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIW"☆商☆"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIR"☆角☆"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIB"☆徵☆"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIM"☆羽☆"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIM"☆五韵合一☆"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
				        		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -1900);
                if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);


if ((int)me->query_skill("rousi-whip",1)> 360)
{
message_vision(HIW"$N看着遍地含苞待放的花朵，情到一处油然而生，顺口吟道："+HIR""BLINK"≈≈花变≈≈"NOR""+HIW"吾心不变......\n"NOR,me,target);
message_vision(HIG"            “人间花开，春去天涯，红药万株，天然浩态狂香”。\n"NOR,me,target);
message_vision(HIG"            “尊贵御衣，独占花王，困倚凝香，用花千万余枝”。\n"NOR,me,target);
message_vision(HIG"            “人诧奇芳，结蕊当屏，怜葩就幄，红掩绿绕华堂”。\n"NOR,me,target);
message_vision(HIG"            “秉兰观雨，花面交相，幽意难忘，罢酒风亭梦魂”。\n"NOR,me,target);
message_vision(HIC"“天香染露，最忆当年，无限春风恨，夜深花睡冷香，多情芳心轻吐，问："+HIR"‘世间情为何物’"+HIC"”\n"NOR,me,target);
        
        damage=300+(int)me->query_skill("rousi-whip")+random((int)me->query_skill("whip"));
        if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIW"$n眼前遍地花草争奇斗艳，被这如此出奇美景早已迷的心乱如麻，顿感心力交瘁。\n"NOR,me,target);
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                target->receive_damage("jing",damage);
                target->receive_wound("jing",damage/2);
                target->start_busy(2);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n心平气和，盘膝而座，怀中掏出玉酿美酒，合着此情此景独自享用起来。\n"NOR,me,target);
        }
        me->receive_damage("jing", 50);
        me->add("neili", -100);
	
	
}	


if ((int)me->query_skill("rousi-whip",1)> 800)
{
	        mystr=me->query_str() * 2;

              k=(int)me->query_skill("whip");
              damage_bonus=k;
              damage_bonus=mystr*(damage_bonus+100+me->query("jiali"))/209;
        message_vision(HIY"$N满心伤痕，痛不欲生，哭道：你真没良心，我跟你拼了! 说罢扑向$n，早已忘了自己的生死!\n"NOR,me,target);
                     
                        if (random((int)me->query("per"))<10 || random((int)target->query("combat_exp")) > ((int)me->query("combat_exp"))) 
                                                  {

        message_vision(HIB"可是$p看到了$P哭泣背后的企图，笑道:我本来就无情无义，你能如何！\n"NOR,me,target);

                                }
                                 else {
			msg="";
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃绝┃\n";
			msg +=HIB "   ┗━┛\n";
               		damage=calculate_damage(me, target, 20, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("qi", damage);
                                 msg+=WHT"结果$n"WHT"心中一动，呆呆的看着$N。\n" NOR;
                    			}
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃情┃\n";
			msg +=HIB "   ┗━┛\n";
               		damage=calculate_damage(me, target, 40, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_wound("qi", damage);
                                msg+=WHT"结果$n"WHT"想起你的情，低下了头。\n" NOR;
                    			}
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃绝┃\n";
			msg +=HIB "   ┗━┛\n";
               		damage=calculate_damage(me, target, 60, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("qi", damage);
                                msg+=WHT"结果$n"WHT"绝望的看着$N，无地自容。\n" NOR;
                    			}
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃意┃\n";
			msg +=HIB "   ┗━┛\n";
               		damage=calculate_damage(me, target, 80, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_wound("qi", damage);
                                msg+=WHT"结果$n"WHT"想起你的情意，满面通红，羞愧万分。\n" NOR;
                    			}
                    			me->add("neili", -130);
                            message_vision(msg, me, target);
                                                 COMBAT_D->report_status(target);
                            }
	
}	


        me->receive_damage("qi", 50);
        me->add("neili", -130);



        me->start_busy(3);
        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

        damage=100+base_damage+(damage_bonus+random(damage_bonus));
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
                damage-=damage/3*2;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

	return damage;
}