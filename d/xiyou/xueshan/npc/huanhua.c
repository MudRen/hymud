//huanhua.c
//hehe, this npc is interesting:D...weiqi, 97.09.15

inherit NPC;
void create()
{
	set_name("佻�", ({"huan hua", "huanhua", "hua"}));
	set("gender", "Ů��" );
	set("age", 16);
	set("long", "ѩɽ����Ů���ӡ�\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 30000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 4, "����");



	set("per", 21);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);
	setup();

	set("eff_dx", -8000);
	set("nkgain", 60);

	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}
