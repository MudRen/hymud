//Cracked by Roath
// shizhe.c ��ƿʹ�ߺ
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("��ƿʹ��", ({ "shizhe" }));
	set("title", "�Ϻ������̴�");   
	set("long", @LONG
�Ϻ�������ǰ��ƿʹ�ߡ�
LONG);
	set("gender", "����");
	set("age", 20);
	set("attitude", "friendly");
	set("max_kee", 300);
	set("max_gin", 300);
	set("max_sen", 350);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 10);
	set("max_mana", 350);
	set("mana", 350);
	set("mana_factor", 20);
	set("combat_exp", 100000);
	set("daoxing", 200000);


  

	setup();
        add_money("silver", 20);
	carry_object("/d/xiyou/nanhai/obj/jingping");

}
