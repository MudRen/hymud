//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�칬��ǽ");
set("long", @LONG
�ߴ���ΰ���칬��ǽ���������������ߣ�����
��ǽ��ȥ������һ�ڣ��岽һ�ڡ��䱸ɭ�ϡ�
LONG );


set("magicroom",1);set("exits", ([
"west"   : __DIR__"tgqs6",
"east"   : __DIR__"tgqs8",
]));


set("objects", ([
   __DIR__"npc/tianshen" : 1,
 __DIR__"npc/jinnaluo" : 1,
  __DIR__"npc/qiandapo" : 1,
]));



set("outdoors", "dntg");
setup();
}
