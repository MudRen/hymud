//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�칬��Ӫ");
set("long", @LONG
���������칬���ر����أ�������ֱͨ�칬��Ӫ��
����פ���ż�ʮ�������
LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"hgj4",
]));


  set("objects", ([
  __DIR__"npc/tian-bing"   : 8,
]));


set("outdoors", "dntg");

setup();
}
