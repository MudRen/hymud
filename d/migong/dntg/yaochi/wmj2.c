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
  "north"   : __DIR__"wmj3",
  "south"   : __DIR__"wmj1",
  "east"   : "/d/migong/dntg/yunlou/gate",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
