 // worker.c
inherit NPC; 
void create()
{
        set_name("����Ů��", ({ "naked girl", "girl" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("long", "�����Է�ҶȪˮ���˵�Ů��\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
        set_skill("dodge", 100);
        set_skill("throwing", 50);
        set("max_qi",400);
        set("eff_qi",400);
        set("qi",400); 
        setup();
}  
