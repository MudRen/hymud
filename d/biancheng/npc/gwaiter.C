#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("���ĵĻ��", ({ "good waiter" }) );
        set("gender", "����" );
        set("age", 33);
        set("richness",1000000000);
        set("combat_exp", 50);
        set("no_arrest",1);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
message_vision("$N˵������λ"+RANK_D->query_respect(ob)+
"����ζ��ţ�⣬�Թ�����\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N˵����"
+ "ٯ���ǽ���������ֵǮ�Ķ���������ɣ��������̫��ǿ���ˣ�\n",this_object(),ob);
                        break;
                case 2:
message_vision("$Ņͷ��ɨ��һ�����ܣ��ף���һ��ȥ����ס�\n"
,this_object(),ob);
                        break;
                                }
}  