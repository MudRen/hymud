 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "鸣弦泉");
        set("long", @LONG
面前一高崖耸立，崖下绿草如茵，有泉水自高山石壁骤然落下，冲击一块横卧
山麓，左厚右薄中空，状如古琴的岩石上，发出“叮咚，叮咚”悦耳而有节奏的
音响。曾有古诗赞道“却按工商仔细听，二十五弦俱不在”。
LONG
        );
    set("exits", ([ 
                "east"  : __DIR__"sandie",
        ]));
        set("objects", ([
        __DIR__"obj/stone3" : 1,
                        ]) );
        set("outdoors", "huangshan");
        set("coor/x",-570);
        set("coor/y",-520);
        set("coor/z",0);
        set("mingxuan", 1);
        setup();
} 
void init() {
        add_action("do_search", "search");
} 
int do_search(){
        object me, stone;
        
        me = this_player();     
        if (me->is_busy())
                return notify_fail("你现在正忙。\n");
        me->start_busy(1);
        if (me->query("marks/黄山鸣弦泉") && query("mingxuan",1)) {
                message_vision("$N仔仔细细的在泉边崖壁上搜寻。\n", me);
                message_vision("$N发现岩石的一角有些松动。 你用力一扳，竟脱落下来。\n", me);
                stone = new(__DIR__"obj/ystone");
                stone->move(me);
                set("mingxuan",0);
           return 1;
        } 
        tell_object(me,"你胡乱摸索了一阵，结果什么也没找到。\n");
        return 1;
}  
void reset(){
        ::reset();
        if (!random(4)) set("mingxuan",1);
}  
                      
