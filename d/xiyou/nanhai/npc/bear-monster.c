//Cracked by Roath
// bear-monster.c ���ܹ֡�
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���ܹ�", ({ "bear monster", "bear", "monster" }));
	set("title", "�Ϻ�����֮ͽ");   
	set("long", @LONG
���ֱܹ���ɽ��Ұ�ޣ���֪������ѧ��һ��ñ��졣
�������Ϻ����������Ϻ�������Ϊͽ�ܡ�
LONG);
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("per", 9);
	set("rank_info/self", "����");
	set("rank_info/rude", "�ܹ�");
	set("max_kee", 850);
	set("max_gin", 800);
	set("max_sen", 850);
	set("force", 400);
	set("max_force", 500);
	set("force_factor", 50);
	set("max_mana", 250);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 30000);
	set("daoxing", 50000);

	set_skill("literate", 60);

        create_family("�Ϻ�����ɽ", 2, "����");

	setup();
//	carry_object("/obj/cloth")->wear();
	carry_object("/d/xiyou/nanhai/obj/jingu3");
//	carry_object("/d/xiyou/nanhai/obj/jingu3");
}

