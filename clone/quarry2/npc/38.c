#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "ɽ��" NOR, ({ "shan zhu", "shan", "zhu" }));
	set("long", WHT "����һֻ�ǳ����͵�ɽ��\n" NOR);

	set("age", 1);
	set("str", 35);
	set("dex", 40);
	set("max_qi", 1600);
	set("max_jing", 1600);
	set("combat_exp", 30000);
set("race", "Ұ��");
        set("power", 28);
        set("item1", __DIR__"item/zhurou");

        set_temp("apply/parry", 150);
        set_temp("apply/dodge", 150);
        set_temp("apply/attack", 130);
        set_temp("apply/defense", 130);
        set_temp("apply/unarmed_damage", 130);
        set_temp("apply/armor", 220);

	setup();
}
