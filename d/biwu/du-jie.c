// dujie.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�ɽ�", ({ "du-jie", "jie" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�Ұף���һ��ֽһ����\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 5500000);
	set("score", 200000);

	set("str", 130);
	set("int", 130);
	set("cor", 130);
	set("cps", 130);
	set("con", 130);

	set("qi", 54000);
	set("max_qi", 52000);
	set("neili", 54000);
	set("max_neili", 54000);
	set("jiali", 90);

	create_family("������", 35, "����");
	assign_apprentice("����", 0);

	set_skill("force", 1150);
	set_skill("whip", 980);
	set_skill("parry", 1180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 1350);
	set_skill("riyue-bian", 980);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);

	setup();
	carry_object("/d/shaolin/obj/changbian")->wield();
}
