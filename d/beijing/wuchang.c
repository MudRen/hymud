#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"�����˴��"NOR);
	set("long", @LONG
����һ�����䳡���ɾ޴�Ļ�����ʯ���̾ͣ������п������˱����ᡣ
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"kang2",
	]));
	set("objects",([
                "/kungfu/class/hu/fu" : 1,
                "/kungfu/class/hu/feng2" : 1,
                "/kungfu/class/hu/wudang" : 1,
                "/kungfu/class/hu/shaolin" : 1
	]));
	set("coor/x", -179);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
