#include <room.h>
inherit ROOM;


void create()
{
        set("short", "山路");
        set("long", @LONG
这一带川南地区，多是崇山峻岭，连绵起伏的群山间夹着许多山谷，羊肠小
道从中蜿蜒而过。山上多是瘟瘴遍布人迹罕至之处，也偶尔有些山蛮族人的村寨，
豺狼野兽时时在遮天蔽日的密林之下活动。
LONG
        );
        set("exits", ([
                "southwest"     : __DIR__"dukou2",
                "northup"         : __DIR__"shanlu02",
        ]));
        setup();
        set("outdoors","xinan");
}
