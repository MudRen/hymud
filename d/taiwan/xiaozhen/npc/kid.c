inherit NPC;
void create()
{
       set_name("小孩子",({"kid","xiaohaizi","xiaohai"}));
       if (random(2)==1)
       set("gender","女性");
       else set("gender","男性");
       set("combat_exp",200+random(200));
       set("str",13);
       set_skill("unarmed",10);
       set("chat_chance",40);
       set("chat_msg",({
                 (:random_move:),
            "小孩子好奇地看着你!\n",
            "小孩子对你嘻嘻笑了两声.\n",
         }));
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("coin",10+random(20));
  }