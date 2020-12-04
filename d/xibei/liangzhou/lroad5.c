//lroad5.c

inherit ROOM;

void create()
{
        set("short","沙土路");
        set("long", @LONG
凉州城的中心道路，西边是凉州的西门，虽说凉州是大城，但城中路
面并不平整，行人走过，尘土飞扬。尽管如此，对那些从西方艰苦跋涉而
来的旅人，到这里就意味着他们可以找个地方放松一下疲惫的身心，忘掉
西方漫漫的黄沙和一望无际的荒野，
北边是一座钟鼓楼，南边是一家茶庄，往东就是凉州城的主干道，从那里
通往城中心。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "east"          :       __DIR__ "lroad4",
                "west"          :       __DIR__ "ximen",
                "south"         :       __DIR__ "chadian",
                "north"         :       __DIR__ "zhonglou",
                ])
        );
//      replace_program(ROOM);
        setup();
}

