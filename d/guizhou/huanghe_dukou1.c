
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghe_dukou1"
#define TO __DIR__"huanghe_dukou2"
#include "shiproom.c"

void create ()
{
  set ("short","�Ͻ��ɿ�");
  set ("long", @LONG
�������Ͻ��Ķɿڡ���ǰ�Ͻ�ˮ���������ƾ��ˡ�ֻ��һҶ��������
�������ˡ�
LONG);

  set("exits", ([ 
"south":__DIR__"huanghe_dukou2",
  "north":"/d/henshan/hsroad4",
  "east":__DIR__"huanghe4",
         ]));
set("outdoors","guizhou");
  set("valid_startroom", 1);
  setup();
 
}
