
// banker.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;


void create()
{
        set_name("�Ϲ���", ({ "hockshop owner","owner","hocker" }) );
        set("title", "�����ϰ�");
        call_out("add_room_money",1,this_object());
        set("gender", "����" );
        set("age", 26);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("where","north");
        set("long",
                
"�Ϲ����Ǹ��������൱˹�ĵ������ˣ�������ʱ�����Щ�Ĳ����ɵ�\n"
                
 "���ӣ���Զ�ľ�����Ϲ��ƶ������е�����Ī��ĸо���Ϊʲ����\n"
                
"����������Ϊһ�Ҵ����ϰ壬������һ��ϡ��Źֵ��书����\n"
                
"���Ϲ����ƺ������񵭣�������Щ���ߵķ�ǣ�ֻҪ���˲�ȥ������\n"
                "��Ҳ������ȥ�������ˡ�\n");

        set("combat_exp", 200000);
        set("attitude", "friendly");
//        set("pursuer", 1);
        set("env/wimpy", 70);

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set("chat_chance", 15 );
//        set("chat_msg", ({
//                (: random_move :),
//                (: exert_function, "powerfade" :),
//        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                CYN 
"��ϧ����Ц��Ц�������㣬���ϵ���������Ź֣���֪������Щʲ�᣿\n" NOR,
                CYN 
"��ϧ�ǵ���Ӱ����һ�£��ƺ��������ϸ�����Ѩ����һ�£�����Ҳ������Ĵ����\n" 
NOR,
                CYN 
"��ϧ�������Ȼ���������������������������Լ����£������޹ء�\n" NOR,
                CYN "��ϧ�Ǻ�Ȼ�ǺǺǵ�Ц��������ȴ��֪����ЦЩʲ��....\n" 
NOR,
                (: perform_action, "sword.counterattack" :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        
        setup();
        
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        add_money("silver", 10);
}

void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}