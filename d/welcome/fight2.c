#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG
ɽ·���������˾�ͷ����ǰͻȻ����һƬ�Ѽ��Ŀ���������
����һƬ��ʯ������Сɽ�ڣ�ֻ����Щʯͷǧ�˰�̬��������
������⣬�������ֹ����������
LONG);
  set("exits", ([ /* sizeof() == 2 */



"west" : __DIR__"fight",
"southeast" : __DIR__"fight3",

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