// guanzhong.c

inherit NPC;

void create()
{
	set_name("����", ({ "guan zhong" }) );
	if(random(10)<5)
		set("gender", "����" );
	else
		set("gender", "Ů��" );
	set("age", 30);
	set("max_kee",400);
	set_skill("unarmed",60);

	set("long",
		"����һλ��ˮ���������ҡͷ���ԣ�����������ա�\n");
	set("combat_exp", 7000);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
