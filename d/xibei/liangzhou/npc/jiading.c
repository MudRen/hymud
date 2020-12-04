// Npc : jiading.c
// hydra

#include <ansi.h>
inherit NPC;

string ask_me( object );

void create()
{
    set_name( "家丁", ({ "jia ding", "ding" }) );
    set( "attribute", "heroism" );
    set( "gender", "男性" );
    set( "age", 27 );
    set( "long", @LONG
一个家丁，中等身材，面无表情的站在那里。
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
    
    set( "talk_msg", ({
        "去去，一边去。。。\n",
        "嗯。家丁皱了皱眉头，一副不爱理人的样子。\n",
        "你能不能别来烦我？\n"
    }) );
    
    set("inquiry",([
        "小姐"    :   "哎。。。",
        "恶人"    :   "这帮恶人真是天杀的，不得好死！",
        "老方丈"  :   "你是问大云寺的老方丈吧，他在隔壁的大云寺里住着。",
        "方丈"    :   "你是问大云寺的老方丈吧，他在隔壁的大云寺里住着。",
    ]) );
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}


