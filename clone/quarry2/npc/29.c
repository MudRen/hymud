#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "Ò°ÍÃ" NOR, ({ "ye tu", "ye", "tu" }));
	set("long", WHT "ÕâÊÇÒ»Ö»Ã«È×È×µÄÒ°»ÒÍÃ¡£\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 30);
	set("max_qi", 300);
	set("max_jing", 300);
	set("combat_exp", 1000);
set("race", "Ò°ÊŞ");
        set("power", 5);
        set("item1", __DIR__"item/turou");

        set_temp("apply/dodge", 80);
        set_temp("apply/defense", 80);

	setup();
}
