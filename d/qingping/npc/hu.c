 // XXDER@FY3
inherit NPC;
void create()
{
        set_name("������" , ({ "buchou", "hu buchou", "hu" }) );
        set("long", "ֻ����ͷ����̣���ǿ�����������ȻδЦ��Ҳ���ż���Ц�⡣\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 19);
        set("gender", "����" );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        create_family("��ƽɽׯ", 1, "����");
        set("combat_exp", 350000);
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
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}   
