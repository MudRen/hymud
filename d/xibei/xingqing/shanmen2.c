//door6.c.高台寺山门
//shanmen2.c:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"高台寺山门"NOR);
    set("long",@LONG
高台寺是元昊所建，用以贮宋王朝所赐《大藏经》，常有回鹘高僧来译经讲
法，寺院位于城东，控扼东去辽宋都城驿道黄河渡口。一条驿道直通向远方, 面
前是山门。山门用厚厚的杉木制成，上面包铜，镶满巨大的铜钉。山门正上方悬
着一块黑漆大匾，上面写着<<高台寺>>三个大字。由于这是西夏皇家寺院所以有
铁鹞军前来巡逻。
LONG);
   
    set("exits",([
        "north"   : __DIR__"road28",
        "south"   : __DIR__"qiandian2",
    ]));
    set("outdoors","xingqing");
    setup();
}

