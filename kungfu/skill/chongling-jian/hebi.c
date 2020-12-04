// hebi.c
// by dubei

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
private int remove_effect(object me, int skill);
int perform(object me, string arg)
{
    object weapon, weapon1, target;
    object victim;
    int skill, skill1;

    if(!arg) return notify_fail("你想和谁一起双剑合璧？\n");
    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("这里没有这个人。\n");

        if( !victim ) victim = offensive_target(me);

        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("双剑和璧左右互搏只能对战斗中的对手使用。\n");


    if(!living(target))
                return notify_fail(target->name()+"已经无法战斗了。\n"); 
    if(target==me) return notify_fail("想和自己合璧？\n"); 
    if(me->is_fighting(target))
                return notify_fail("你正在和"+target->name()+"打架呢。\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "chongling-jian"
      )
        return notify_fail("你要把冲灵剑法做为剑法才能用「双剑合璧」。\n");

    if(me->query_skill_mapped("force") != "zixia-shengong" )
        return notify_fail("你要把紫霞神功做为内功才能用「双剑合璧」。\n");
    if(me->query_skill_mapped("force") != "zixia-shengong" )
        return notify_fail("你要把紫霞神功做为内功才能用「双剑合璧」。\n");
if (me->query("gender")=="无性")
        return notify_fail("一男一女才能双剑合璧。\n");

if (me->query("gender")=="男性" && target->query("gender")=="男性")
        return notify_fail("一男一女才能双剑合璧。\n");
if (me->query("gender")=="女性" && target->query("gender")=="女性")
        return notify_fail("一男一女才能双剑合璧。\n");
        
    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "chongling-jian"
      )
        return notify_fail(target->name()+"要把冲灵剑法做为剑法才能用「双剑合璧」。\n");

    skill = me->query_skill("chongling-jian", 1);
    skill1 = target->query_skill("chongling-jian", 1);
    
    if(skill < 160 )
        return notify_fail("你的冲灵剑法等级不够，不能使用「双剑合璧」。\n");
    
    if( skill1 < 160 )
	return notify_fail( target->name()+"的冲灵剑法不够纯熟，无法和你配合使用「双剑合璧」。\n");

    if((int)me->query_skill("zixia-shengong", 1) < 160 )
        return notify_fail("你的紫霞神功等级不够，不能使用「双剑合璧」。\n");       

    if((int)target->query_skill("zixia-shengong", 1) < 160 )
        return notify_fail(target->name()+"的紫霞神功不够纯熟，无法和你配合使用「双剑合璧」。\n");       
    
    if((int)me->query("neili") < 300 )
        return notify_fail("你现在真气太弱，不能使用「双剑合璧」。\n");

    if((int)target->query("neili") < 300 )
        return notify_fail( target->name()+"现在真气太弱，不能使用「双剑合璧」。\n");

    if((int)me->query("max_neili") < 500 )
        return notify_fail("你现在内力太弱，不能使用「双剑合璧」。\n");

    if((int)target->query("max_neili") < 500 )
        return notify_fail(target->name()+"现在内力太弱，不能使用「双剑合璧」。\n");

    if(me->query_temp("gumu_hebi")) 
        return notify_fail("你已经在使用「双剑合璧」了。\n");

    if(target->query_temp("gumu_hebi")) 
        return notify_fail(target->name()+"已经在使用「双剑合璧」了。\n");
    
    if(me->query_temp("gmhebi_target")){
          if(me->query_temp("gmhebi_target")==target)
                return notify_fail("你已经做好和"+target->name()+"双剑合璧的准备了。\n");
          else{               
               tell_object(me->query_temp("gmhebi_target"), YEL+me->name()+"决定不和你进行双剑合璧了。\n"NOR); 
               me->delete_temp("gmhebi_target");
               }
          }
    if(target->query_temp("prepare_gmhebi")) {
	message_vision(HIC"$N长啸一声，将手中"+weapon->name()+HIC"一摆，好象给了$n一个信号。\n"NOR,me,target);
        message_vision(HIC"$n将手中"+weapon1->name()+HIC"一摆，架在$N的"+weapon->name()+HIC"上，双剑相加，顿时光芒四射，声震天地！\n"NOR,me,target);
        me->delete_temp("prepare_gmhebi", 1);     
        me->delete_temp("gmhebi_target", 1);
        me->set_temp("gumu_hebi", target); 
        target->set_temp("gumu_hebi", 1); 
        me->add("neili", -300);
        target->add("neili", -300);
        me->add("jing", -50);
        target->add("jing", -50);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dexerity", skill/15);
        target->add_temp("apply/attack", skill1);
        target->add_temp("apply/dexerity", skill1/15);
if (random(3)==0) target->start_busy(5);
message_combatd(HIC "$N"HIC"和$n" HIC "两人眼神一交，心意已"
                        "然相通，不由的会心一笑，只见二人身形一错，霎时\n"
                        "已经向" + victim->name() + HIC"攻出数招！\n" NOR,
                        me, target);
        target->start_busy(5);
        message_vision(HIG"$N使出"HIW"--在天愿做比翼鸟．在地愿为连理枝--!"HIG" 左边刺一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIC"$n使出"HIR"--两情若在长久时．又岂在朝朝暮暮--!"HIC" 右边刺一剑！！\n" NOR,me,target);
        COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
        message_vision(HIG"$N使出"HIW"--天涯地角有穷时．只有相思无尽处--!"HIG" 上边刺一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIC"$n使出"HIR"--衣带渐宽终不悔．为伊消得人憔悴--!"HIC" 下边刺一剑！！\n" NOR,me,target);
        COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
        message_vision(HIG"$N使出"HIW"--无情不似多情苦．一寸还成千万缕--!"HIG" 高处劈出一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIG"$N使出"HIW"--此情可待成追忆．只是当时已惘然--!"HIG" 剑光一道，夺人心魄！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

if (me->query("qi") < me->query("max_qi"))
{
message_vision(HIC"$N的伤好像好了很多！！\n" NOR,me,target);
me->add("qi", me->query("max_qi")/3);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi", me->query("max_qi")/3);
}
if (target->query("qi") < target->query("max_qi"))
{
message_vision(HIC"$n的伤好像好了很多！！\n" NOR,me,target);
target->add("qi", target->query("max_qi")/3);
if (target->query("eff_qi") < me->query("max_qi"))
target->add("eff_qi", me->query("max_qi")/3);
}


        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, skill :), 1);
        target->start_call_out( (: call_other, __FILE__, "check_fight", target, me, skill1 :), 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), (skill+skill1)/2);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), (skill+skill1)/2);
        return 1;
        }
    message_vision(YEL"$N将手中"+weapon->name()+"一横，暗示$n和$P一起运用双剑合璧。\n"NOR,me,target);
    tell_object(target, YEL"你如果愿意和"+me->name()+"进行双剑和壁，请也对"+me->name()+"下一次 ( perform hebi player<name> ) 的命令。\n"NOR); 
    me->set_temp("prepare_gmhebi", 1);     
    me->set_temp("gmhebi_target", target);
    return 1;
}

