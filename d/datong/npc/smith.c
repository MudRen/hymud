// smith.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("����", ({ "liu tie" }) );
        set("gender", "����" );
        set("age", 38);
	set("str",88);
        set("long", "���������ϰ�������\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);

	//set_weapon_ability(({"blade", "axe"}));
	//set_ability_level(10);

        setup();

	carry_object("/clone/misc/cloth")->wear();
}