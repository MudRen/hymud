 //XXDER/TIE
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��������", ({ "shu sheng"}) );
    set("gender", "����" );
    set("age", 39);
    set("int", 30);
    set("long",
        "һ��Ӣ��ͦ�ε������ˣ�����ȥ����ζ�����أ��������űʣ����ڶ���һ"
        "���������˼��\n");
        set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 2000000);
        set("force",1000);
        set("max_force",1000);
        set("force_factor",20);
        set_skill("dodge", 150);
        set_skill("sword", 160);
        set_skill("parry",150);
        set_skill("qingpingsword", 120);
        set_skill("force", 160);
        set_skill("qingpingforce", 150);
        set_skill("chaos-steps", 150);
        set_skill("unarmed",150);
        set_skill("bai-quan",220);
        
        map_skill("unarmed","bai-quan");
        map_skill("parry","qingpingsword");
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) );
    
    create_family("��ƽɽׯ", 2, "����");
    set("rank_nogen",1);
    set("ranks",({"��ͯ","����","��ʿ","����","����","����"}));
    set("rank_levels",({64000,256000,1536000,3456000,26244000})); 
    
    setup();
    carry_object(__DIR__"obj/pcloth")->wear();
    carry_object(__DIR__"obj/shoe")->wear();
    carry_object(__DIR__"obj/pen")->wield();
} 
