// hunpofeiyang.c 魂魄飞扬
 
#include "/kungfu/skill/eff_msg.h";
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
void remove_effect(object target);
string *songs = ({"五行之气调阴阳","损心伤肺摧肝肠","藏离精失意恍惚","三焦齐逆兮魂魄飞扬"});
 
int perform(object me)
{
	int extra;
	object weapon, target;
      string msg, song;                                   
      int p;
      song = songs[random(sizeof(songs))];
	
	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting() )
	    	return notify_fail("「魂魄飞扬」只能在战斗中使用。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力还不够高！\n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法使用魂魄飞扬！\n");

	if( (int)me->query_skill("qishang-cuff", 1) < 60)
		return notify_fail("你七伤拳的修为不够，不能使用魂魄飞扬! \n");
    if ((int)me->query_skill("kongdong-xinfa", 1) < 40 )
        return notify_fail("你本门内功火候不够，使不出「魂魄飞扬」。\n");

      if(target->query_temp("qishang"))
          return notify_fail("对方已经身受「七伤总诀」，你不用费劲了！\n");

// not tiezhang-zhangfa, should be qishang-cuff (by xbd)
	extra = me->query_skill("qishang-cuff",1) / 20;
	extra += me->query_skill("force",1) /20;
	me->add_temp("apply/attack", 200);	
	me->add_temp("apply/damage", 1800);
	msg = HIY "$N大喝一声，使出七伤拳的绝技「魂魄飞扬」，双拳势如雷霆，向$n击去。\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

if (me->query_skill("qishang-cuff",1)>300)
{
		msg = HIY "$N一拳击出，拳风中竟带有刚柔三种不同的劲力，分击$n的全身上下三十六道要穴\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIY "$N暗吸一口真气，双拳平伸，左刚右柔连续打出四拳，带着四种不同之力击向$n。\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIY "$N默运神功，双拳无形无定，突然于空气中出现五种不同的劲力骤然击向$n\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIY "$N单拳一握，默运内息，六种不同劲力随着打出的拳风又低又快的击向$n\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIY "只见$N双目紧闭深运内力，然后猛的大喝了一声，飞身扑下，以七种无比之劲力击向$n的全身\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIY "$N一声狂啸，双目赤红，拳路大开大阖，每一拳击出如诸神震怒，石破天惊，皆含催破内家真气的大威力\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
	
	me->add_temp("apply/attack", -200);
	me->add_temp("apply/damage", -1800);

      
if (userp(me))
{
      message_vision(HIR"\n突然$N眼射精光，朗声念出句似歌非歌、似诗非诗的拳诀：“"+song+"”，接着走上前去，砰的一拳击向$n！\n"NOR,me, target);

     if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0){         
            target->receive_damage("qi", me->query_skill("force"));            
            target->receive_wound("qi", me->query_skill("force"));            
            me->add("neili", -100);
            me->start_busy(3);
            target->start_busy(1);
            if(me->query("neili")*2 < target->query("neili"))  
                 tell_object(me, HIR"你只觉"+target->name()+"体内内力极强，你暗藏在拳内的各种力道根本送不出去！\n"NOR);
            else{
                 tell_object(me, HIW"在刚一触到"+target->name()+"的身体时，你便暗暗发力，将隐藏在在拳内的七种力道送了过去！\n"NOR);
                 tell_object(target, HIW"你一晃眼，只见"+me->name()+"的拳已经打在你的身上，跟着几股说不出的暗劲顺势传了过来！\n"NOR);
                 target->set_temp("qishang", 1);
                 target->add_temp("apply/strength", -(target->query("str", 1)/2));    
                 target->add_temp("apply/dexerity", -(target->query("dex", 1)/2));  
                 target->add_temp("apply/intelligence", -(target->query("int", 1)/2));    
                 target->add_temp("apply/constitution", -(target->query("con", 1)/2));  
                 target->apply_condition("qishang_poison", 50+target->query_condition("qishang_poison"));
                 target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), me->query_skill("force")/2); 
                }
            target->receive_damage("qi", me->query_skill("force")*3);    
            p = (int)target->query("qi")*100/(int)target->query("max_qi");
            msg = damage_msg(me->query_skill("force")*3, "内伤");
            msg += "( $n"+eff_status_msg(p)+" )\n";                
            } 
            else 
               {       
                me->start_busy(3);
                me->add("neili", -(100)); 
                msg = "只见$p轻轻一转身，已经绕到了$P身后。而$N却因劲力打空不受控制，头脑眩晕！\n";
               }
}
            message_vision(msg, me, target);
           return 1;
}
void remove_effect(object target)
{
      if(!target) return;
      target->add_temp("apply/strength", target->query("str", 1)/2);    
      target->add_temp("apply/dexerity", target->query("dex", 1)/2);  
      target->add_temp("apply/intelligence", target->query("int", 1)/2);    
      target->add_temp("apply/constitution", target->query("con", 1)/2);   
      target->delete_temp("qishang");
      tell_object(target, HIW"终于，体内那几股暗劲在遍布你的全身后开始慢慢散去了。\n"NOR);
}
