//sgzl 
 
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "������");
  set ("long", @LONG
ֻ���������ţ��̳�����������ͣ����ϻϣ�����ױ�ɡ�
���߰���Ա����Ԫ˧��һԱԱ������������ϳӵ츣���
����ʮ����������ˣ�һ����ִ����ޣ��ֵ��̽���

LONG);

  set("magicroom",1);set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dadao6",
  "north" : __DIR__"jieyindian",
  "west" : __DIR__"tgqs4",
  "east" : __DIR__"tgqs5",
]));

  create_door("north", "������", "south", DOOR_CLOSED);

  set("objects", ([
  __DIR__"npc/moli-qing"   : 1,
  __DIR__"npc/tian-bing"   : 4,
]));


  set("outdoors", "dntg");

  setup();
}
 
