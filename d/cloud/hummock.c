
// Room: /u/cloud/dragonhill/hummock.c

inherit ROOM;

void create()
{
        set("coor",({1000,4450,20}));
	set("short", "������");
        set("long",
"����λ��ѩͤ�����������һ��ɽ������˵ɽ��ʱ����ǿ����·���١�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"nhillfoot",
  "southdown" : __DIR__"shillfoot",
]));

        set("objects", ([
                __DIR__"npc/gangster" : 5
]) );

        set("outdoors", "cloud");

        setup();
}
