#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(HIY "金钱豹" NOR, ({ "jinqian bao", "jinqian", "bao" }));
	set("long", HIY "这是一只全身有着金钱斑纹的雄豹。\n" NOR);

	set("age", 3);
	set("str", 35);
	set("dex", 50);
	set("max_qi", 2800);
	set("max_jing", 2800);
	set("combat_exp", 80000);
set("race", "野兽");
        set("power", 35);
        set("item1", __DIR__"item/baorou");
        set("item2", __DIR__"item/baopi");

        set_temp("apply/parry", 180);
        set_temp("apply/dodge", 180);
        set_temp("apply/attack", 160);
        set_temp("apply/defense", 160);
        set_temp("apply/unarmed_damage", 220);
        set_temp("apply/armor", 220);

	setup();
}
