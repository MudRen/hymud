#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "����" NOR, ({ "hei xiong", "hei", "xiong" }));
	set("long", CYN "����һֻ���ľ޴������쳣�ĺ��ܡ�\n" NOR);

	set("age", 8);
        set("str", 50);
        set("dex", 20);
        set("con", 50);
        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("combat_exp", 500000);
set("race", "Ұ��");
        set("power", 50);
        set("item1", __DIR__"item/xiongrou");
        set("item2", __DIR__"item/xiongpi");


        set_temp("apply/force", 220);
        set_temp("apply/parry", 220);
        set_temp("apply/dodge", 220);
        set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/unarmed_damage", 280);
        set_temp("apply/armor", 280);

	setup();
}
