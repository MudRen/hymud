// Room: /d/snow/npath2.c
inherit ROOM;
void create()
{
        set("short", "Ϫ��С·");
        set("long", @LONG
������һ��Ϫ�ߵ�С·������������������ߵ�ɽ��һ���ٲ�
�����ϴ��£�����ɽ���ϵ�һƬ���֣��Լ���Զ���Ĳݵأ������
���ϱ�������Ϫˮ�弤��Ϫ������ʯ�������ܴ����������������
С·���Իص�ѩͤ��Ĵ�֣�С·���Ͽ���ͨ��Ϫ�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"npath3",
                "west" : __DIR__"npath1",
]));
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
