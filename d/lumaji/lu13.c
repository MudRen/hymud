
inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С·��·�����׾��Ǳ�������Ի��ң�����
ȥ��һƬ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([

  "west" : __DIR__"liehu",
  "south" : __DIR__"lu12",
]));

	set("objects", ([
		"/clone/npc/man" : 2,
	]));

	set("outdoors", "lumaji");
	setup();


	replace_program(ROOM);
}
