#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "ɽ��" NOR, ({ "shan ji", "shan", "ji" }));
	set("long", WHT "����һֻ������Ϊ��׳��ɽ����\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 30);
	set("max_qi", 300);
	set("max_jing", 300);
	set("combat_exp", 1000);
set("race", "Ұ��");
        set("power", 5);
        set("item1", __DIR__"item/jirou");

        set_temp("apply/dodge", 80);
        set_temp("apply/defense", 80);

	setup();
}
