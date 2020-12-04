// qigai.c

inherit NPC;

void create()
{
	set_name("����ؤ", ({ "qi gai","beggar","gai" }) );
	//set("title", "������ؤ");
	set("title", "��ؤ");
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);

	set("max_qi", 1500);
	set("max_jing", 1100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("shen_type", 0);

	set_temp("apply/attack",  120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage",  120);

	set("combat_exp", 200000);
	set("str", 27);
	set("kar", 100);
	set("thief", 0);
	set("force", 200);

	set("max_force", 200);
	set("force_factor", 2);

	set_skill("unarmed", 150);
	set_skill("sword", 150);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("stealing", 300);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"����ؤ˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"����ؤ������ش��˸���Ƿ��\n",
		"����ؤ����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
	}) );
	create_family("ؤ��", 19, "����");

        carry_object("/clone/food/jitui");
        carry_object("/clone/food/jiudai");
	add_money("silver", 1);
}

