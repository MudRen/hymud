 // Room: dong0
inherit ROOM;
#include <room.h> 
void create()
{
        set("short", "ɽ϶��");
        set("long", @LONG
����ɽ�ڼ�һ��һ�߶���ɽ϶���������ڱ��ϵ������������ڣ�
������ϸ̽����ѷ��֡�
LONG
        ); 
       set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"troad3",
  "westdown" : __DIR__"dong1",
 
]));
         
      set("coor/x",150);
        set("coor/y",0);
        set("coor/z",20);
        setup();
        replace_program(ROOM); 
} 
