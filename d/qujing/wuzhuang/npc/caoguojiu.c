//Cracked by Roath
// caoguojiu.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("�ܹ���", ({"cao guojiu", "cao", "guojiu"}));
	//set("title", "");
	set("gender", "����" );
	set("age", 40);
	set("per", 20);
	set("long", "һλ��������������ˡ��ܹ��������ݣ����ʴ��ƣ�\n��ϲ���󣬿�Ľ���顣��ܽ��ݲ����������ӹ��ܡ�\n�ܹ�������Ϊ�ܣ�������ɽ�֣���˼Ԫ����Ͷ����Ԫ���¡�\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 200000);

	set("attitude", "peaceful");
	create_family("��ׯ��", 3, "����");
	set_skill("unarmed", 60);
	

	setup();
	initlvl((300+random(280)),16);
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/hammer/baiyuban")->wield();
}

