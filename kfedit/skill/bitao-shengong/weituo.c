//lestat 2001

#include <ansi.h>
inherit F_SSERVER;

int exert(object me)
{
        int invocation_time;
        object soldier;
object target;
int skill;
mapping ob_fam; 
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能请韦陀下凡。\n");
        
        if( !target ) target = offensive_target(me);
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
		
		        if((int)me->query_skill("buddhism",1) < 200)
                return notify_fail("你的禅宗心法还不够。。。\n");

        if((int)me->query_skill("bitao-shengong",1) < 200)
                return notify_fail("你的碧涛心法还不够。。。\n"); 
                
               	if ((!(ob_fam = me->query("family")) || ob_fam["family_name"] != "白云庵") && userp(me))
return notify_fail("白云庵才能请韦陀下凡。\n"); 

if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("分身无法再分身！\n");

if (me->query_temp("invoker"))
return notify_fail("分身无法再分身！\n");

if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("超出一次战斗上限。\n");         
        
        invocation_time=30+(200-(int)me->query_skill("buddhism"));
        
        if(invocation_time<30) invocation_time=30;
        
        if((time()-me->query_temp("last_invocation"))<invocation_time+30 && !wizardp(me))
                return notify_fail("你刚请韦陀下凡。，心力不足！\n");

        if ((int)me->query_condition("zdizi_busy") && !wizardp(me))  
        return notify_fail("你刚请韦陀下凡。心力不足！\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("jing") < 500 )
                return notify_fail("你的精神无法集中！\n");

        skill=(int)me->query_skill("bitao-shengong",1);
        skill=skill*0.6;
        message_vision(HIG"$N跳出圈子来，高颂佛号。\n"NOR, me);
 message_vision(HIY"\n$N语音清脆，越念越是冲和安静，全身隐隐发出圣洁的光辉。\n"NOR,me,target);
 
 
message_vision(HIY"\n大慈大悲始至终，菩萨智慧量无穷。"NOR,me,target);
message_vision(HIY"\n信解功德行为首，愿力宏深十地中。"NOR,me,target);
message_vision(HIY"\n表法慈悲圣观音，象征智慧师文殊。"NOR,me,target);
message_vision(HIY"\n示范功行恩普贤，实践宏愿心地藏。\n"NOR,me,target);
 
        me->add("neili", -600);
        me->receive_damage("jing", 300);

        if( random(me->query("max_neili")) < 500 ) 
        {
                message("vision", "但是什么也没有发生。\n",environment(me));
                return 1;
        }

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
	      soldier->set_name(HIY"持刀韦陀"NOR,({"weituo"}));
        soldier->invocation(me);
        soldier->initlvl(skill,59);
        soldier->set_temp("nozh",1);
	 message_vision(HIG"$N喝道：降妖伏魔！\n"NOR, soldier);

        if (!userp(me)) me->add_temp("zhrs",1);
        me->set_temp("last_invocation",time());
        me->start_busy(3);
        if(me->query_skill("bitao-shengong", 1) >= 400)
                call_out("sanqing2", 1, me, target);   
        return 1;
}

int sanqing2(object me, object target)
{
        object soldier;
        int skill;
        skill=(int)me->query_skill("bitao-shengong",1);
        skill=skill*0.6;

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));

        soldier->set_temp("invoker",me);
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
	      soldier->set_name(HIG"持鞭韦陀"NOR,({"weituo"}));
        soldier->invocation(me);
        soldier->initlvl(skill,57);
        soldier->set_temp("nozh",1);
	 message_vision(HIG"$N喝道：降妖伏魔！\n"NOR, soldier);

        if(me->query_skill("bitao-shengong", 1) >= 600)
                call_out("sanqing3", 1, me, target);   

        return 1;
}

int sanqing3(object me, object target)
{
        object soldier;
        int skill;
        skill=(int)me->query_skill("bitao-shengong",1);
        skill=skill*0.6;

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
	      soldier->set_name(HIR"持杵韦陀"NOR,({"weituo"}));
        soldier->invocation(me);
        soldier->initlvl(skill,58);
	 message_vision(HIG"$N喝道：降妖伏魔！\n"NOR, soldier);

        return 1;
}

