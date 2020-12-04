// zhangty.c

inherit NPC;

void create()
{
	set_name("������", ({ "zhang tianyou" }) );

	set("title","��å����");

	set("gender", "����" );
	set("age", 23);

	set("attitude","peaceful");

	set("long", "��λ�Ǵ�ͬ�żҵ�С��ү��ƽʱ�޶�������\n");

	set("combat_exp", 20000);

	set("str", 30);

	set("kee",900);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

	set_skill("unarmed",40);
	set_skill("dodge",30);
	set_skill("parry",30);

	set("chat_chance_combat",30);
	set("chat_msg_combat",({
	"\n�����к�������ʲô���ҹ���ȥ������ô���ˣ�\n\n",
	"\n�����к�������Ҫ��ʲô���ҳ��˵�Ϸ��Ů�۸�Ҫ���ľ�û�ɹ���������\n\n",
	"\n�����к�������ʲô���ҹ���ȥ���ҵ��е���Ǯ��\n\n",
	"\n�����к�����������ô�����Ұ��㺢���Ӿ���ȥ����\n\n",
 }));

	setup();
	add_money("silver",2);
	carry_object("/clone/misc/cloth")->wear();
}

void die()
{
	object killer = query_temp("last_damage_from"),zhu;


	if(objectp(killer)
	&& killer->query("quest/shaolin_quest/name") == "����֥")
	{
		zhu = new(__DIR__"obj/biduzhu");
		zhu->move(this_object());
	}

	::die();
}
