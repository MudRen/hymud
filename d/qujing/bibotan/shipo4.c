#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

��ʯ����ʯ��أ����С�ĵ������ǡ����ϼ����������ľΨ
�к���������ɽ������һ�ź��ơ��򶫿ɿ����̲�̶��һ��̶ˮ
������Χ��ɽ�С�
LONG);


  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shipo2",
]));

  setup();
}

