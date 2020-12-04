// fenglin_du.c
inherit ROOM;

void create()
{   
    set("short","风陵渡");
    set("long",@LONG
黄河在此上下数百里，风陵渡是最大的一个渡口。相传为黄帝献八阵图大败
蚩尤的风后就葬在这里，因此地名唤为“风陵渡”。百余米宽的急流之上，横架
着一座铁索木板浮桥，岸边各有巨大的铜牛将铁索栓住。岸上有个小村庄，村口
一家客栈，上书“安渡”二字。南岸即是潼关。
LONG );
    set("exits",([
        "southwest" : __DIR__"tongguan", 
        "northeast" : __DIR__"zhongtiao_shan1"  ]) );
    set("outdoors","zhongyuan");
    setup();
}

