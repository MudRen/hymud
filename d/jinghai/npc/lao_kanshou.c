// lao_kanshou.c

inherit NPC;

void create()
{
	set_name("�η�����", ({"laofang kanshou"}));

	set("long", "����һλ��������ļһ\n");
	set("gender","����");

	set("attitude","peaceful");
        set("age",36);
        set("con",30);
        set("str",25);
        set("per",15);
        set("kar",25);
	set("max_qi",1200);
	set("max_jing",1200);
	set("max_sen",1200);
	set("max_neili",1200);
	set("neili",1200);
	set("force_factor",20);

	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("unarmed",150);
	set_skill("force",150);
	set_skill("jingyiforce",150);
	set_skill("demon-blade",150);
	set_skill("fengyu-piaoxiang",150);

	map_skill("dodge","fengyu-piaoxiang");
	map_skill("parry","longjiao-blade");
	map_skill("blade","longjiao-blade");
	map_skill("force","jingyiforce");

	set("combat_exp",150000);

        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object ob;

	if( objectp(ob = previous_object()) &&
	ob->is_fanren() &&
	objectp(ob->query_master()) )
		call_out("do_accept_f",1,ob);
}

private void do_accept_f(object ob)
{
	object m;
	string name;
	mapping q;

	if(!objectp(ob)
	|| !objectp(m = ob->query_master())
	|| (environment(ob) != environment())
	|| (environment(m) != environment()) )
		return;

	name = ob->name();

	say(sprintf("%s��%s˵�������������ˣ����������Ҵ�ȥ�ռ��ˡ���\n",name(),m->name()));

	destruct(ob);

	if( mapp(q = m->query("quest/jinghai_quest/"))
	&& (q["quest"] == "ץ��") && (q["name"] == name) )
		m->set("quest/jinghai_quest/finish",1);
}


