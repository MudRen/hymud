// Room: /d/taiwan/midao1.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
һ����ڵ��ܵ�,�����������������ܹ�������,�㲻�Ҵ���,С�ĵ�
���Ŵֲڵ�ʯ����ǰ��.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lengtanyue.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"midao2",
  "up" : __DIR__"midao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
