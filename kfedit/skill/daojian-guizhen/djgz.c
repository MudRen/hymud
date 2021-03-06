// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;
        int ap, dp, fp, pp,count;

      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在战斗中对对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("daojian-guizhen", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("lengyue-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通胡家武学，使出了胡家的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}

	me->delete_temp("lianhuan");

	me->add_temp("apply/attack", 200);	
	me->add_temp("apply/damage", 2800);
	msg = HIR  "$N一咬牙，手上动作加快，同时使出［胡家刀法中］的刀刀相连，手中的"+ weapon->name() +" 一刀连着一刀，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIR "在一片刀光中，一刀劈了过来\n" NOR;
        message_vision(msg, me, target);

	for(i=0;i<7;i++)
	{
	msg = HIY "$N咬紧牙关，一刀又劈了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}

	me->add_temp("apply/attack", -200);	
	me->add_temp("apply/damage", -2800);



        damage = me->query_skill("daojian-guizhen",1)+me->query_skill("lengyue-shengong",1);

        msg = HIY "$N" HIY "将" + weapon->name() + HIY "与" +
              weapon->name() + HIY "横置于胸前，运转出「"
              HIR "刀剑七重天" HIY "」功力，内劲如海啸般爆发。\n" NOR;

if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                msg += HIR "$n" HIR "见$N" HIR "杀气大涨，不禁心"
                       "生惧意，招架顿时散乱，全然不成章理。\n" NOR;
       target->receive_damege("qi", damage,me);
        target->receive_wound("qi", damage,me);
                //ap += ap / 5;
                //damage += damage / 2;
        } else
        {
                msg += HIG "$n" HIG "见$N" HIG "杀气大涨，丝毫不"
                       "敢大意，急忙收敛心神，努力不受干扰。\n" NOR;
        }

        msg += HIW "突然间$N" HIW "身形一展，右手" + weapon->name() +
               HIW "忽地一振，凌空卷出一道半弧，直劈$n" HIW "而去。\n" NOR;

 	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
        	
       target->receive_damege("qi", damage*2,me);
        target->receive_wound("qi", damage*2,me);
		msg +=                     HIR "$n" HIR "奋力抵挡，却哪里招架得住"
                                           "，被$N" HIR "一招划中要脉，鲜血四处飞"
                                           "溅。\n" NOR;
        	

        } else
        {
                msg += CYN "$n" CYN "心知这一招的凌厉，急忙凝神"
                       "聚气，小心拆招，丝毫无损。\n" NOR;
        }

        msg += HIW "接着$N" HIW "又将左手" + weapon->name() +
               HIW "朝$n" HIW "平平递出，招式看似简单，却蕴藏着"
               "极大的杀着。\n" NOR;

 	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                // 转移武器
       target->receive_damege("qi", damage*2,me);
        target->receive_wound("qi", damage*2,me);

		msg +=                     HIR "$n" HIR "只觉眼花缭乱，全然无法洞"
                                           "察先机，$N" HIR "一招命中，射出一柱鲜"
                                           "血。\n" NOR;
                // 转移回初始状态

        } else
        {
                msg += CYN "$n" CYN "心知这一招的凌厉，急忙凝神"
                       "聚气，小心拆招，丝毫无损。\n" NOR;
        }
        message_combatd(msg, me, target);


   msg = HIW "$N" HIW "手中" + weapon->name() + HIW "蓦地一抖"
              "，将「" NOR + WHT "胡家刀法" HIW "」并「" NOR + WHT
              "苗家剑法" HIW "」连环施出。霎时寒\n光点点，犹如夜陨"
              "划空，铺天盖地罩向$n" HIW "，正是一招「" HIW "天下"
              "有" HIR "血" HIW "」。\n" NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("parry",1);

       if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                msg += HIW "$n" HIW "只见无数刀光剑影向自己逼"
                       "来，顿感眼花缭乱，一招命中，射出一柱鲜血。\n" NOR;
      damage=me->query_skill("daojian-guizhen",1);
      target->receive_damege("qi", damage*8,me);
        target->receive_wound("qi", damage*8,me);
        } else
        {
                msg += HIG "$n" HIG "突然发现自己四周皆被刀光"
                       "剑影所包围，心知不妙，急忙小心招架。\n" NOR;

        }
        message_combatd(msg, me, target);

	me->start_busy(4);
	return 1;
}

