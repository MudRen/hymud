// Npc : zhang.c 张员外
// hydra

#include <ansi.h>
inherit NPC;

string ask_me( object );

void create()
{
    set_name( "张员外", ({ "zhang yuanwai", "zhang" }) );
    set( "attribute", "friendly" );
    set( "gender", "男性" );
    set( "age", 45 );
    set( "long", @LONG
张员外也是个读书人，早年赶考没中，回来操持家业，发达了起来。
他心地善良，不时接济穷人，所以在凉州很得人心。
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );   
   
    set("inquiry",([
        "老方丈"  :   (:ask_me:),
        "方丈"    :   (:ask_me:),
    ]) );
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

string ask_me( object ppl )
{
    ppl = this_player();
    if ( ppl -> query_temp("凉州/allow_enter" ))
    {
        tell_object(ppl,CYN"张员外道：原来你是老方丈介绍来的，你一定要救救小女啊。\n"NOR);
        ppl->set_temp("凉州/can_enter_gelou",1);
        return "老夫感激不尽大师的大恩大德！";
    }
    else
    {
        return "你是问大云寺的老方丈吧，他在隔壁的大云寺里住着。";
    }
}
