 // XXDER@FY3
inherit NPC;
void create()
{
        set_name("��η" , ({ "buwei", "jin buwei", "jin" }) );
        set("long", "������߰˳ߣ�������ͣ���������۲��۵�ç����\n");
        set("attitude", "friendly"); 
        set("age", 30);
        set("gender", "����" ); 
        create_family("��ƽɽׯ", 1, "����");
        set("combat_exp", 500000);
        
        set_skill("dodge", 50+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 65);
        set_skill("qingpingsword", 60);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 54);
        
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
