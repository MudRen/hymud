//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��ĸ��");
set("long", @LONG
    
һ�����Ĵ�֣���ֱ����չ��ȥ����������ס��
�����칬����Ȩ�Ƶ��ˣ�·�ľ�ͷ���������԰��
LONG );


set("magicroom",1);set("exits", ([
  "east"    : "/d/migong/dntg/laojun/gate",
  "south"   : "/d/migong/dntg/sky/yunlue3",
  "north"   : __DIR__"wmj5",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
