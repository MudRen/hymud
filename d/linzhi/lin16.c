// Room: /d/linzhi/lin16.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǲ����ˣ��ش����ض��ϲ����˴��ز��ر�󣬺ӹ�
����ش�����ֻ��1600�����ң�����÷��ѩɽ��������������ƽ
������5000�����ϣ���߷���6740�ס�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"lin17",
  "west" : __DIR__"lin21",
  "north" : __DIR__"lin15",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1600);
	setup();
	replace_program(ROOM);
}
