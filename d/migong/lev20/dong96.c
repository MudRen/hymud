#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ҵ���Ĺ"NOR);
	set("long", HIM @LONG
���Ǵ�˵�й���ĵ���Ĺ��ͨ·������Ʈ����һ�ſ�����
�ĺ�ˮ�������ܵ�ǽ�ں��컨���������������ıڻ��;���
��ʯ������ɢ�������صĹ�â��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"eastup" : __DIR__"dong97",
            	"westdown" : __DIR__"dong9"+(random(4)+3),
		"south" : __DIR__"dong9"+(random(4)+3),
		"north" : __DIR__"dong9"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(2)+6),
		"north" : __DIR__"dong9"+(random(2)+6),
	]));

if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+3),
            	"east" : __DIR__"dong97",
	]));
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/player" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}