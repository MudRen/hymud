 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "龙虎寨");
        set("long", @LONG
这地方叫龙虎寨，就在密林后，四面群山环抱，奇峰矗立，看来就像是一只野
兽，正张大了嘴在等着择人而噬。住在这里的人，也正像是一群野兽。谁也不愿意
被野兽吞下去，所以这地方非但很少看得见陌生人，连飞鸟都已几乎绝迹。
LONG
        );
        set("exits", ([ 
                "northwest" : __DIR__"forest3",
        ]));
        set("objects", ([
                __DIR__"npc/baimian":   1,
                __DIR__"npc/tulaohu":   1,
                __DIR__"npc/oneeye":    1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1000);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
//      NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
/*
void reset() {
        object badguy,*inv,room=this_object();
        int count,i;
        
        ::reset();
        
        inv=all_inventory();
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->name()=="山寨喽罗")
                        count++;
        }
        if (count<4) {
                badguy=new(__DIR__"npc/bandit");
           badguy->set("attitude", "friendly");
                badguy->move(room);
                badguy->command("say 大王,小的准备好了。");
        }
}
        
*/ 
/* 
void midnight_event() {
        object badguy;
        object room = this_object();
        int i, bandit_no = 2 + random(5);
        
        if(!random(10)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("山西土匪", "/clone/misc/cloth", "/obj/weapon/blade_guitou", "fy");
                                badguy->move(room);
                                badguy->command("chat 月黑杀人，风高放火！");
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
                if(ob_list[i]->query("area_mark") == "fy") {
                        if(environment(ob_list[i])) {
                                message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
*/      
