 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
��·���ˣ�һ���ӿ��������������ߣ�������ģ�������ɴ��ƺ�
���и��Ҷ�����ϧ��������ס�ˡ�������������һ���ֲ�ڣ���ʯ·
�����򶫱����죬��߶�����ʯ·��������������ȥ�ġ�
LONG
        );
        set("exits", ([ 
                "westup" : __DIR__"exit1",
                "east" : __DIR__"court2",
                "southeast" : __DIR__"yongdao7",
                        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
