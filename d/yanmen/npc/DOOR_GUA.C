// #pragma save_binary
// door_guard.c

inherit NPC;

void create()
{
	set_name("С��", ({ "guard" }) );
	set("gender", "����");
	set("age", 24);
	set("long",
        	"���������е㾫�������н����������������������ӡ�\n");

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("combat_exp", 60000);

	set("force", 600);
	set("max_force", 600);
	set("force_factor", 5);

	set_skill("blade", 50);
	set_skill("unarmed", 40);
	set_skill("parry", 60);
	set_skill("dodge", 50);

	setup();

	carry_object( __DIR__"obj/blade")->wield();
}
