//Cracked by Roath
// lancaihe.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("���ɺ�", ({"lan caihe", "lan", "caihe"}));
	//set("title", "");
	set("gender", "����" );
	set("age", 18);
	set("per", 20);
	set("long", "һλ������Ƶ����ꡣ\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 200000);

	set("attitude", "peaceful");
	create_family("��ׯ��", 3, "����");
	

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 800);
	set("neili", 1600);
	set("max_neili", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	initlvl((300+random(280)),15);
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/blade/yanblade")->wield();
}

