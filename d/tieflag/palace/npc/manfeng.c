inherit NPC;
void create()
{
        set_name("������", ({ "manfeng" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("per", 58);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 300);
        set("mana", 300);
        create_family("������", 2, "����");
        set("fly_target",1);
        set("max_neili", 100);
        set("neili", 50);
        set("force_factor", 5);
        set("attitude", "aggrensive");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.longwujiutian" :),
        }) ); 
        set("long","���ǵ����ȹ�����Ů��\n");
        set("combat_exp", 200000);
        set("score", -50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 90);
        set_skill("zuixian-steps", 50);
        set_skill("thunderwhip",10);
        set_skill("iceheart",10);
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
   setup();
        carry_object(__DIR__"obj/zhanpao1")->wear();
        add_money( "coin" , 50);
}    
