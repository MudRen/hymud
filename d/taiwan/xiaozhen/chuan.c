// Room: /d/taiwan/chuan.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
һ��װ���˻������ΦС��,���������ܾ��ܺ��ϵĴ����.�и�
СС�Ĵ�����ǿ��������Ϣ.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liusan.c" : 1,
]));
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"matou",
]));
          set("no_fight", 0);

	setup();
	replace_program(ROOM);
}
