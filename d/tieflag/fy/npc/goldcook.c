 // fatman.c
inherit NPC; 
void create()
{
        set_name("���", ({ "cook" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һ�����վ�տ�Ĵ��.\n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 130);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        setup();
    add_money("gold", random(2));
        carry_object(__DIR__"obj/jinzhuang")->wear();
        carry_object(__DIR__"obj/luwei");
        
}
