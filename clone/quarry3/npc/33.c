#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(HIW "绵羊" NOR, ({ "mian yang", "mian", "yang" }));
	set("long", HIW "这是一头雪白可爱的又肥又壮的绵羊。\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 8);
	set("dex", 25);
	set("max_qi", 600);
	set("max_jing", 600);
	set("combat_exp", 3000);
set("race", "野兽");
        set("power", 6);
        set("item1", __DIR__"item/yangrou");
        set("item2", __DIR__"item/yangpi");

        set_temp("apply/parry", 30);
        set_temp("apply/dodge", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/unarmed_damage", 30);
        set_temp("apply/armor", 30);

	setup();
}
