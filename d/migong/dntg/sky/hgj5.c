//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
    
���������칬���ر����أ�������ֱͨ�칬��Ӫ��
����פ���ż�ʮ���������Ӫ�Ա������������
����䡣
LONG );


set("magicroom",1);set("exits", ([
  "north"   : __DIR__"hgj6",
  "south"   : __DIR__"hgj4",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
