//kezhan.c

inherit ROOM;

void create()
{
        set("short","凉州客栈");
        set("long", @LONG
凉州最大的客栈，共有两层，楼下供客人吃饭休息，楼上供客人睡觉
休息。这里离闹市的距离恰好不远不近，你若想做生意出门向东就到，你
若想休息，闹市的喧闹也到不了这里。所以客栈的生意十分得兴隆。来来
往往的过客到凉州多半要住在这里，店主是一位西夏人，据说和这里的官
府关系密切。
LONG
        );
        set("exits", ([ 
                "south"         :       __DIR__ "lroad4",
                ])
        );
//      replace_program(ROOM);
        setup();
}

