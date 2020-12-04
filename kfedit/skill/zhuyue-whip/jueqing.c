// writted by fbbz
// 10/2001

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int calculate_damage(object me, object target, int base_damage, int damge_bonus);

int perform(object me, object target)
{       
        string msg="";
        int damage,wound,k,damage_bonus,mystr;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("一个人绝情给谁看啊！\n");

        if(!me->is_fighting())
                return notify_fail("「绝情」只能在战斗中让别人的心灵受伤！\n");
        

      if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("请使用碧涛心法!\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("你的碧涛心法还不够。。。\n"); 

                
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 300 )
                return notify_fail("你的精神状态太差了，没人会看你！\n");
        if((int)me->query_skill("zhuyue-whip", 1) < 200)
                  return notify_fail("你的这门鞭法修为还不够，恐怕只能偷偷的流泪吧！\n");
               mystr=me->query_str();

              k=(int)me->query_skill("whip");
              damage_bonus=k;
              damage_bonus=200+mystr*(damage_bonus+100+me->query("force_factor"))/200;
        message_vision(HIY"$N满心伤痕，痛不欲生，哭道：你真没良心，我跟你拼了! 说罢扑向$n，早已忘了自己的生死!\n"NOR,me,target);
                     
                        if (random((int)me->query("per"))<5 || random((int)target->query("combat_exp")) > ((int)me->query("combat_exp"))) 
                                                    {
//                         msg = "可是$p看到了$P哭泣背后的企图，笑道:我本来就无情无义，你能如何！\n" NOR;
//		              message_vision(msg, me, target）;
        message_vision(HIB"可是$p看到了$P哭泣背后的企图，笑道:我本来就无情无义，你能如何！\n"NOR,me,target);

                                }
                                 else {
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃绝┃\n";
			msg +=HIB "   ┗━┛\n\n";
               		damage=calculate_damage(me, target, 60, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"结果$n心中一动，呆呆的看着$N。\n" NOR;
                    			}
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃情┃\n";
			msg +=HIB "   ┗━┛\n\n";
               		damage=calculate_damage(me, target, 80, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"结果$n想起你的情，低下了头。\n" NOR;
                    			}
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃绝┃\n";
			msg +=HIB "   ┗━┛\n\n";
               		damage=calculate_damage(me, target, 120, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"结果$n绝望的看着$N，无地自容。\n" NOR;
                    			}
			msg +=HIB "   ┏━┓\n";
			msg +=HIB "   ┃意┃\n";
			msg +=HIB "   ┗━┛\n\n";
               		damage=calculate_damage(me, target, 180, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"结果$n想起你的情意，满面通红，羞愧万分。\n" NOR;
                    			}
                            message_vision(msg, me, target);
                                                 COMBAT_D->report_status(target);
                            }
        me->start_busy(2);
        //me->add("qi", -100);
        me->add("neili", -200);
        //me->add("jing",-100);
        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=(int)me->query_skill("zhuyue-whip", 1)+base_damage+(damage_bonus+random(damage_bonus))/4;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

	return damage;
}

