//Cracked by Roath
// zhangchan.c ����ɮ
// By Dream Dec. 20, 1996

inherit NPC;



void create()
{
	set_name("����ɮ", ({ "zhangchan seng", "seng" }));
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 250);
	set("max_gin", 250);
	set("max_sen", 250);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 20);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 20);
	set("combat_exp", 10000);
	
	set("apply/staffno", 10);
	set("apply/spearno", 10);
        create_family("�Ϻ�����ɽ", 4, "����");
	
	setup();
//        carry_object("/obj/money/silver");
        add_money("silver", 20);
	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}


