
// Room: /d/ustc/bforest/road11.c

inherit ROOM;

void create()
{
    set("coor",({1000,4650,10}));
	set("short", "����С��");
	set("long",
"����һƬï�ܵ�����,һ��������ͷ,��ֻ�������г�������,�Ա��п�ʯͷ,�Ͽ����Ѫ���\n"
"�� ������˵� ,���ܶ�������,���ƺ�����·��!\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road12",
  "north" : __DIR__"work",
]));
	set("outdoors", "ny");

	setup();
	replace_program(ROOM);
}
