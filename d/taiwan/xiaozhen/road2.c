// Room: /d/taiwan/road2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
С����еķ��ӽ������������,ʱ��ʱ����Ц����ͯ�ڴ˼�������
ȥ,������ɹ���˸����С����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"undertree.c",
  "north" : __DIR__"villege",
  "east" : __DIR__"house3",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
