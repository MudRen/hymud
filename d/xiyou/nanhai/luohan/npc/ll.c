 //Cracked by Roath
inherit NPC;

void create()
{
	set_name("�����޺�", ({ "luo han"}));
	set("long", @LONG
�Ϻ���������ʮ���޺���
LONG);
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("rank_info/self", "ƶɮ");
	set("class", "bonze");
	set("max_kee", 2000);
	set("max_gin", 2000);
	set("max_sen", 2000);

	set("force", 3000);
	set("max_force", 1800);
	set("force_factor", 70);
	set("max_mana", 1800);
	set("mana", 3000);
	set("mana_factor", 70);

	set("combat_exp", 2000000);
	set("daoxing", 2000000);


       

	setup();
	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
	carry_object("/d/xiyou/nanhai/obj/budd_staff")->wield();
}