void check_fight(object me, object target, int skill, int skill1)
{
    object weapon;      
    object victim;
        if( !victim ) victim = offensive_target(me);
if (victim && random(2)==0)
{
if (!target->is_busy()) target->start_busy(3);
        message_vision(HIG"$N使出"HIW"--多情自古空余恨--!"HIG"左边刺一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIC"$n使出"HIR"--情到深处无怨由--!"HIC"右边刺一剑！！\n" NOR,me,target);
        COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
if (me->query("qi") < me->query("max_qi"))
{
message_vision(HIC"$N的伤好像好了很多！！\n" NOR,me,target);
me->add("qi", me->query("qi")/6);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi", target->query("qi")/6);
}
if (target->query("qi") < target->query("max_qi"))
{
message_vision(HIC"$n的伤好像好了很多！！\n" NOR,me,target);
target->add("qi", target->query("qi")/6);
if (target->query("eff_qi") < me->query("max_qi"))
target->add("eff_qi", target->query("qi")/6);
}
}
    if(!objectp(weapon = me->query_temp("weapon")) 
     || !objectp(weapon = target->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword")
    {
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else if( !present(target->query("id"), environment(me)) 
	  || !me->is_fighting() 
	  || !living(target) 
	  || !target->is_fighting()
          || target->is_ghost() 
	  || me->is_ghost() 
	  || !living(me)) {

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else {
	call_out("check_fight", 1, me, target, skill);
	 return;
	}
}
private int remove_effect(object me, object target)
{
    int skill, skill1;
     skill = me->query_skill("chongling-jian", 1);
    if(me->query_temp("gumu_hebi")) 
{
    me->delete_temp("gumu_hebi");
    me->delete_temp("gmhebi_target");
    me->delete_temp("prepare_gmhebi");     
   me->add_temp("apply/attack", -skill);
    me->add_temp("apply/dexerity", -skill/15);
	message_vision(HIR"$N双剑合璧完结，攻守也恢复正常了。\n"NOR, me);
tell_object(me, "你的双剑合璧完结，攻守也恢复正常了。\n");
}
}
 