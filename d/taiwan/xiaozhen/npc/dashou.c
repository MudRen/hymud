//musix  yangzhou's liumang.c 

inherit NPC;
void about_money();

void create()
{
	set_name("打手", ({ "dashou","da shou", "da" }));
	set("gender", "男性");
	set("age", 24);
	set("long", "张老财雇佣的打手,用来催租逼债.\n");
	
	set("combat_exp", 10000);
	set("mingwang", -1);

	set("attitude", "peaceful");
      set("chat_chance",30);
           set("chat_msg",({
                    (:about_money:),
              }));
      set("inquiry",([
               "银子":"这小子欠了张财主五十两银子,怎么,你想替他还?\n",
               "silver":"这小子欠了张财主五十两银子,怎么,你想替他还?\n",
               "老板":"我家主人张老财,这一带无人不知,无人不晓,\n
欠帐还钱,天经地道,这小子欠了五十两银子,居然不还!\n",
               ]));
	set_skill("unarmed", 30);
	set_skill("dodge", 40);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 30);

	setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("silver",10); 
}
void about_money()
{object ob,ob1;
 ob=this_player();
 ob1=load_object("/d/taiwan/xiaozhen/house");
 if (!ob||environment(ob)!=ob1) return;
 command("say 欠了老板的银子不还,居然还在大吃大喝!\n");
 return;
}
int accept_object(object who, object ob)
{
  if (ob->query("money_id")&&ob->value()>=5000)
       {   
           message("vision","打手掂了掂手中的银子,对渔夫道:白便宜了你小子!\n","/d/taiwan/xiaozhen/house");
           this_player()->set_temp("taiwan/渔夫");
           command("go west");
           call_out("out",1,1);
           return 1;
      }
  command("say 敢来消遣你家大爷!\n");
this_object()->kill_ob(who);
  return notify_fail("");
}
void out()
{ destruct(this_object());
  return;
}