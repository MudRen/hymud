#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯��������
ָ�� sleep����
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"lw",
"south" : __DIR__"gc1",

]));

set("roomif","$botten#˯��:sleep$#");
  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"jing" : 1,
 
]));
  //set("outdoors","welcome");
  set("sleep_room", 1);

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object ob;

me->set_temp("nbjob3",1);
	
	return ::valid_leave(me, dir);
}