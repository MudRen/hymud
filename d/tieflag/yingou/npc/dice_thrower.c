#include <ansi.h>
inherit NPC;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
int *low_index = ({});
void pay_him(object who, int amount);
void clear_stat();
void pre_cal();
void create()
{
        int i,amun;
        set_name( "黄麻子", ({ "huang", "huang ma zi" }) );
        set("long", "这是银钩赌坊的职业赌手，骰子上的功夫出神入化。\n");
        set("attitude", "friendly");
        set("title", HIW "银钩手"NOR);
        set("force_factor", 30);
        set("reward_npc", 1);
        set("difficulty", 40);
        set("fly_target",1);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_neili", 2000);
        set("neili", 2000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("age", 33);
        set_temp("apply/damage",600);
        set("gender", "男性" );  
        set("str", 35);
        set("cor", 30);
        set("cps", 25);
        set("per",5);
        set("lower_limit",1);
        set("too_late",0);
        set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0); 
        set("force_factor",250);
        set_skill("throwing",300);
        set_skill("unarmed",200);
        set_skill("dodge",500);
   set("combat_exp", 50000000);
        setup();
        carry_object(__DIR__"obj/yingoupao")->wear();
        carry_object(__DIR__"obj/guzi")->wield(); 
}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       // add_action("do_bet", "bet");
        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "黄麻子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来赌两手，开开心吧。\n");
                        break;
                case 1:
                        say( "黄麻子晃了晃手中的骰子，叫道：这位" + RANK_D->query_respect(ob)
                                + "，小赌可以养家糊口，大赌可以定国安邦。来吧！\n");
                        break;
                case 2:
                        say( "黄麻子说道：这位" + RANK_D->query_respect(ob)
                                + "，进来！进来！ 输了算我的！\n");
                        break;
        }   
        return; 
}
 