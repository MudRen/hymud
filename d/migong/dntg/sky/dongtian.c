
#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������칬�Ķ��š����Ĵ�����֮һ��ħ��츺���ء�����
�������������߿ɾ�������ˡ���Ȼ��ˣ���������Ŀ�˿��
���������ʺ�Ĵ������������������ͭ�����Ե�����Ƿ���
�����춡���������һ˿������Ѳ���š�

LONG);

  set("magicroom",1);set("exits", ([ /* sizeof() == 3 */
  "west"      : __DIR__"yunlue4",
  "south"      : __DIR__"tgqe4",
  "north"      : __DIR__"tgqe5",

]));

  create_door("west", "������", "east", DOOR_CLOSED);

  set("objects", ([
__DIR__"npc/moli-hong"   : 1,
__DIR__"npc/niulang"   : 1,
  __DIR__"npc/tian-bing"   : 5,
]));


  setup();
}


