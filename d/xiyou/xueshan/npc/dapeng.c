// dapeng.c...weiqi, 97.09.27.

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("��������", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "ѩɽ֮��");
	set("gender", "����" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "��λ����������ȷ����������˵��������������Ҳ�е����ݹ�ϵ��\n���������ġ��˾ˡ������������ֿ�ȸ���������ˣ�ȴҲ�������࣬\n��������֮�ʸ����Ž��������ƽ������ľ��Ǻ��С�\n");
	set("class", "yaomo");
	set("combat_exp", 1800000);
	set("daoxing", 3000000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 1, "��ʦ");
	set("rank_info/respect", "����");
 
	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);

            setup();
	carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}


