 inherit ROOM;
void create()
{
        set("short", "�ߵ�");
        set("long", @LONG
�ݺ�����һ���ߵ����ߵ������ǵ�̾��µ�ʯ�ڣ�����Ƕ�ŷ�����ͭ�ƣ�
��һ�Ⱥܴ�ľ�ʯ���磬��ס���ߵ��ľ�ͷ��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"palace4",
                "north" : __DIR__"bathroom",
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
