
// Room: /d/snow/droad2.c

inherit ROOM;

void create()
{
        set("coor",({-20,5020,15}));
	set("short", "ɽ·");
	set("long",
"����һ���Ӳݴ�����С·���Ѷ���û���˴������߹���·��������Ϣ�ż�ֻ��ѻ����ʱ����\n"
"���������ë���Ȼ�Ľ���������ȥ��Լ�ɼ�һ����ɽ��\n"
);
	set("exits", ([ /* sizeof() == 2 */
    "north" : "/d/yanjing/to_yj",
  "southdown" : __DIR__"droad1",
]));
	set("outdoors", "ny");
	set("objects", ([
                __DIR__"npc/snake": 1 ]) );

	setup();
	replace_program(ROOM);
}
