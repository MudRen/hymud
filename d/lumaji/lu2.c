// Room: /d/lumaji/lu2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ����С�Ļ���С·бб�������ţ����Գ��ŸߵͲ������
�ݣ�͸���Ӳݣ�����Կ��������ɭ�֡�·�������б�Ų���һ
��ľ�ƣ�����д�š�¹������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lu3",
  "north" : __DIR__"lu1",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
