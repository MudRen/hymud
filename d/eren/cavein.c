 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石洞入口");
        set("long", "
一入洞，竟是别有一番景象，洞壁上几根儿臂似的牛油巨烛把四周照的亮堂堂的，
地上是碎石铺成的，最令人惊讶的是，这碎石竟然还砌成了一个狰狞的人像，青
面獠牙，左手持叉，右手执鞭。再往前是一个向下倾斜的甬道，甬道尽头有几个
人影晃动。\n"
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao1",  
                "down" : __DIR__"tocave",  	
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
