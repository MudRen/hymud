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
  "east"   : __DIR__"yunlue3",
  "west"   : __DIR__"yunlue1",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
