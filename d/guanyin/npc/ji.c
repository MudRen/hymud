 inherit NPC;
void create()
{
        set_name("������", ({ "bingyan" }) );
        set("gender", "����" );
        set("age", 42);
        set("str",30);
        set("long",
                "����������������з�ȵļ�����\n");
        set("combat_exp", 1000000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "������������������ô˵�ģ���\n",
                "�����������������Ҳ����\n",
        }) ); 
        set("attitude", "friendly");  
    set_skill("unarmed", 100);
    set_skill("force", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("kongshoudao", 120);
    set_skill("ghosty-force", 150);
    set_skill("ghosty-steps", 100); 
    map_skill("unarmed", "kongshoudao");
    map_skill("force", "ghosty-force");
    map_skill("dodge", "ghosty-steps"); 
        setup();
        carry_object(__DIR__"obj/bcloth2")->wear(); 
}      
