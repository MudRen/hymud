//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
������ �������������ܻ��������ߴ�
��ΰ���������������߰��������ûʡ� 
LONG );


set("magicroom",1);set("exits", ([
  "west"   : __DIR__"xuanyuantang",
  "east"   : __DIR__"xinyuegong",
]));


set("objects", ([
]));



setup();
}
