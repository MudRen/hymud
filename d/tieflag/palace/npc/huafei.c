inherit NPC;
void create()
{
        set_name("����", ({ "huafei" }) );
        set("gender", "����" );
        set("age", 18);
        set("per", 58);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300);
        create_family("������", 2, "����");
        set("fly_target",1);
        set("max_neili", 100);
        set("neili", 50);
        set("force_factor", 1);
        set("attitude", "aggrensive");
        
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.longwujiutian" :),
        }) ); 
        set("long","����������£������������԰׶��忡�������ϣ�����һ�ݹ°���
��֮ɫ���·�δ���κ��˿������
\n");
        set("combat_exp", 200000);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 90);
        set_skill("zuixian-steps", 70);
        set_skill("thunderwhip",10);
        set_skill("iceheart",10);
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ķ�����һ�ۡ�\n",
        }) );
        setup();
        carry_object(__DIR__"obj/zhanpao3")->wear();
        add_money( "silver" , 10);
}       
