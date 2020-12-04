 inherit ROOM;
#include <ansi.h> 
void create() 
{ 
        set("short", "上山小径"); 
        set("long", @LONG 
一条上山小径，弯弯曲曲，通向山里。小径两旁是茂密的松树林。小路的地面上长 
着厚厚的青苔，好象很久没有人来这里了。 
LONG 
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
        "south" : __DIR__"road4", 
 //       "northup" : "/d/wangyou/up_path" , 
])); 
        set("outdoors", "fengyun"); 
        set("coor/x",30); 
        set("coor/y",1000); 
        set("coor/z",100); 
 
        set("coor/x",30); 
        set("coor/y",1000); 
        set("coor/z",100); 
        setup(); 
//        replace_program(ROOM); 
} 
int valid_leave(object me, string dir) 
{ 
        me=this_player(); 
        if( dir == "northup" && 100/((int)me->query_skill("move")+1)>random(250)) 
        { 
        message_vision(HIR"$N一不小心，摔了下来。\n "NOR,me); 
                me->receive_wound("qi",1); 
                return notify_fail(HIW"这座山可真难爬呀，好累哟。。。。^_^ ^_^\n"NOR); 
                } 
        return 1; 
} 
         
