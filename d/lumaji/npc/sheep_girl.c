// sheep_girl.c

inherit NPC;

void create()
{
	set_name("����Ů", ({ "sheep girl", "girl" }) );
	set("gender", "Ů��" );
	set("age", 17);
	set("long", "һ���������СŮ���� \n");
	set("combat_exp", 30000);
	set("per", 30);
	set("str", 30);
	set("kar", 30);
	set("max_kee", 700);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("unarmed", 60);

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
}
