#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG
����һ�����ѵ���ʯ�̾͵�С·����ͨ���ɽ��Ψһ�ĵ�
·��·���Կ�����֪����Ұ����������Ʈ��������һƬ����
����԰��⡣
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"kezhan",	
"east" : __DIR__"fight2",	
"west" : __DIR__"lw",

]));
set("roomif","$botten#����:kill ye tu$#");	
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yetu" : 10+random(10),
 
]));
  set("outdoors","welcome");
//  set("sleep_room", 1);

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}