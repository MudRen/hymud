
// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("coor",({-20,-50,0}));
	set("short", "�쾮");
	set("long",
"�����Ǵ�������е��쾮�������߿��Իص����������������鷿���ϱ����д����˵��᷿��\n"
"����һ������ͨ�������Ժ���쾮������������滨��ݣ���������һ��ʯ��(pillar)����\n"
"���ƺ������֡�\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guestroom",
  "north" : __DIR__"nyard",
  "east" : __DIR__"schoolhall",
  "west" : __DIR__"innerhall",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "ʯ���Ͽ���������ָ�졢������������â���ԡ�������硣
",
]));
	set("no_clean_up", 0);
set("outdoors", "ny");

	setup();
	replace_program(ROOM);
}
