// Room: /d/linzhi/lin41.c

inherit ROOM;

void create()
{
	set("short", "��ԭ�µ�");
	set("long", @LONG
�����Ǹ�ԭ�µ������͵��±ڲ���������ߣ��·���ʱ����
������һ�㡣�㲻�ɵüӿ��˽Ų����������һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin39",
  "south" : __DIR__"lin42",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
