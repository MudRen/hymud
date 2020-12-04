 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "翡翠池");
        set("long", @LONG
在松谷溪边，星罗棋布着六个池潭。平时潭水清澈平静，每当微风吹动，涟漪
微荡，好似龙鳞，所以叫龙潭。依照水色分为赤，青，乌，白，老，更有一潭，水
深形美，所以被称为翡翠池。四周石桌，石栏，悬崖题刻，应有尽有，别有风味。
据说闻名天下的龙化剑便是依此五潭悟出，也不知真假。
LONG
        );
    set("exits", ([ 
                "east" : __DIR__"sroad",
        "eastup" : "/d/heifeng/lu1",
        ]));
    set("objects", ([
        __DIR__"obj/pond1" : 1,
        __DIR__"obj/pond2" : 1,
        __DIR__"obj/pond3" : 1,
        __DIR__"obj/pond4" : 1,
        __DIR__"obj/pond5" : 1,
        __DIR__"obj/pond6" : 1,
"quest/skills2/wunon/yu/yutan" : 2	,
    ]) );
        set("turtle_home", 1);
    set("outdoors", "huangshan");
        set("coor/x",-660);
        set("coor/y",-540);
        set("coor/z",30);
        setup();
} 
int release_turtle(object turtle) {
        if(turtle->name() != "绿毛小乌龟") {
                return 0;
        }
        call_out("turtle_return", random(30) + 10, this_player());
        return 1;
} 
void turtle_return(object me) {
        object ob;
        
   if(environment(me) == this_object()) {
                message("vision", "\n\n绿毛小乌龟费力地游了上来，背上竟然驮着一个盒子。 \n", this_object());
                message("vision", "绿毛小乌龟把盒子推在翡翠池边，然后潜进水里不见了。 \n", this_object());
                if(!me->query("m_success/天灵翡翠")){ 
                me->set("m_success/天灵翡翠",1); 
                me->add("score",3000); 
                } 
                ob = new(__DIR__"obj/box");
                if(objectp(ob)) {
                        ob->move(this_object());
                }       
        }
}      
