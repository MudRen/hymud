// dadao.c
// by dicky

inherit NPC;

void create()
{
	set_name("���", ({"da dao", "da", "dao"}));
	set("long", "����һ�����к��һ���Ĵ����������ҽ��ᡣ\n");
	set("gender", "����");
	set("attitude", "heroism");
	set("age", 50);
	set("shen_type", -1);
	set("shen", -50000);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);

        set("max_sen",2000);
        set("max_qi", 2000);
        set("qi", 2000);

	set("max_jing", 2000);
	set("max_jing", 2000);
	set("neili", 200);
	set("max_neili", 200);
	set("force_factor", 20);

	set("combat_exp", 200000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 120);
	set_skill("parry", 120);
	setup();

        carry_object(__DIR__"obj/hujia")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("gold", 1);
}
