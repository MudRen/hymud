
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",MAG"净念禅院大门"NOR);
  set ("long", @LONG
这里就是净念禅院的门口了，有烧香的人在出出进进。诵佛经的声
音传出里许。门口有个僧人在招呼着进出的行人。静念禅院的名声极大，
所以平时来这里的人也是很多。
LONG);

  set("exits", ([ 
	  "enter":__DIR__"shilu1",
	  "down":"/d/taiwan/dabajianshan",
  
         ]));
  set("objects",([
	  __DIR__"npc/heshang":1,
	  ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();

 
}

