//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����");
set("long", @LONG
�칬��һ��ƫ��������������֮ǰ���ڴ�ЪϢ��
ֻ�������ı����������ƷǷ���
LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"tongmingdian",
  "west"   : __DIR__"yunluw1",
]));


set("objects", ([
]));



setup();
}
