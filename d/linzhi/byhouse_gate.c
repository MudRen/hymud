// Room: /d/linzhi/byhouse_gate.c

inherit ROOM;

void create()
{
	set("short", "�͸�����");
	set("long", @LONG
������������ү���ڴ���ǰ��ֻ���������Ų��ۣ��ֳ�����
�İ͸����������վ���ſڡ��������������װͰ͵Ŀ����㡣��
������̫���ǡ�

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
 // "east" : __DIR__"byhouse_gate",
  "west" : __DIR__"by05",
  "north" : __DIR__"by06",
]));

  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/cityguard" : 2,  	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
