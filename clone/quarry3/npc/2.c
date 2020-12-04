#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "����" NOR, ({ "zi diao", "zi", "diao" }));
	set("long", CYN "����һֻ�ж��쳣���ݵ�������\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 8);
	set("dex", 25);
	set("max_qi", 600);
	set("max_jing", 600);
	set("combat_exp", 3000);
set("race", "Ұ��");
        set("power", 7);
        set("item1", __DIR__"item/diaorou");
        set("item2", __DIR__"item/diaopi");

        set_temp("apply/parry", 60);
        set_temp("apply/dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 60);
        set_temp("apply/unarmed_damage", 30);
        set_temp("apply/armor", 30);

	setup();
}