#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_ANA;



int halt_breaking(object me);
int continue_breaking(object me);

void create()
{
	int i = random(sizeof(meridians));
	string meri = "m"+ (string)(i+1);
	mapping meridian = meridians[i];
	
	set_name(HIY"冲穴铜人"NOR, ({ "chongxue tongren", "tongren" }));
	set_weight(50);

	set("unit", "个");
	set("long",HIG"这是一个全身画满了密密麻麻的经脉穴道的铜人，"
				"按照上面的行功路线似乎可以打通"+meridian["mer"]+"(canwu)。\n"NOR);
	set("value", 1000);
	set("material", "iron");
	set("mer",meri);
}

void init()
{
	add_action("do_chongxue",({"canwu"}));
}

int do_chongxue(string arg)
{
	object me = this_player();	
	string meri;
	seteuid(getuid());	
	if(!id(arg)) return notify_fail("你要用什么来打通经脉穴道？\n");
	
	meri = query("mer");
  
	 //return notify_fail("你要用"+meri+"什么来打通经脉穴道？\n");
	return chongxue(me,meri);
}

int continue_breaking(object me)
{
	mapping meridian = get_meridian(me->query_temp("meri"));
	mapping *anamichis = get_anamichis(me->query_temp("meri"));
	mapping anamichi = anamichis[(int)me->query_temp("anami")];
	
	me->start_busy(60);
	tell_object(me, HIR "\n你继续闭关修行以打通"+meridian["meri"]+HIR"的"+anamichi["ana"]+NOR"。\n"NOR);
	return 1;
}

private void stop_breaking(object me)
{
        if (! interactive(me))
        {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
        }
}

int halt_breaking(object me)
{
	tell_object(me, "你中止了闭关。\n");
	message_vision(HIY "$N" HIY "轻轻叹了一口气，缓缓的睁开眼。\n\n" NOR, me);
	me->set_temp("biguan", 0);
	return 1;
}

private void user_quit(object me)
{
        if (! me || interactive(me))
                return;
      
        me->force_me("quit");
}

int query_autoload() { return 1; }
