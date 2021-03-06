// fenshen.c 分身术

#include <ansi.h>
inherit F_SSERVER;

string get_name(string str)
{
        str="分身术";
        return str;
}

string get_help(string str)                
{
        str="指令：ｃａｓｔ　ｆｅｎｓｈｅｎ\n"
        +"身体一分为二，用假身帮助你攻击对方以及抵御对方的攻击。";
        return str;
}

int exert(object me)
{
	object target;
        int fenshen_time; //this time is the time interval fenshen can be used again. 
        object soldier;
int skill;
mapping ob_fam; 
  if( !target ) target = offensive_target(me);

        if((int)me->query_skill("taoism",1) < 100)
                return notify_fail("你的道法不够。。。\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("只能战斗使用\n");


           if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"只能对战斗中的对手使用。\n"NOR);

        if ((!(ob_fam = me->query("family")) || ob_fam["family_name"] != "青城派") && userp(me))
return notify_fail("青城派才能分身。\n");  

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你无法集中精力！\n");

if (me->query_temp("nozh"))
	return notify_fail("分身无法再分身！\n");
	
if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("超出一次战斗上限。\n");   	
	
	
        fenshen_time=60+(200-(int)me->query_skill("taoism"));
        if(fenshen_time<60) fenshen_time=60;
        if((time()-me->query_temp("last_fenshen"))<fenshen_time)
                return notify_fail("你刚刚分过身，再分身很危险！\n");
                //hehe...at least 1 minute between 2 fenshens to
                //prevent ppls using too many 假身 to kill top masters...weiqi.

        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚用过分身术，心力不足！\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够了！\n");
        
        if( (int)me->query("neili") <1000)
                return notify_fail("你的内力不够了！\n");

        if( (int)me->query("jing") < 50 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语。分身法!!\n", me);

                me->add("neili",-(int)me->query_skill("taoism"));



        me->receive_damage("jing", 40);
        skill=(int)me->query_skill("qingming-xuangong",1);
        skill=skill*0.8;
 seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
              soldier->set_name(this_player()->query("name")+"的分身",({"dizi"}));
   

        soldier->invocation(me);
        soldier->initlvl(skill,41);
         message_vision(HIG"$N喝道：妙中妙，玄中玄 太级化二仪 ！\n"NOR, soldier);
         if (!userp(me)) me->add_temp("zhrs",1);
        me->set_temp("last_fenshen",time());
        me->start_busy(3);

        return 3+random(5);
}

