 inherit ROOM;
void create()
{
        set("short", "青衣楼");
        set("long", @long
不知不觉这段路已经走了过来，无论是战战兢兢提心吊胆，还是轻轻
松松，毕竟都已走过了。路本是同样的路，只看你怎样去走而已。人生的
路也是这样子的。朱红色的门是闭着的．门上却有个大字「推」。
long
        );
        set("exits", ([ 
  //"east" :__DIR__"alou",
  //"east" : __DIR__"yuan1",
  //"west" : __DIR__"shulin1",
  "west" : __DIR__"tolou5",
  
]));
        set("item_desc", ([
                "door": "无论什麽样的门，都能推得开的，也只看你肯不肯去推，敢不敢去推而已(push)。\n",
                "门" : "无论什麽样的门，都能推得开的，也只看你肯不肯去推，敢不敢去推而已(push)。\n",
                "朱红色的门" :"无论什麽样的门，都能推得开的，也只看你肯不肯去推，敢不敢去推而已(push)。\n"
        ]) );

        set("outdoors", "shanxi");
        set("coor/x",-480);
        set("coor/y",-260);
        set("coor/z",100);
        setup();
}
void init()
{
        add_action("do_push", "push");
}
void close_path()
{
        if( !query("exits/enter") ) return;
        message("vision",
        "门忽然被人关上。\n",
                this_object() );
                delete("exits/enter");
}  
int do_push(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="door" || arg =="朱红色的门" || arg=="门") {
                write("你大力地吸了口气，尝试着去推门。\n");
        if( random(100) >= 10 )
                {
                write("门一下就被推开了。\n");
                if( !query("exits/enter") ) {
                set("exits/enter", __DIR__"alou2");
                call_out("close_path", 10);
                                                }
                return 1;       
                }
                else
                write("门突然打开，一股牛芒似的黑针迎面飞来，你躲避之间，依然中了两叁口。\n");
                me->receive_damage("qi",500);
                me->start_busy(3);
                return 1;
        }
                write("你要推开什么？\n");
                return 1;
} 
   