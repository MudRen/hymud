//huoji.c.伙计
//date:1997.8.28
//by dan

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string ask_for_room();

void create()
{
    set_name(MAG"伙计"NOR, ({ "huo ji"}) );
    set("title","泰仁堂");
    set("gender", "男性" );
    set("age",17);

    set("inquiry", ([
                "废墟" : (: ask_for_room :),            
    ]) );
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	__DIR__"obj/jinchuang_yao",
	}));


    set("talk_limit/combat_exp",10000);
    set_temp("talk_npc_number", 10);
    set("talk_player_number/xingqing_huoji",3); 
    set("talk_mark/xingqing_first",4);
    set("talk_msg",({
" 药铺后面有一片废墟。\n",
        }) );

    setup();       
}   
    
void init()
{
    ::init();        
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 

string ask_for_room()
{      
       object me;
       me = this_player(); 
       tell_object( me, "你可以随便翻翻，上次我在里面还找出一个金项圈呢！\n");                                   
       tell_object( me, YEL"伙计带你穿过药铺，来到一片废墟上。\n"NOR);                                                        
       me->move("/d/xibei/xingqing/feixu");    
       return "你可以随便翻翻，上次我在里面还找出一个金项圈呢！\n";
}

