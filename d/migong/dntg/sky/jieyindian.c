// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������ţ��Ѿ����Կ���һ�����칬�����߲�ϼ�⣬��������
����������֮�С�������м������������ϲ����Ž���ҫ�ճ���
����һ�����������������������죬�������߸���һ����
Ҳ��֪�Ǹ�ʲô�õģ��������Լ�������ߵ���������֮������
���˲��١�

LONG);

  set("magicroom",1);set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nantian",
  "north" : __DIR__"caihongqiao",
  "west" : __DIR__"caifengdian",
  "east" : __DIR__"jinlongdian",
]));

  create_door("south", "������", "north", DOOR_CLOSED);
        set("no_clean_up", 0);

  setup();
}
 
