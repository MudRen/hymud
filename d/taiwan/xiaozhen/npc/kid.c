inherit NPC;
void create()
{
       set_name("С����",({"kid","xiaohaizi","xiaohai"}));
       if (random(2)==1)
       set("gender","Ů��");
       else set("gender","����");
       set("combat_exp",200+random(200));
       set("str",13);
       set_skill("unarmed",10);
       set("chat_chance",40);
       set("chat_msg",({
                 (:random_move:),
            "С���Ӻ���ؿ�����!\n",
            "С���Ӷ�������Ц������.\n",
         }));
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("coin",10+random(20));
  }