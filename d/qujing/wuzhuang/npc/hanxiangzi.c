//Cracked by Roath
// hanxiangzi.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("������", ({"han xiangzi", "han", "xiangzi"}));
	//set("title", "");
	set("gender", "����" );
	set("age", 22);
	set("per", 30);
	set("long", "��һλ�����������๫�������ӱ�������֮��ȴ��ϲ�������ˡ�\n�������г��������ѧ������š�\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 200000);

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
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/weapon/sword/zijinxiao")->wield();
}


