//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��ƽ��");
set("long", @LONG
��ƽ�� �������������ܻ��������ߴ�
��ΰ���������������߰��������ûʡ�       
    
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"taiyanggong",
  "north"   : __DIR__"qianyuangong",
]));


set("objects", ([
]));



setup();
}
