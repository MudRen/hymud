 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "黄山山门");
        set("long", @LONG
这是一座石雕门坊，过了石门后，便是黄山，从石门望去，只见万峰叠翠，入 
眼一片翠绿。群峰连绵百里，峰顶云雾缭绕，苍松翠柏迎来游人无数。路北有一小 
酒肆，供游人歇脚。 
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"wenquan",  
  "north" : __DIR__"jiusi",  
		"southwest" : "/d/henshan/hsroad2",
]));
        set("objects", ([
        __DIR__"npc/3cheng" : 1,
"quest/skills2/wakuang/kuang/kuangmai" : 2,
                        ]) );
        set("outdoors", "huangshan");
        set("coor/x",-510);
        set("coor/y",-510);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
