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
  "south"   : __DIR__"wmj5",
  "west"   : "/d/migong/dntg/pantao/gate",
  "east"   : __DIR__"gate",
]));





set("outdoors", "dntg");

setup();
}
