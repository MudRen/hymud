// Room: /d/lumaji/lu5.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
һ����ʯ�̳ɵ�С·���м䳤��һЩ�Ӳݡ�·�������һ��
ũ����ס���ǵ��صĴ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nongju",
  "south" : __DIR__"lu6",
  "north" : __DIR__"lu4",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
