 // TIE@FY3
#include <ansi.h>
inherit NPC;
inherit F_BANKER;
void create()
{
        set_name("杨开泰", ({ "yang kaitai","yang" }) );
        set("title", RED "利源利通钱庄老板"NOR);
        set("gender", "男性" );
        set("age", 32);
        set("richness",5000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                "四四方方的脸，穿着件干干净净的布衣，整个人就像是块刚出炉的硬面饼。\n");
        set("combat_exp", 200000);
        set_skill("unarmed",100);
        set_skill("changquan",100);
        set("attitude", "friendly"); 
        set("max_neili", 1000);         set("neili", 1000);             
        set("force_factor", 30);
        set_skill("dodge",200);
        map_skill("unarmed", "changquan");
        
        set("inquiry", ([
                "风四娘" : "唉！恐怕又和萧十一郎在一起吧！\n",
        ]) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 10);
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
