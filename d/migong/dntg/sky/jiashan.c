
#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "��ɽ");
  set ("long", @LONG

�칬��Ժ�ļ�ɽ���ļ���ʢ�����ʻ�������һ��һľ��
��¶�������緶��
LONG);

  set("magicroom",1);set("exits", ([ /* sizeof() == 3 */
  "north"      : __DIR__"beitian",

]));

  create_door("north", "������", "south", DOOR_CLOSED);

  set("objects", ([
]));


  setup();
}


