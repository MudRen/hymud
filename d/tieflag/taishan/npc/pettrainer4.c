 // Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "wanghu" }) );
        set("gender", "����" );
        set("age", 22);
        set("long","һ�����θߴ�ĺ���\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("chat_chance", 1);
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
//        add_action("do_train", "train"); 
} 
