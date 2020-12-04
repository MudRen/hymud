
// beggar.c

inherit NPC;

void create()
{
	set_name("��ؤ", ({ "beggar" }) );
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"��ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
		"��ؤ������ش��˸���Ƿ��\n",
		"��ؤ����׽ס�����ϵġ��ӣ��������������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
	}) );
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say ��л��λ" + RANK_D->query_respect(me) + "��������һ�����кñ��ģ�");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}
