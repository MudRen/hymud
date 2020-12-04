// toumu.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("СͷĿ", ({ "tou mu" }) );
        set("gender", "����");
        set("age", 27);
        set("long",     "��һﳤ�ø߸����ݣ�������Ц���������һ�Ѵ�Ƭ������\n");
        set("combat_exp", 700000);

	set("max_kee", 1200);
        set("max_gin", 1600);
        set("max_sen", 1600);
        set("attitude", "heroism");

	set("max_force",2000);
	set("force",2000);
	set("force_factor",50);

        set_skill("blade", 120);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		this_object()->kill_ob(ob);
        }
}
