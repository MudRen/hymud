// Room: /d/lumaji/lu3.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С·��ʯ���г���һЩ�Ӳݣ�ʱ������
����ˮͰ�����ﾭ����������ͷҲ��̧���߿��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu4",
  "east" : __DIR__"jing",
  "north" : __DIR__"lu2",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
