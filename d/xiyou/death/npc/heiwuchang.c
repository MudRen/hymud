// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("黑无常", ({ "hei wuchang","wuchang", "gargoyle" }));
        set("long","一个黑衣漆黑面皮的使者，黝黑的脸上看不出任何喜怒哀乐。\n");
        set("attitude", "peaceful");
	set("per", 10);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "引魄司主");
        set("combat_exp", 150000);
  set("daoxing", 200000);

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
	set("class", "youling");
	set("force", 1500);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 600);
	set("mana", 1000);
	set("mana_factor", 40);
	

create_family("阎罗地府", 3, "你好");
  set("inquiry",([
   "name":"在下引魂使黑无常，奉十殿冥王之命，前往阳间勾魂。\n",
   "here":"这里是阎罗地府。\n",
   "勾魂":"我按批文所书勾人，若有冤屈，可与发此公文之冥王申诉(complain)。\n",
   "冤枉":"我按批文所书勾人，若有冤屈，可与发此公文之冥王申诉(complain)。\n",
   "冤屈":"我按批文所书勾人，若有冤屈，可与发此公文之冥王申诉(complain)。\n",
  ]));

        setup();
	carry_object("/d/obj/cloth/hei")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
//		ob->set("title", "地府引魄司阴兵");
}

�
