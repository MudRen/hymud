//dangpu.c

inherit HOCKSHOP;

void create()
{
        set("short","成记当铺");
        set("long", @LONG
紧临闹市的当铺,门口的招子随风飘荡,上面黑圈蓝底中写着斗大的一
个"当"字.因为许多来自遥远中原的商人有出不了手的货物,而又急着回家
,所以干脆将货物在这里当掉,所以当铺生意十分兴隆.
LONG
        );
        set("exits", ([ 
                "north"         :       __DIR__ "center",
                ])
        );
//      replace_program(ROOM);
        setup();
}

