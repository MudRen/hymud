//by dewbaby@sk_sjsh
//【怜月】

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon,ob;
        string msg;
         int myexp,yourexp,youexp;
        int busy;    
        int hyjf, ap, dp, attp, defp;
        int damage;    
 
 

               string str; 


        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展【怜月九式】？\n");
         
         
         
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("【怜月九式】只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("你的太玄功还不够。。。\n"); 

        if((int)me->query_skill("bawang-qiang",1)+100 < (int)me->query_skill("sumi-jian",1))
                return notify_fail("此招需要领悟霸王枪法的意境。。。\n"); 


        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");
         
         if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

         if( (int)me->query_skill("sumi-jian", 1) < 120) 
                return notify_fail("你的素霓剑法火侯不够，无法使用此招!\n");

         hyjf = (int)me->query_skill("sumi-jian",1);

         if( (int)me->query_skill("sword",1) < hyjf)
                return notify_fail("你的基本剑术等级不够，无法使出【怜月】 。\n");

         if (me->query("neili") < 1300)
                return notify_fail("你内力不够，无法使用这一招。\n");

         me->clean_up_enemy();
         ob = me->select_opponent();
         myexp = (int) me->query("combat_exp");
         yourexp = (int) target->query("combat_exp");
         busy = (int)me->query_skill("parry",1)/54;
message_vision(HIY"\n$N腾空跃起，左手指尖向天，在空中画了个圆。右手剑气环绕，连绵不绝。正是"HIW"侠客岛"HIY"千古绝技"BLINK""HIR"怜月\n"NOR,me,target);        
    
message_vision(HIR"\n\n            “月到伤心谁肯怜，每逢佳节更难圆。\n"NOR,me,target);
message_vision(HIR"\n\n            “暮云西聚竞相逐，碧水东流不复还。\n"NOR,me,target);
message_vision(HIR"\n\n            “桂叶含香几分泪，山风醒酒准无眠。\n"NOR,me,target);
message_vision(HIR"\n\n            “吴刚已倦应停斧，又恐衣单晓雨寒。\n"NOR,me,target);

         damage=100+(int)me->query_skill("parry")+random((int)me->query_skill("sword"));
         if(random(myexp)>yourexp/8)
         {
                
          msg = HIY "若问月下谁有心，千山明月可曾惜，雨夜寒烛裹单衣，梦中无梦忘今夕.....”\n" NOR;
          message_vision(msg, me, target);
          target->start_busy(3);
          target->receive_damage("qi",damage,me);
          target->receive_wound("qi",damage/3,me);
          target->receive_damage("jing",damage,me);
          target->receive_wound("jing",damage/3+20,me);
          COMBAT_D->report_status(target);
      }
      else {
            message_vision(HIW"$n毫不动心，一声冷笑：“此情此景何需惜？自古至今月常新。”\n"NOR,me, target);
          me->start_busy(2);
          me->add("neili", -100);
  

  }
         
 if (hyjf> 300 && me && target)
 	{
  myexp = (int) me->query("combat_exp");
              youexp = (int) target->query("combat_exp");
                      
              msg = HIW "$N使出侠客岛"HIB"「忘怀」"WHT+"手中宝剑上隐现出丝丝"HIB+"暗蓝"WHT+"之气\n\n" NOR; 
              message_vision(msg, me); 
       	me->add_temp("apply/attack", 90);
me->add_temp("apply/damage", 1000);
              //me->clean_up_enemy(); 
              ob = target; 
    if (random(2)==0) target->start_busy(3);
              message_vision(HIY"$N身形迅如闪电，圈圈剑气不断地涌向$n。\n"NOR, me, ob); 
              
              
              	msg = HIB "$N吟：“山雨忽来溪水涨，风摇竹韵泪先淌。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       
              message_vision(HIY"$N一招之后第二招随即而起，$n"HIY+"被困得手忙脚乱。\n"NOR, me, ob); 
  
                	msg = HIB "$N黯然道：“岩蛙应睡为何鸣。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
  
                  	msg = HIB "$N黯然道:“星月难期共谁赏。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

       
              message_vision(HIY"$N脚步渐慢，手中剑舞却毫不停顿。$n"HIY+"只能暗自叫苦。\n"NOR, me, ob); 
                	msg = HIB "$N仰天道：“好梦焉能每夜圆。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
  
                  	msg = HIB "$N仰天道:“痴心不记几回往。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 
              message_vision(HIY"$N转身绕过$n，"HIY+"回手又是一剑，动作快而不躁。\n"NOR, me, ob); 
                	msg = HIB "$N咏道：“依窗只说已忘怀。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
  
                  	msg = HIB "$N咏道:“酒入愁肠偏又想。 ”\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       
              message_vision(HIW"$N连连几剑出手，身法快若魅影。$n被剑气逼得无法动弹。\n"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
	me->add_temp("apply/attack", -90);
me->add_temp("apply/damage", -1000);
 	}	
if (hyjf > 600  && me && target)
{
         message_combatd( HIR "$N聚气于剑，默运内力，只听“铮”的一声，忽然间银光闪耀，$N手中"+ weapon->name() + HIR"竟断化无数\n"
         + "截，如漫天红云般向$n激射而出！\n"NOR, me, target, "");

        attp = me->query_skill("taixuan-gong",1) + me->query_skill("sumi-jian",1);
        defp = target->query_skill("dodge");

//      if( random( attp ) > random( defp ) )
        if(  attp  > random( defp ) || random(3)==0)
        {
                damage = 800+me->query_skill("sumi-jian",1) + me->query_skill("sword",1)+ (int)me->query_skill("taixuan-gong", 1)*2;
                damage = damage - random( target->query_skill("dodge")/10 );

                target->receive_wound("jing", random( damage ),me);
                target->receive_damage("qi", 20 + random(damage)+damage,me);
                target->receive_wound("qi", 20 + damage, me);
                me->start_busy(3);
                target->start_busy(3 + random(4));
        }
        else 
        {
                message_combatd( HIY "可是$p晃动身形，迅速的闪过了无数刀屑。\n" NOR, me, target, "" );
                me->start_busy(2);
        }
	
me->add("neili", -50);
}		
	 	        
           me->start_busy(3);
if (msg && me && target)          message_vision(msg, me, target); 
     return 1;  
}


