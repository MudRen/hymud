// Room: /d/taiwan/midao2.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
һ����ڵ��ܵ�,�����������������ܹ�������,�㲻�Ҵ���,С�ĵ�
���Ŵֲڵ�ʯ����ǰ��.ǰ���ƺ�¶��������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lengchuanyun.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"midao1",
  "out" : __DIR__"huayuan",
]));

	setup();
	replace_program(ROOM);
}
