#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "����" NOR, ({ "bian fu", "bian", "fu" }));
	set("long", WHT "����һֻ�����������ڶ�����\n" NOR);
        set("no_auto_kill", 1);
        set("aves", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 28);
	set("max_qi", 220);
	set("max_jing", 220);
	set("combat_exp", 1000);
set("race", "Ұ��");
        set("power", 3);

        set_temp("apply/dodge", 60);
        set_temp("apply/defense", 60);

	setup();
}
