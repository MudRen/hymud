 // woodcutter.c
inherit NPC; 
void create()
{
        set_name("�Է�", ({"woodcutter"}) );
        set("gender", "����" );
        set("age", 36);
        set("agi",30);
        set("per", 10);
        set("str",100);
        set("long",
                "�Է��������Ŀ�����ǰ�Ĵ�����\n"
                );
        set("max_jing", 500);
        set("max_qi", 500);
        set("max_sen", 500);
        set("eff_jing", 500);
        set("eff_qi", 500);
        set("eff_sen", 500);
        set("jing", 500);
        set("qi", 500);
        set("sen", 500);
        set("combat_exp", 9999);
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
        set_skill("axe",50);
            setup();
            carry_object(__DIR__"obj/woodaxe")->wield();
            carry_object("/clone/misc/cloth")->wear();  
}    
