// tuying-zunzhe.c...weiqi, 97.09.15.

#include <ansi.h>

inherit NPC;
string expell_me(object me);
void create()
{
	set_name("ͺӥ����", ({"tuying zunzhe", "tuying", "zunzhe"}));
	set("title", "��������");
	set("gender", "����" );
	set("age", 53);
	set("per", 112);//no rongmao description.

	set("long", "�������������Ļ�������֮һ����ͷ���ʣ�һ����֪���������\n");
	set("class", "yaomo");
	set("combat_exp", 500000);
	set("daoxing", 400000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 2, "����");

	set("max_kee", 800);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1000);
	set("max_mana", 500);	
	set("force_factor", 50);
	set("mana_factor", 25);

        set("eff_dx", -120000);
        set("nkgain", 300);

	set("inquiry", ([

		"name": "�ٺ٣�\n",
		"here": "�࿴��˵��\n",
	]) );


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	//carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

