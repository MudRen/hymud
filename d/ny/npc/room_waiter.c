
// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("�߾�", ({ "bianjun" }) );
	set("title", "");
	set("gender", "����" );
	set("title", "��������");
	set("age", 18);
	set("long", "��һ��Ǹ��߾���\n");
     set("shen_type",-1);
     set("con", 30);
     set("cor", 30);
     set("str", 15);
     set("max_kee", 250);
     set("kee", 250);
	set("combat_exp", 800);
	set("attitude", "friendly");
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 80);
	setup();

	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();

}

