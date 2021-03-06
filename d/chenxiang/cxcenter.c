 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM; 
void midnight_event();
void sunrise_event(); 
void create() {
        set("short", "老城广场");
        set("long", @LONG
这里是当年沉香镇的中心，广场的北面是一条小河流，河流的旁边有
一块大青石，就当做船夫的上岸的小码头。江南不愧被赞为鱼米之乡，这
里已经成为沉香城的农货市场了。
LONG);
        set("exits", ([
                        "north" : __DIR__"cx4",
                        "south" : __DIR__"cxs1",
                        "east" : __DIR__"cxe1",
                        "west" : __DIR__"nanbank",
                        ]));
        set("objects", ([
                        __DIR__"npc/fishseller": 1,
                        __DIR__"npc/fishbuyer": 1,
                        //"/p/residence/npc/xiaolang" : 1,
                        ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-500);
        set("coor/z",0);
        setup();
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
void midnight_event() {
        object badguy;
        object room = this_object();
        int i, bandit_no = 3 + random(7);
        
        if(!random(20)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("蒙面土匪", "/clone/misc/cloth", "/obj/weapon/blade_guitou", "cx");
                                badguy->move(room);
                           badguy->ccommand("chat 月黑杀人，风高放火！");
                        }
                }
                NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
        } else {
                NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
        }
} 
void sunrise_event() {
        object *ob_list;
        int i;
        
        ob_list = children("/obj/npc/bandit");
        for(i=0; i<sizeof(ob_list); i++) {
                if(ob_list[i]->query("area_mark") == "cx") {
                        if(environment(ob_list[i])) {
                                message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}  
