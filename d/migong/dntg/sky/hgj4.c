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
  "south"   : __DIR__"yunluw3",
  "north"   : __DIR__"hgj5",
  "west"   : __DIR__"bingyinggate",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
