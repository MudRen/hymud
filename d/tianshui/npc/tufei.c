// tufei.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "bandit" }) );
        set("gender", "����");
        set("age", 27);
        set("long",     "��һﳤ�ø߸����ݣ�������Ц���������һ�Ѵ�Ƭ������\n");
        set("combat_exp", 200000);
        set("attitude", "heroism");

        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);

	set("max_force",2000);
	set("force",2000);
	set("force_factor",30);

        set_skill("blade", 150);
        set_skill("parry", 100);
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
		message_vision("���˳�$N����������С�ӣ��������ܣ�������ˣ�����\n",ob);
		this_object()->kill_ob(ob);
        }
}
