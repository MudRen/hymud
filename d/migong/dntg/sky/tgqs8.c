//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�칬��ǽ");
set("long", @LONG
�ߴ���ΰ���칬��ǽ���������������ߣ�����
��ǽ��ȥ������һ�ڣ��岽һ�ڡ��䱸ɭ�ϡ�
LONG );


set("magicroom",1);set("exits", ([
"west"   : __DIR__"tgqs7",
"north"   : __DIR__"tgqe1",
]));


set("objects", ([
    __DIR__"npc/winter-gongcao" : 1,
]));



set("outdoors", "dntg");
setup();
}