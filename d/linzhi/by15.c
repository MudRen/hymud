// Room: /d/linzhi/by15.c

inherit ROOM;

void create()
{
	set("short", "С����б·");
	set("long", @LONG
������С����б·�ϣ���ʱ�й���������������������ż
����Ҳ������һ�������̡������ʷ���һ��Ǯׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by16",
  "west" : __DIR__"teashop",
  "northeast" : __DIR__"by14",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
