// Room: /d/lumaji/lu15.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ߵ����ֻ����·�߶���һ���ɲ񣬲�ѱ�����һ��
ƽ��������ȥ������һƬ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu14",
  "east" : __DIR__"lu16",
  "north" : __DIR__"ws_home",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
