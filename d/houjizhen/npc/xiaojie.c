// chunhua.c
// by dicky

#include <ansi.h>
inherit NPC;
int ask_huijia();

void create()
{
	set_name("刘小姐", ({"liu xiaojie", "xiaojie"}));
	set("long", "这是一位的有钱人家的小姐，长得颇有几分姿色。\n");
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 18);
	set("per", 25);
	set("str", 28);
	set("con", 23);
	set("dex", 28);

	set("combat_exp", 2000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);

        set("inquiry", ([
		"回家":(: ask_huijia :),
        ]));

	setup();

        carry_object(__DIR__"obj/skirt1")->wear();
}

int ask_huijia()
{
	object ob;
	ob=this_player();

	if (!ob->is_fighting())
	{
	command("say 谢谢"+RANK_D->query_respect(ob)+"的舍命相救，小女子无一回报，就以家传玉佩相赠，希望"+RANK_D->query_respect(ob)+"能够珍惜！\n");
	new(__DIR__"obj/yupei")->move(ob);
	message_vision(
		"刘小姐给$N一个玉佩。\n\n"
		"刘小姐匆匆离开！\n",
                this_player(), this_object());
	destruct(this_object());
	return 1;
	}
	return notify_fail("你还是先保护自己再说吧！\n");
}