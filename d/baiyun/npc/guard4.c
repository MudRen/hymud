 // XXDER@FY3
inherit NPC;
void create()
{
    set_name("Ҷ��" , ({ "swords man","man" }) );
    set("long", "һ������ƮƮ��Ӣ�������İ��Ƴǽ�ʿ����\n");
        set("attitude", "friendly");
/*      set("max_jing", 500);
        set("max_jing", 500); */
    set("age", 19);
        set("gender", "����" );
/*      set("str", 35);
        set("cps", 25);         */
        create_family("���Ƴ�", 2, "��ʿ");
    set("combat_exp", 100000+random(1000));
    set_skill("dodge", 80+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 65);
        set_skill("feixian-sword", 50);
        set_skill("force", 60);
        set_skill("feixian-steps", 50);
        set_skill("qingpingforce", 55);
        map_skill("sword", "feixian-sword");
        map_skill("dodge", "feixian-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}   
