// Room: /d/snow/square_e.c
inherit ROOM;
void create()
{
        set("short", "�㳡����");
        set("long", @LONG
������ѩͤ��㳡���ߣ���������һ��Ƨ�������ӣ�������һ
��ߴ���������ϱ���һ�Ҵ������ӣ��������Ų�����һ�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"epath",
                "west" : __DIR__"guangchang",
]));
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
