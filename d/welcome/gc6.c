#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����㳡");
  set ("long", @LONG
���ǹŴ������㳡��¶��ĳ���������������õ�ɳ����
ľ�ˣ���������С�����ں�������ػӶ���ȭ�š�
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"gc5",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jl" : 3,
 
]));
set("roomif","$botten#����|����:duilian jiao tou|duilian jiao tou$#");	

  set("outdoors","welcome");
//  set("sleep_room", 1);

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}