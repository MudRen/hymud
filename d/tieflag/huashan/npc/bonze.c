 // woodcutter.c
inherit NPC; 
void create()
{
        set_name("����ɮ", ({"bonze", "travel bonze"}) );
        set("gender", "����" );
        set("age", 36);
        set("agi",25);
        set("per", 10);
        set("str",30);
        set("long",
                "һ�������ķ��Ľ���ɮ��\n"
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
        set("combat_exp", 2000);
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
            setup();
            carry_object(__DIR__"obj/cloth")->wear();  
                carry_object(__DIR__"obj/shoe1")->wear();
} 
