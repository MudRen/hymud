// Room: /u/cass/hg/neishi.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ӵʹ���������������ʲô�������Աߣ�����һ���¹����װ��м���ľ��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dafotang",
]));
	set("objects", ([
		__DIR__"npc/real-queen":1,
	]));

	setup();
	replace_program(ROOM);
}
