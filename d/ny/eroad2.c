
// Room: /d/snow/eroad2.c

inherit ROOM;

void create()
{
	set("coor",({1200,4700,10}));
	set("short", "����С��");
	set("long",
"����һ����ͨ�Ļ���С����С��������ͨ��һ��ɽ���ƽ�أ�����������������ٷ��ݴ���\n"
"��ƽ���ϣ���������һ·��ɽ��\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"eroad3",
  "southwest" : __DIR__"eroad1",
]));
	set("outdoors", "ny");

	set("objects", ([
		__DIR__"npc/dog": 2 ]) );

	setup();
	replace_program(ROOM);
}
