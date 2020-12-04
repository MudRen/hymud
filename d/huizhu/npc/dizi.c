// Room: /d/huijiang/npc/dizi.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("�컨�����", ({ "di zi", "dizi" }));
	set("long", "һ������ͨͨ�ĺ컨�����\n�������ʮ���ˣ�\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 21);
	set("int", 22);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2800);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 200000);
	set_skill("force", 145);
	set_skill("dodge", 145);
	set_skill("unarmed", 140);
	set_skill("parry",150);
	set_skill("sword",150);
	set_skill("blade",150);

	create_family("�컨��",3, "����");

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
