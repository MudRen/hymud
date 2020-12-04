#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "鳄鱼" NOR, ({ "e yu", "e", "yu" }));
	set("long", CYN "这是一只体形庞大的鳄鱼，相当的凶猛。\n" NOR);

	set("age", 3);
	set("str", 35);
	set("dex", 50);
	set("max_qi", 8000);
	set("max_jing", 8000);
        set("neili", 8000);
        set("max_neili", 4000);
	set("combat_exp", 600000);
set("race", "野兽");
        set("power", 50);
        set("item1", __DIR__"item/eyurou");
        set("item2", __DIR__"item/eyupi");

        set_temp("apply/force", 220);
        set_temp("apply/parry", 220);
        set_temp("apply/dodge", 220);
        set_temp("apply/attack", 280);
        set_temp("apply/defense", 280);
        set_temp("apply/unarmed_damage", 300);
        set_temp("apply/armor", 300);

	setup();
}
