 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
��·��խ�� 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"jailroad1",
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
