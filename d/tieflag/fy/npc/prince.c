 // Tie @ fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小公子", ({ "prince", "little prince"}) );
        set("gender", "男性" );
        set("age", 12);
        set("long", "这是当今皇上的小公子，最受宠爱的一个\n");
        set("class","official");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        set_skill("dodge", 200);
        set_skill("leadership",101);
        set_skill("strategy",100);
        set("intellgent",1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "小公子信口道：狂"+HIR"风"NOR+"一翻滚，何处不是"+HIG"云"NOR+"。\n",
        }) );

        setup();
        add_money("silver", 1);
        carry_object(__DIR__"obj/fycloth")->wear();
}        
