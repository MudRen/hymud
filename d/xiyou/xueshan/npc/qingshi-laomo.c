// qingshi-laomo.c...weiqi, 97.09.15.

inherit NPC;
void create()
{
	set_name("��ʨ��ħ", ({"qingshi laomo", "qingshi", "laomo"}));
	set("title", "��������");
	set("gender", "����" );
	set("age", 63);
	set("per", 112);//no rongmao description.

	set("long", "��λ��ʨ��ħԭ����ʨ��ɽ��ң���������������н��顣\n����ʨ��ɽ������ɽ���Ƕ���һλ�õ����˽���\n��ħ��Ͷ�������������˻������ߡ�һ���������г�\nһ������ʿ�г�Ҳ����֪�����ѡ�\n");
	set("class", "yaomo");
	set("combat_exp", 800000);
	set("daoxing", 1000000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 2, "����");
	
	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 60);
	set("mana_factor", 25);

	set("eff_dx", -200000);
	set("nkgain", 400);

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

