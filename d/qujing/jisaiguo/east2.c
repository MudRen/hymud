#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����¶���");
  set ("long", @LONG

·�����⽨����£���ɫ����ǽ�������������쵽�Ǳߣ���ǽ��
���������ϸ���ɫ��Ƭ���ֵ��ܿ��������������࣬·��ܸɾ���
����Ϊɮ�˾�����ɨ��Ե�ʡ�·����Ӵ������򣬼���Сͯ��·
����ˣ��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"east1",
  "south" : __DIR__"east3",
]));

  setup();
}
