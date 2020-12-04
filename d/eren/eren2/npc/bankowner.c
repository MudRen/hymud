 // banker.c
#include <ansi.h> 
inherit NPC;
inherit F_BANKER;
void create()
{
        set_name("南宫十四郎", ({ "shisi" }) );
        set("title", RED "钱庄大少"NOR);
        set("gender", "男性" );
        set("age", 22);
        set("richness",5000000);
        set("cps", 30);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十四郎乃钱庄大少。\n"); 
        set("combat_exp", 2000000);
        set("attitude", "friendly"); 
        set("max_atman", 1000);
        set("atman", 1000);             
        set("max_neili", 1000); 
        set("neili", 1000);             
        set("max_mana", 1000);
        set("mana", 1000);              
        set("force_factor",50);
                

        
        set("inquiry", ([
                "抢劫" : "唉！山外的马贼真厉害啊！来无影，去无踪！\n",
                "rob" : "唉！山外的马贼真厉害啊！来无影，去无踪！\n",
        ]) ); 
        setup();
        
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}
