// Room: /d/linzhi/by13.c

inherit ROOM;

void create()
{
	set("short", "С����б·");
	set("long", @LONG
������С����б·�ϣ���ʱ�й���������������������ż
����Ҳ������һ�������̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"house03",
  "east" : __DIR__"by07",
  "southwest" : __DIR__"by14",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
