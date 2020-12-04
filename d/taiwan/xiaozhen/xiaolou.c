// Room: /d/taiwan/xiaolou.c

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����һ�������С¥,��������������,�����ﾲ���ĵ�,ûһ����
Ӱ,��紵��,���ƺ�����������Ů�Ŀ���,���������Ϣһ�¡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huayuan",
  "north" : __DIR__"tingtang",
]));
	set("outdoors", "/d/taiwan");
  set("sleep_room",1);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/obj/jiudai" : 1,
  __DIR__"npc/obj/mifan" : 1,
  __DIR__"npc/obj/kaoya" : 1,
  __DIR__"npc/obj/niurou" : 1,
]));
	setup();
	replace_program(ROOM);
}
