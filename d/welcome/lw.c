#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "���䳡");
  set ("long", @LONG
���ǹŴ�����䳡��һ��¶��ĳ���������������õ�ɳ����
ľ�ˣ���������С������һλ���ߵ�֪���º�������ػӶ���ȭ�š�
LONG);
  set("exits", ([ /* sizeof() == 2 */

"south" : __DIR__"sleep2",
"north" : __DIR__"weapon",
"east" : __DIR__"fight",	
"west" : __DIR__"new1",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wu" : 1,
 
]));
set("roomif","$botten#��ʦ|ʦ���书|��������:bai wu bo|skills wu bo|job$#");	

  set("outdoors","welcome");
//  set("sleep_room", 1);

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}