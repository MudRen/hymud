#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"����"NOR, ({"huo wu", "huo wu"}));
        set("long",
               "����Ҫ���͵Ļ��\n");
        set("unit", "��");
        set("weight", 200);
        set("no_steal",1);
        set("no_beg", 1);
        set("no_put",1);
        set("no_pawn",1);
        //set("no_drop", 1);
        //set("no_get", 1);

        setup();
}


void owner_is_killed() { destruct(this_object()); }

