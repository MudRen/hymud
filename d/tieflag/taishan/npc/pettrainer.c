 // Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ɳ����", ({ "shaluomen" }) );
        set("gender", "����" );
        set("age", 62);
        set("long","ɳ�����������ã����Թ�Ƨ��ר���붯��Ϊ�飬�ó�ѱ�ޣ���������\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );
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
 //       add_action("do_train", "train"); 
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "ɳ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������ô�ߣ�\n");
                        break;
                case 1:
                        say( "ɳ����̾������λ" + RANK_D->query_respect(ob)
                                + "���Ұ���ѱ�ޣ���ָ��һ���һؼҵ�·�ɡ�\n");
                        break;
        }
} 
