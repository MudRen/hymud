inherit NPC;


void create()
{
        set_name("��԰��", ({ "shouyuan ren","shouyuan","ren" }) );
        set("gender", "����" );
        set("age",65);
        set("social_exp",2000);
        set("combat_exp",10000);
	set_skill("unarmed", 70);
        set("force",200);
        set("max_force",200);
        set("force_factor",10);
       	set("chat_chance", 20);
        setup();
        carry_object(__DIR__"obj/linen")->wear();
}
