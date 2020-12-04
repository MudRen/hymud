//dianzhu.c.店主
//date:1997.8.27                            
//by dan   

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
 
string ask_for_jiu();    

void create()
{
    set_name(MAG"店主"NOR, ({ "dianzhu" }) );
    set("title","商号");
    set("gender", "男性" );
    set("combat_exp", 100000);
    set("max_qi", 400);
    set("max_sen", 300);

    set_skill("dodge",900);
    set_skill("sword",900);
    set_skill("unarmed",900);
    set("attitude", "friendly");
    set("env/attack", 78); 
	set("vendor_goods", ({
__DIR__"obj/maozhan",
	}));
  

    set("inquiry", ([
                "葡萄酒" : (: ask_for_jiu :),   
    ]) );    

    set("talk_limit/combat_exp",10000); 
    set_temp("talk_npc_number", 10);
    set("talk_player_number/xingqing_dianzhu",3);
    set("talk_mark/xingqing_first",3); 
    set("talk_msg",({
"这里几年前发生过大火，所有屋子都烧毁了，这是这几年重建的。\n",
        }) ); 

    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/jian3")->wield();
}    

void init()
{
    ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}  

string ask_for_jiu()
{       
        return "我这里也只有几瓶了,我不卖。除非用太阿剑来换.\n";
}

int accept_object( object me, object obj)
{
        if ( ( obj->query("id")!="tai a jian" ) )
        {
                command("say 多谢美意，不过这东西对我好象没有什么用。");
                return 0;
        }
        if ( obj->query("id")=="tai a jian" )
        {
                obj = new(__DIR__"obj/jiu1");
                obj -> move( me );
                message_vision("店主给$N一瓶葡萄酒。\n", me);
                return 1;
        }

}






