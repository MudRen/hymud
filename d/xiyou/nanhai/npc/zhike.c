//Cracked by Roath
// zhike.c ֪��ɮ�
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("֪��ɮ", ({ "zhike seng", "seng" }));
	set("long", "һλ�����ɮ�ˣ��������Ǵ��������Ц�ݡ�\n�������ڴ�ӭ��ǰ����������Ŀ��ˡ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);



        create_family("�Ϻ�����ɽ", 4, "����");
	
	setup();
              add_money("silver", 8); 
	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}

