// Room: /d/taiwan/house.c

inherit ROOM;

void create()
{
	set("short", "���ļ�");
	set("long", @LONG
һ��ܼ�ª��é�ݷ���.�����ʵĹ�����,�ܿ�����ϡ������ľ��.�� 
�õ�һ��ľ�����ϻ�����������,����ʮ������. ���������Ϣһ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"villege",
]));
  set("sleep_room",1);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fisherman.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
