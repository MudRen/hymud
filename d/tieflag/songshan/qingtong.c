 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "青童峰");
        set("long", @LONG
太室东的高峰，险峻却苍翠，下临卢崖瀑布，两侧峰下几座小小
的庙宇，由于这里险峻而且偏僻，所以游人也不太多，但是许多隐士
高人却多爱在此长伴青山绿水。修练佛，道乃至武学。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"luya", 
]));
        set("outdoors", "songshanfy");
        set("objects", ([
                __DIR__"npc/shuzhen" : 1,
       ]) );
        set("coor/x",-180);
        set("coor/y",130);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
