//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�¬��");
set("long", @LONG
�칬��һ��ƫ��������������֮ǰ���ڴ�ЪϢ��
ֻ�������ı����������ƷǷ���
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"bishagong",
  "north"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
