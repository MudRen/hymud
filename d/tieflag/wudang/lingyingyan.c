 inherit ROOM;
void create()
{
        set("short", "��Ӧ��");
        set("long", @LONG
������������ɽ��С���������Ӧ���ٷ塱���׳ơ�����������
����ÿ��Ķ��������ﶼ�������ƣ������Ը߲��ɲ�ĸо���
LONG
        );
        set("exits", ([
                "south" : __DIR__"wuroad3",
        ]));
        set("outdoors", "wudangfy");
        set("objects", ([
                __DIR__"npc/taoist4" : 1,
                __DIR__"npc/taoist_1" : 1,
        ]));
        set("coor/x",130);
        set("coor/y",-120);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}   
