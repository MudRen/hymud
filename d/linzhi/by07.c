// Room: /d/linzhi/by07.c

inherit ROOM;

void create()
{
	set("short", "���л���ʯ·");
	set("long", @LONG
�����ڻ���ʯ·�ϣ���ʱע�������ܵ������·���ദ�ʷ�
���������һ�Ҳ�ҩ�̣����������⻹����������һ��С·
ͨ��賡��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by06",
  "west" : __DIR__"by13",
  "north" : __DIR__"by08",
  "east" : __DIR__"jewelshop",
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
