//heshang.c.和尚
//date:1997.8.27
//by dan 

#include <ansi.h>
inherit NPC;

int ask_for_bi();

void create()
{
    set_name(YEL"和尚"NOR, ({ "heshang" }) );
    set("title","承天寺");
    set("gender", "男性" );

    set("inquiry", ([
                "承天璧" : (: ask_for_bi :),            
    ]) );

    setup();     
}

int ask_for_bi()
{       
    object ob;
    ob = this_player();
    if ( ob->query("bellicosity") <= 100 )
    return notify_fail("你瞎打听这些干什么...?\n");
    write("你不要杀我那块璧好象在后院内的塔...\n");
    return 1;
}






