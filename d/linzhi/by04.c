// Room: /d/linzhi/by04.c

inherit ROOM;

void create()
{
	set("short", "���л���ʯ·");
	set("long", @LONG
���������ֻ��·�������������������������æµ�š�
·�ı�����һ������ʯľ�����¥������Ӧ��������Ψһ�Ŀ͵�
�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"by03",
  "east" : __DIR__"by05",
  "west" : __DIR__"by16",
  "north" : __DIR__"inn",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
"/clone/npc/man" : 1, 	
]));

        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
