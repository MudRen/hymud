#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"ˮ��ɽ��"NOR);
	set("long", WHT @LONG
    ��һ�����صĵط����˴���һ�����ܶ�Χ������ɽ�����ɽ��
ɽ�ȵĵ�������һ��Ư���ĺ�����������������Ĵ�����ұ��
�ʻ��̲ݣ����ҴӴ���ȥ��������ɼ����������Ǹ�������Դ��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(5)+4),
		"east" : __DIR__"dong7"+(random(5)+4),
		"south" : __DIR__"dong7"+(random(4)+1),
		"north" : __DIR__"dong79",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong79",
		"north" : __DIR__"dong7"+(random(4)+4),
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}