#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(HIY"黄金面具"NOR, ({ "golden mask","mask" }) );
        set_weight(1000);
        set("long","一个黄金雕刻而成的面具，巧夺天工精致无比。\n");
        set("unit", "个");
        set("value", 1000);
        set("material", "cloth");
        set("armor_type", "mask");
        set("fakegender", "男性");
        set("armor_prop/id", ({"sun legate"}));
        set("armor_prop/name", ({"太阳使者"}));
        set("armor_prop/short", ({"武当老掌门(wudang master)"}) );
        set("armor_prop/short", ({HIY"太阳使者"NOR+"(sun legate)"}) );
}
