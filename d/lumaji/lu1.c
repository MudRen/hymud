// Room: /d/lumaji/lu1.c

inherit ROOM;

void create()
{
	set("short", "¹������");
	set("long", @LONG
һ����С�Ļ���С·бб�������ţ����Գ��ŸߵͲ������
�ݣ�͸���Ӳݴԣ������ɭ�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/d/kunming/nanmen",
  "south" : __DIR__"lu2",
]));
	set("outdoors", "lumaji");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
