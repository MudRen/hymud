//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��·");
set("long", @LONG
̤�����������칬��·������Ʈ�������ƣ������˼�ũ��
��Ʈ����������̣����˱����Ŀ�������
LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"yunluw2",
  "west"   : __DIR__"yunluw4",
  "north"   : __DIR__"hgj4",
  "south"   : __DIR__"hgj3",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
