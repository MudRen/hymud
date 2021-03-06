// 钱庄老板 /d/city/chuzhou/npc/bankboss.c
// by lala, 1997-12-13

#include <ansi.h>
inherit NPC;
inherit F_BANKER;

void create()
{
    set_name( "陈日禾", ({ "chen rihe", "chen", "boss", }) );
    set( "title", MAG"钱庄"GRN"老板"NOR );
    set( "gender", "男性" );
    set( "age", 58 );
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    set( "long", @LONG
陈日禾是本地钱庄的老板，他有多少家产没有人能说清楚，而且他在外面放了许
多高利贷，大收印子钱，在城中的评价不是怎么太好。作为这么个大富翁，他还
是每天亲自到店面上来盯着。
LONG
    );
    set( "attitude", "friendly" );
    set( "talk_msg",({
       "“现在我没有什么新鲜的东西，过两天就有了，等等看。”",
    }));
     
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
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
