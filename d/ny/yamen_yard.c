
// Room: /d/snow/yamen_yard.c
#include <room.h>
inherit ROOM;

void create()
{
	set("coor",({-70,4870,10}));
	set("short", "���Ŵ�Ժ");
	set("long",
"����������ǰ�����Ŵ�Ժ���������������������ǳ����֣��������˽����š���ʱ��һ��������\n"
"�������С�\n"
);
	set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yamen_gate",
  "west" : __DIR__"yamen",
]));
	set("no_clean_up", 1);


	setup();
	replace_program(ROOM);
}
