
// trainee.c

inherit NPC;

void create()
{
	set_name("武馆弟子", ({ "trainee" }) );
	set("gender", "男性" );
	set("age", 19);
	set("long", "你看到一位身材高大的汉子，正在辛苦地操练著。\n");
       set("cor",30);
       set("con",30);
       set("max_kee",250);
       set("kee",250);
	set("combat_exp", 100);
	setup();
	carry_object(__DIR__"obj/linen")->wear();
}
