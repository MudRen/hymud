#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + YEL "����" NOR, ({ "song shu", "song", "shu" }));
	set("long", YEL "����һֻë���׵Ĵ�����\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 28);
	set("max_qi", 250);
	set("max_jing", 250);
	set("combat_exp", 1000);
set("race", "Ұ��");
        set("power", 5);

        set_temp("apply/dodge", 60);
        set_temp("apply/defense", 60);

	setup();
}
