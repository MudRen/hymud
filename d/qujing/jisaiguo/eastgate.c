#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����������");
  set ("long", @LONG

����͵��˼������Ķ��ţ���·�ǳ��Ŀ��㣬����ݵ���ʮ����
�ۡ���ֱ����·ֱͨ����У�������ͽ����·����������������
������֮������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guard" : 2,
]));
  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
//  "east" : __DIR__"pingxi",
  "west" : __DIR__"crosseast",
  "east" : __DIR__"to-baoxiang1",
]));

  setup();
}
