#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG
������һƬ�����أ�ԶԶ����������������������̣�������
��Ȯ��֮�����������Ҫ����Ļ��������������ִ������������ָ
�� ask hua about ���壩��
LONG);
  set("exits", ([ /* sizeof() == 2 */


"east" : __DIR__"welcome",	


]));
set("roomif","$botten#����:ask hua about ����$#");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hua" : 1,
 
]));
  set("outdoors","welcome");
  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}