// yayi.c  �ٸ�����
inherit NPC;

void create()
{
	set_name("����", ({ "ya yi", "ya" }));
	set("gender", "����");
	set("age", 25);

	set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
	set("combat_exp", 7500);
	set("shen_type", 1);
	set("combat_exp", 81000);
	set("shen_type", 1);

    set("max_neili",500);
    set("neili",500);
    set("qi",500);
    set("eff_qi",500);
    set("max_qi",500);

    set("jing",500);
    set("eff_jing",500);
    set("max_jing",500);
        set_skill("force", 80+random(80));

        set_skill("unarmed", 80+random(80));
        set_skill("blade", 80+random(80));
        set_skill("parry", 80+random(80));
        set_skill("dodge", 80+random(80));
        set_skill("kuang-blade", 80+random(80));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set("chat_msg_combat", ({
		"����˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
		"����˵������Ҫ��������ȡ�֣����Ĳ�ͷ����ץȥ����!\n",
		"�������еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
		"����˵������������������ĵط�����\n"
	}) );
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/yayifu")->wear();
}
	
