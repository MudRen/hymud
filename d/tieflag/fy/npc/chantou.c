 // worker.c
inherit NPC; 
void create()
{
        set_name("���ͽ", ({ "chantu", "tu" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("title","��������");
        set("long", "һ��������������ͽ\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
        set_skill("dodge", 40);
        set_skill("throwing", 50);
        set("max_qi",400);
        set("eff_qi",400);
        set("qi",400); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}   
