
// Room: /d/snow/hockshop2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",
"�����Ƿ�ǵ��̵Ĵ����ң���ʱ������Ĵ󳯷�������治�µ����������ó���������\n"
"����������ֻ�ܿ���һ�������������ӡ������ߴ���һ�����Ϳ��Իص����̵��档\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hockshop",
]));

	setup();
	replace_program(ROOM);
}
