 inherit NPC;
inherit F_VENDOR;
//inherit F_FLOWERSELLER;
#include <ansi.h> 
void create()
{
        set_name("������", ({ "huaman" }) );
        set("gender", "����" );
        set("age", 81);
        set("title", BLU "����"NOR);
        set("long",
                "��λ�ϰ�������¶�������Ц�ݡ�\n");
        set("combat_exp", 350000);
        set("attitude", "friendly");
        set("per",20);
        set("vendor_goods", ({
                __DIR__"obj/purple_flower",
                __DIR__"obj/red_flower",
                __DIR__"obj/yellow_flower",
                __DIR__"obj/blue_flower",
                __DIR__"obj/white_flower",
                __DIR__"obj/black_flower",
        }));
        set_skill("unarmed",50);
        set_skill("dodge",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
        add_action("assign_delivery","delivery");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$NЦ��˵�����������ʻ��䣬��Щ��ȥ����������˰ɡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$NЦ�����˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô������\n",this_object(),ob);
                        break;
        }
}     
