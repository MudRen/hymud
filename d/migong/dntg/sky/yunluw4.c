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
  "east"   : __DIR__"yunluw3",
  "west"   : __DIR__"xitian",
]));


set("objects", ([
]));



set("outdoors", "dntg");

  create_door("west", "������", "east", DOOR_CLOSED);

setup();
}
