 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��");
        set("long", "
�����£�ÿ��ʮ��߱��������ĵ���\n"
        );
        set("exits", ([ 
//                "northdown" : __DIR__"yongdao2",
                "southup" : __DIR__"cavein",
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
