//Cracked by Roath

// ludongbin.c...weiqi, 98.02.24.

string give_book();
string ask_jinguzhou();

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("������", ({"lu dongbin", "lu", "dongbin"}));
	//set("title", "������");
	set("gender", "����" );
	set("age", 35);
	set("per", 30);
	set("long", "�������������Ԫ����������ĵ����ˣ��Ĳɷ�����ɫ�����졣\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 800000);

	set("attitude", "peaceful");
	create_family("��ׯ��", 3, "����");
	set_skill("unarmed", 60);
	

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 800);
	set("neili", 1600);
	set("max_neili", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	set("inquiry", ([
		"name" : "��ׯ�۴�������Ҳ��\n",
		"here" : "���ںδ����������ӡ�\n",

	]) );

	set("no_book", 0);

	setup();
	initlvl((300+random(280)),16);
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}
