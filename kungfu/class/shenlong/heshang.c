#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name( "行痴" , ({ "xing chi","xingchi"}));
        set("shen_type", 0);
        set("age",43);
        set("title", HIR"老和尚"NOR);
        set("gender", "女性");
      set("per",24);
        set("long",
                "他生得白白胖胖，所以他的脸色显得很苍白。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "永不加赋" : "要想天下太平，就要‘永不加赋’！！。\n",
                "营救" : (: ask_me :),
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book7")!=5))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢教命之恩。\n",this_object(),who);
	message_vision("$N对$n说道： 看来吴三桂真的要反叛了，天下百姓要遭殃了 。\n",this_object(),who);
	who->set_temp("book761",1);
	call_out("destroying", 0);                       

	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}