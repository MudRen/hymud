
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ƺӶɿ�");
  set ("long", @LONG
�����ǻƺӶ����Ķɿڡ���ǰ�ǹ����Ļƺӣ�ֻ�м�������������
�ڶ����������ˡ�
LONG);

  set("exits", ([ 
  "west":__DIR__"dukou2",
  "south":__DIR__"shanxi/huanghe4",

  "east":__DIR__"road3",
         ]));
set("outdoors","taiyuan");
  set("valid_startroom", 1);
  setup();
 
}

