// Room: /d/lumaji/lu6.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
��������ʯ·�ϣ���ʱ�д��������߾�����·���ұ���һ
����Ժ����ʱ������е�������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu7",
  "east" : __DIR__"yuan",
  "north" : __DIR__"lu5",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
