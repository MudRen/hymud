 // worker.c
inherit NPC; 
void create()
{
        set_name("��������", ({ "gateman" }) );
        set("gender", "����" );
        set("age", 52);
        set("long", "���������Լ��ʮ��ͷ��һ�����׵��������ӣ����ϵ��������кü���\n"
        "���̣�һ�����Ǵ����˶������������ϱ����ӣ�ͨ��ľ�����ӣ�����\n"
        "���������񣬶���������������ĵĲ��Ǳ�ģ�ֻ��������Ǹ����ƺ�!!\n"); 
        set("combat_exp", 20000);
        set("attitude", "heroism");
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("sword",80);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        setup();
        add_money("coin", 2);
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
        
}      
