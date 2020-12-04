// /clone/medicine/nostrum/binghuojiu.c 玄冰碧火酒
// Modified by Zeratul Jan 11 2001 force>特殊内功时喝酒增长内力，反之降内力

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

void init()
{
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}
void create()
{
	set_name(HIC "玄冰碧火酒" NOR, ({"xuanbingbihuo jiu", "jiu"}));
	set("unit", "壶");
	set("long", "这是一壶珍贵之极的玄冰碧火酒, 据说对内力修为有极大助益。\n");
	set("value", 1000);
	set("lev", 1+random(3));
	set("pour_type", "1");
	setup();
}
int do_drink(string arg)
{
int exp,pot,i;
	object me = this_player();
	mapping	skill_map = me->query_skill_map();
	int force_limit = me->query_skill( "force" ) * 10;
	int neili_limit = me->query( "max_neili" );
	

exp = 888+random(888);
pot = exp/2;

	
	if(!id(arg)) return notify_fail("你要喝什么？\n");
	if(!present(this_object(), this_player()))
		return notify_fail("你要喝什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢喝，小心别呛着了。\n");
if (me->query_condition("medicine"))
{message_vision("$N上次的药性还没过", me);return notify_fail("你上次的药性还没过。\n");}
	if(arg=="jiu")
	{
		tell_object(me, HIM"你仰起头来，将壶中的酒尽数喝干，登时腹痛如绞。当下运起内力，\n要将肚中这团害人之物化去。哪知这酒的毒性非同小可，这一发作\n出来，只痛得你全身抽搐，手足痉挛，立时便欲晕去。\n"NOR );

			if ( (int)me->query_condition("binghuo" ) > 0 )
			{
				tell_object(me, HIR"你才喝此酒未久，还没用内功化除净尽，新酒入口，实难抵挡。\n"NOR);
				me->add( "max_neili", -random(20) );
				me->unconcious();
			}
			else
			{
				tell_object(me, HIG"你将以前学过、见过的诸般武功施展出来，乱打乱拍。只觉每发出\n一拳一掌，腹中的疼痛便随内力的行走而带了一些出来。使了一阵\n拳脚，腹内疼痛也随之而减。直到剧毒尽数逼离肚腹，也就不再疼\n痛，内力修为似乎有了不小进益。\n"NOR);
					me->add("max_neili", 50 + random(30) );
			}
       me->add("combat_exp",exp);me->apply_condition("medicine", 20);
       me->add("potential",pot);
message_vision("$N获得了"+chinese_number(exp)+"点经验,"+chinese_number(pot)+"点潜能!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N获得了"+chinese_number(i)+"点成长上限!\n"NOR, me);
}       
}
		me->apply_condition("binghuo", 500);
		destruct(this_object());
	}
	return 1;
}
