//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ǬԪ��");
set("long", @LONG
ǬԪ�� �������������ܻ��������ߴ�
��ΰ���������������߰��������ûʡ�     
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"shenpinggong",
  "north"   : __DIR__"lingxiao",
]));

set("no_npc",1);
set("objects", ([
]));



setup();
}
