// Room: /d/linzhi/by14.c

inherit ROOM;

void create()
{
	set("short", "С����б·");
	set("long", @LONG
������С����б·�ϣ���ʱ�й���������������������ż
����Ҳ������һ�������̡����洫���������������죬������һ
�������̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"by15",
  "west" : __DIR__"smithshop",
  "northeast" : __DIR__"by13",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
