 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Сʯ��");
        set("long", @LONG
ÿ�䶴�Ҷ������࣬��������˵���ܻ��������һ������ź�������
����Ĵ���ǽ������һ��������������ɷ����д�ż����֣�
        ��������ʿ����ɱ������ 
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"mouseroom2",
                
                        ]));
        set("objects", ([
                __DIR__"npc/mice3" : 1,
                __DIR__"npc/mice4" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
