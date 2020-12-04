// gems - by xbd

#include <ansi.h>

inherit ITEM;
inherit F_GEMS;

void create()
{
	int lev, i,j,fn;
	string gem, s,filen;
	object ob;
	object me = this_player();

	i = random(12);
	if (i == 1) gem = "ruby";
	else if (i == 2) gem = "topaz";
	else if (i == 3) gem = "sapphire";
	else if (i == 4) gem = "emerald";
	else if (i == 5) gem = "amethyst";
	else if (i == 6) gem = "windjade";
	else if (i == 7) gem = "firejade";
	else if (i == 8) gem = "icejade";
	else if (i == 9) gem = "thunderjade";
	else if (i == 10) gem = "earthjade";
	else if (i == 11) gem = "diamond";
	else gem = "skull";

          lev=8;

if (i > 0) i=i*10;
fn=i+lev;

	set_name(query_gem_name(gem, lev)+HIY" 原石"NOR, ({query_gem_id(gem, lev)}));
	set_weight(100);
	set("long", query_all_effect(gem));
	set("unit", "颗");
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
        set("no_pawn",1);
	set("value", 10000 * lev * lev * lev);
	set("material", gem);
	set("lb", i);
	set("level", lev);
	
	setup();

}

void init()
{
	add_action("do_combine", "search");
	add_action("do_combine", "jianding");
}



int do_combine(string arg)
{
	int i;
	object ob;
	int lev, j,fn;
	string s,filen;
	object *inv, gem, me = this_player();

	if (!wizardp(me) && !arg || arg == "")
		return notify_fail("你想鉴定什么宝石？\n");
	if (!wizardp(me) && arg != query("id")) return 0;
	
	if (me->query("max_neili") < 100 || me->query("neili") < 300)
		return notify_fail("以你现在的内力修为，还无法运功鉴定宝石！\n");

	if ((int)me->query("score") < 300 )
		return notify_fail("以你现在的江湖阅历，还无法运功鉴定宝石！\n");

				message_vision(HIY"$N暗运内力劲透宝石，但见" + name() + HIY"表面异彩流动，
渐渐的$N收回了内力，只觉" + name() + HIY"表面的杂质和渣滓全部被融化了！\n", me);
				me->add("max_neili", -2);
				me->add("neili", -200);
				me->add("score", -200);
				me->start_busy(1);
i=query("lb");
lev=query("level");
fn=i+lev;

	filen="/clone/gem/gem"+fn;
	

	           ob = new(filen);
  
           ob->move(this_player());


				destruct(this_object());
				return 1;
}
