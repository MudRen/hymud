//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��������");
set("long", @LONG
�������� �������������ܻ��������ߴ�
��ΰ���������������߰��������ûʡ���ʴ��
���������롣
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"qianyuangong",
  "north"   : __DIR__"hougong",
//  "west"   : __DIR__"hougong",
//  "east"   : __DIR__"hougong",
]));


set("objects", ([
  __DIR__"npc/yuhuang"   : 1,
//"/d/qujing/wuzhuang/npc/laojun"   : 1,
  __DIR__"npc/wuquxingjun"   : 1,
]));



setup();
}
