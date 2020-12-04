 // banker.c
#include <ansi.h> 
inherit NPC;
inherit F_BANKER;
void create()
{
        set_name("南宫十三郎", ({ "nangong" }) );
        set("title", RED "钱庄掌柜"NOR);
        set("gender", "男性" );
        set("richness",500000000);
        set("age", 52);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十三也是南宫世家
的族人\n"); 
        set("attitude", "friendly");
        set("fly_target",1);
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_neili", 1000);
        set("force", 1000);             
        set("force_factor", 3);
        set("max_mana", 1000);   
        set("mana", 1000);              
        set("mana_factor", 3); 
        set_skill("dodge", 10);
        set_skill("parry",100);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
        add_money("coin", 1);


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