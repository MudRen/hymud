
#include <ansi.h>
inherit NPC;

string ask_liwu();

void create()
{
        set_name("厨师", ({ "chu shi" }) );
 //set("title", HIR "武术教练" NOR);
	set("gender", "男性" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "
古村的厨师，你可以问他要(yao)一些吃的。
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 1500);
	set_skill("blade", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);


	setup();
	carry_object("clone/cloth/cloth")->wear();
}

