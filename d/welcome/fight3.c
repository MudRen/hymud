#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�ҷظ�");
  set ("long", @LONG
����һƬ���Ƿ�Ĺ����֪�����˶���Ӣ�ۺú������پ޼�
������˲�������������������˵ı���֮�⡣�������̻�
һ���������Ƕ���Ҳ�ܷ���ѣĿ�Ĺ�ʣ�һ��ˣ��㲻����
�𱯹۵���ͷ����Ѫ���ȣ��޲�������Ͷ�����������ȥ
��ȡ������ʷ��
LONG);
  set("exits", ([ /* sizeof() == 2 */
"northwest" : __DIR__"fight2",
"south" : "/clone/quarry/dong88",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yetu" : 10+random(10),
 
]));
  set("outdoors","welcome");
set("roomif","$botten#����|ɭ����ս:kill ye tu|south$#");	

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}