// Room: /d/zuojiacun/haichan.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����̣���Ȼ����ȴ���򵽶������ʵĺ���Ʒ����
���㡢����ʲô�ġ�����Ҳ�����⣬�����۸��Թ���һЩ������
�޹Ѹ��Ǹ����ˣ����������˺󣬴�����������ʮ�ֲ��ס�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu5",
]));
  	set("objects",([
	__DIR__"npc/butcher" : 1,
]));
	setup();
	replace_program(ROOM);
}
