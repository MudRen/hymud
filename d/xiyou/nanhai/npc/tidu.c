//Cracked by Roath
// tidu.c

#include <ansi.h>

inherit NPC;

string ask_for_join();
string ask_for_leave();
string ask_for_huansu();

void create()
{
	set_name("���ɮ", ({ "tidu seng", "seng" }) );

	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	

	map_skill("force", "lotusforce");
	map_skill("spells", "buddhism");

	create_family("�Ϻ�����ɽ", 4, "����");

	setup();

	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}

