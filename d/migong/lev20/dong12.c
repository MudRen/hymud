
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�þ�"NOR);
	set("long", HIG @LONG
ΰ������������ҫ�����ɭ���У�����ɭ����ҫ��
һƬ���ɫ�Ĺ���С��ڸߴ����ָ��������������밫
��ľ,  �㷢�����Ѿ���·�ˡ� 
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong34",
		"east" : __DIR__"dong1"+(random(3)+1),
                "south" : __DIR__"dong1"+(random(3)+1),
                "north" : __DIR__"dong1"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(4)+1),
                "west" : __DIR__"dong1"+(random(3)+1),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong34",
                "north" : __DIR__"dong1"+(random(3)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev4" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}