 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
������ʮ���ᣬ����һת����ڰ���խ�Ķ�Ѩ������Ȼ����������ʯ
�����ԣ������Ű���㾧Ө�⻬��ʯ�飬���������еƹ�͸��ȴ�Ʋ�����
��Ƕ������ġ�
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao5",
                "westup" : __DIR__"yongdao3",
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
