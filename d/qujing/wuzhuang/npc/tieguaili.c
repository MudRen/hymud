//Cracked by Roath
// tieguaili.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("������", ({"tieguai li", "tieguai", "li"}));
	//set("title", "");
	set("gender", "����" );
	set("age", 42);
	set("per", 12);
	set("long", "���ŵ�һ˫�ò�Ь������һ�����û�˱�����Ŀ�����ۣ���������ߵ�С����һ��������̬��\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 300000);

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

	setup();
	initlvl((300+random(280)),16);
	carry_object("/d/obj/cloth/pobuyi")->wear();
	carry_object("/d/obj/cloth/lancaoxie")->wear();
	carry_object("/d/obj/weapon/staff/tieguai")->wield();
}

