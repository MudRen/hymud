 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "登封县城");
        set("long", @LONG
青石街道随着越来越接近山区变得坎坷起来，由于来来往往的游客极多，
所以作为登少室山必经之路的登封县城分外的热闹，道路两边店铺林立，
上山所需的一切，这里应有尽有。
LONG
        );
        set("exits", ([ 
  "northeast" : "/d/songshan/taishique",
  //"west" : AREA_FUGUI"xiaodao1",
  "northwest" : __DIR__"qimu",
  "southeast" : __DIR__"bupu",
  "southwest" : __DIR__"tiepu",
]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
       ]) );
        set("outdoors", "songshanfy");
        set("coor/x",-200);
        set("coor/y",100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
