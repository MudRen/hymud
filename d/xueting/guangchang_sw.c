// Room: /d/snow/square_sw.c
inherit ROOM;
void create()
{
        set("short", "�㳡����");
        set("long", @LONG
������ѩͤ��㳡�����ϱߣ��㳡����Ĵ�����������Ķ���
����Զ��������ı��߿��Կ���һ�ҿ�ջ��������һ���ֵ�������
����һ��·�ڿɿ���һ�Ҵ������ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"wstreet1",
                "east" : __DIR__"guangchang_s",
                "north" : __DIR__"guangchang_w",
	])
	);
        set("outdoors","xueting");
        setup();
}
