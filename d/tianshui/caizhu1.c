// Room: /u/xiaozhen/caizhu1.c

inherit ROOM;

void create()
{
	set("short", "��Ҵ���");
	set("long", @LONG
���������ˮ����׸������ҵĴ����ˣ�һ��ʯʨ����ס
���ŵ����࣬�ſڵ���������д��һ�����顱�֣������������
������������ǹ������űߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sroad2",
  "east" : __DIR__"caizhu2",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wolf_dog" : 2,
]));

	setup();
	replace_program(ROOM);
}
