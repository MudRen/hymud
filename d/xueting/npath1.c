// Room: /d/snow/npath1.c
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ������С·���������Իص�ѩͤ�����Ҫ�ֵ���������
һƬ�ݵأ��ݵؾ�ͷ����һƬ���֣����������������ȵ�ˮ������
Զ����������һ��ɽϪ��
LONG
        );
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"npath2",
                "west" : __DIR__"street01",
]));
        setup();
        replace_program(ROOM);
}
