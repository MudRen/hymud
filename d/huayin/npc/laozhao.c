// laozhao.c

inherit NPC;

void create()
{
	set_name("����", ({ "lao zhao" }) );

	set("title","ľ��");
	set("gender", "����" );
	set("age", 50);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	string weather;



	if(   (ob->value() < 100) )
	{
		tell_object(who,"����Ц�Ǻǵ�˵�������������˻��Ƕ�ѽ��лл����\n");
		return 1;
	}


	tell_object(who, "����Ц�Ǻǵ�˵������Ҫ����Ь�ɣ����Ǵ�ЬҲ̫������\n");
	who->set_temp("valid_enter_drying_room",1);
	return 1;
}
