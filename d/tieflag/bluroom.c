#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",BLU "蓝室"NOR);
  set("long",@LONG
屋中竟有一个大水池，池水很清，很蓝，阳光透过窗户照到池水上，再倒映到天
花板上，整间小室都融在波光之中。池水中有几头金鱼悠闲地游动，一个身着蓝衫的
少女若有所思地坐在池边。
LONG
  );
        set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/blugirl" : 1,
       ]) );
  
  set("coor/x",70);
        set("coor/y",0);
        set("coor/z",-30);
        setup();
  replace_program(ROOM);
}  
