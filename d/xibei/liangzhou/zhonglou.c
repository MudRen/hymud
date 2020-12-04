//zhonglou.c

inherit ROOM;

void create()
{
        set("short","钟鼓楼");
        set("long", @LONG
西夏国君为记念西夏立国而修的钟鼓楼，从楼下宽敞的门洞进去后再
沿两侧的石梯盘旋而上就到了楼顶的钟亭，一口熟铜打铸的大钟用碗口粗的
钩子挂在亭内的大梁之上。大钟周围用汉文和西夏文两种文字刻着铭文.
LONG
        );
        set("exits", ([ 
                "south"         :       __DIR__ "lroad5",    
                "north"         :       __DIR__ "gubei",
                ])
        );
//      replace_program(ROOM);
        setup();
}

