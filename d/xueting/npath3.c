// Room: /d/snow/npath3.c
inherit ROOM;
void create()
{
        set("short", "Ϫ��С·");
        set("long", @LONG
����������һ��Ϫ�����ϵ�С·��Ϫˮ��������ʯ��ĺӴ���
��������������һ��ľ�ſ��Ϫ������ͨ�������С·������Ϫ��
���ϲ�Զ�����������һ��ĥ����
LONG
        );
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 3 */
                //"east" : "/d/green/shuichi",
                "northwest" : __DIR__"npath2",
                "south" : __DIR__"lane2",
]));
        setup();
        replace_program(ROOM);
}
