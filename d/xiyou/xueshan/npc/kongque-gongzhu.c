// kongque-gongzhu.c...weiqi, 97.09.15.

inherit NPC;

string get_ice(object me);
void do_drop(object ob);

void create()
{
	set_name("��ȸ����", ({"kongque gongzhu", "kongque", "gongzhu"}));
	set("title", "��������");
	set("gender", "Ů��" );
	set("age", 23);
	set("per", 21);
set("long", @LONG
��λ��ȸ�����ǿ�ȸ������Ů������ȸ��������������
Ѻ����ɽ�����ɴ�������һ�ִ���˵��ֶŮ�����
������ʵ���и�Ů֮�顣
LONG );
	set("class", "yaomo");
	set("combat_exp", 800000);
 	set("daoxing", 500000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 2, "����");
	set_skill("unarmed", 140);


	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 3000);
	set("max_force", 1500);
	set("mana", 3000);
	set("max_mana", 1500);	
	set("force_factor", 75);
	set("mana_factor", 76);
       set("eff_dx", -200000);
       set("nkgain", 400);


            setup();
	carry_object("/d/xiyou/xueshan/obj/nihong-yuyi")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
       carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/sword/fenghuangqin")->wield();
}

