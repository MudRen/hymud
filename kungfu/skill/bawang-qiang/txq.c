//毒龙穿心钻
//by junhyun@SK

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon,victim;

        int mkee;

        int ap, dp;

        int times, extra,i;
        string number;

        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("club",1);
        myskill1= (int)me->query_skill("bawang-qiang",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";

                 if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
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

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");



        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");


       if( !wizardp(me) &&(int)me->query_skill("bawang-qiang", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("taixuan-gong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");



        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "bawang-qiang")
          //      return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通侠客岛武学，使出了侠客岛的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               
//victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}


        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");

 
        
        
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("neili");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("neili",-100);
        //me->receive_damage("jing", 50);
        message_vision(HIW"$N单手握枪，纵身跃起，身随枪走，带起杀气滚滚！
            『毒龙穿心钻』 \n" NOR,me,target);        
        message_vision(HIY"$N与手中枪化作一道金光犹如一条黑龙笔直的刺向对方！\n"NOR,me);
         if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                msg = HIR"$n躲闪不及，金光大作中被$N连人带枪透体而过！\n"NOR;
                damage=100+(int)(myskill1);
                if(damage<1)damage = 1;
                target->receive_damage("qi",damage*4,me);
                target->receive_wound("qi", damage*4,me);
                //target->start_busy(3);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                me->start_busy(1);
        }
        else
        {
                msg = HIW"$n自知不敌，身形一低,贴着地面平平的飞了出去！\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target, me, tweapon);
                me->start_busy(2);
        }        
message_vision(HIC"$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"枪，枪枪要命！\n"NOR,me,target);
                if (!target->is_busy()) target->start_busy(1);
        me->add_temp("apply/attack", 180);
        me->add_temp("apply/damage", 2200);
        times=6;
        for(i=1;i<=times;i++)
{
                        msg = HIY "第"+chinese_number(i)+"枪-------> ”\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
}        
        me->add_temp("apply/attack", -180);
        me->add_temp("apply/damage", -2200);

       damage = 100+random(me->query_str()) + me->query_skill("taixuan-gong");
      message_vision(HIW "$N" HIW "突然间只觉得右肋下‘渊液穴’上一动，一道热线沿着‘足少"
                     "阳胆经’，\n向着‘日月’、‘京门’二穴行去，\n一招‘十步杀一人’的"  + 
                     "拳法已随意使出，各种招式源源而出，将$n" HIW "笼罩。\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$n" HIY "却觉$N" HIY "这招气势恢弘，于是运力奋力抵挡。但是无奈这"
                "招威力惊人，\n$n" HIY "闷哼一声，倒退几步，顿觉内息涣散，" + "双手" + HIY 
                "上早已染满鲜血！\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "气贯双臂，凝神以对，竟将$N" HIC "之力卸去。\n" NOR;
        }
        message_vision(msg, me, target);


        message_vision(HIW "$N" HIW "肌肤如欲胀裂，内息不由自主的依着‘赵客缦胡缨’那套经脉运"
                     "行图谱转动，\n同时手舞足蹈，似是大欢喜，又似大苦恼。\n" NOR, me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$n" HIY "冷笑一声，觉得$N" HIY "此招肤浅之极，于"
                                          "是随意招架，\n猛然间，「噗嗤」！一声，" + "一拳" +
                                          HIY "已穿透$n" HIY "的胸膛，鲜血不断涌出。\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "会心一笑，看出$N" HIC "这招中的破绽，随意施招竟将这招化去。\n" NOR;
        }
        message_vision(msg, me, target);


        message_vision(HIW "‘赵客缦胡缨’既毕，接下去便是‘吴钩霜雪明’，$N" HIW "更"
                    "不思索，\n石壁上的图谱一幅幅在脑海中自然涌出，自‘银鞍照白马’直到‘谁能书阁下’，\n"
                    "一气呵成的使了出来。\n" NOR, me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$n" HIY "心中一惊，但见$N" HIY "这几招奇异无比，招式变化莫测，"
                "但威力却依然不减，\n正犹豫间，$n" HIY "却已中招，顿感精力不济，浑"
                "身无力。\n" NOR;

        } else
        {
              msg = HIC "$n" HIC "默运内功，内劲贯于全身，奋力抵挡住$N" HIC "这招。\n" NOR;
        }
        message_vision(msg, me, target);


        message_vision(HIW "待得‘谁能书阁下’这套功夫演完，$N" HIW "只觉气息逆转"
                     "，‘不惭世上英’倒使上去。\n" NOR, me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$N" HIY +  "拳法奇妙无比，招式时而宛若游龙，时而"
                "宛若惊鸿，霎那间$n" HIY "已遍体鳞伤。\n$N" HIY "猛然将" + "拳风" + HIY "一"
                "转，招式陡然加快，将$n" HIY "团团围住，竟无一丝空隙！\n" NOR;

        } else
        {
                            msg = HIC "$n" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，方才躲过$N" HIC "这招。\n" NOR;
        }
        message_vision(msg, me, target);


me->start_busy(4);
     
        return 1;
}
