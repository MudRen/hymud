#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "Í»Ó¥" NOR, ({ "tu ying", "tu", "ying" }));
	set("long", CYN "ÕâÊÇÒ»Ö»¼È³óÂª£¬ÓÖÍşÎäµÄÍºÓ¥¡£\n" NOR);
        set("aves", 1);

	set("age", 1);
	set("str", 35);
	set("dex", 50);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("combat_exp", 30000);
set("race", "Ò°ÊŞ");
        set("power", 32);
        set("item1", __DIR__"item/yingrou");

        set_temp("apply/parry", 150);
        set_temp("apply/dodge", 150);
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/unarmed_damage", 80);
        set_temp("apply/armor", 100);

	setup();
}
