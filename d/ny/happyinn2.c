
// Room: /d/snow/happyinn2.c
#include <ansi.h>
inherit ROOM;
int mark_book;
void create()
{
	set("coor",({-40,4950,10}));
	set("short", "�ɶ�Ҫ���᷿");
	set("long",
"����һ����������Է���������һ�ſ��Ĵ������еİ�����Ȼ�ܺ���������͸��һ����\n"
"���������Ǿ�����һЩ�Ź֣����ֿ���������\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"happyinn0",
  "west" : __DIR__"happyinn",	
]));
	set("no_clean_up", 0);
	mark_book=1;
	setup();
}


