// Room: /d/yeyangzai/chalu.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
����Ǹ���·�ڣ����������ͨ���ϱ���Ҫ�����������˶�����������
��ͨ��̨���Լ�ɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : "/d/taiwan/dabajianshan",
  "north" : __DIR__"xiaolu",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
