 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "草原");
        set("long", @LONG
远远可以望见许多高低起伏的房屋，前方是一座无名的边城，这儿住的有汉人，
也有藏人。偶尔几匹快马驰过，奔向前方，马上骑者皆是行色匆匆，风尘仆仆，腰
间鼓鼓囊囊，显见都携着兵刃，密鼓般的蹄声，转瞬即逝。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"wild6",
        "northwest" : "/d/biancheng/road1",
        ]));
	set("objects", ([
"quest/skills2/wunon/dalie/dalie" : 2,

	])); 
        set("outdoors", "zangbei");
        set("coor/x",-1090);
        set("coor/y",170);
        set("coor/z",0);
        setup();
} 
