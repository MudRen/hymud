 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "方丈南院");
        set("long", @LONG
这里现在已经没有人住了，历代文人墨客，武学泰斗赠送方丈之物多存
放于此，其中尤以蔡京的“面壁塔额”最为出众。
LONG
        );
        set("exits", ([ 
                  "southup" : __DIR__"changjing",
                  "northup" : __DIR__"lixue",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",240);
        set("coor/z",40);
        setup();
}  
void init ()
{ 
        add_action("do_look", "look");
        add_action("do_north", "north");
        add_action("do_north", "n");
} 
int do_north(string arg)
{
        object me, room;
        me = this_player();
        if(me->query_temp("see_fangzhang")) {
                room = find_object(__DIR__"fang");
                if(!objectp(room)) room=load_object(__DIR__"fang");
                message("vision", me->name()+"向北离开。\n", environment(me),me );
                me->move(room);
                message("vision", me->name()+"走了过来。\n", environment(me),me );
                return 1;
        }
        return 0;
}  
/*
void init()
{
        if(!this_player()->query_temp("see_fangzhang"))
        {
                set("exits/northup",__DIR__"lixue");
                delete("exits/north");
        }
        else 
        {
                set("exits/north", __DIR__"fang");
                delete("exits/northup");
        }
}*/  
