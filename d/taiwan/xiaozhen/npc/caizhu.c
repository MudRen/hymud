inherit NPC;
void whisper();
void create()
{
     set_name("张财主",({"caizhu","zhang","zhangcaizhu"}));
     set("gender","男性");
     set("age",56);
     set("long","张财主靠盘剥佃户,欺压穷人,数十年间积累起巨大财富!\n");
     set("combat_exp",1700000);
     set("mingwang",-6000);
     set("max_force",1000);
     set("force",1000);
     set("force_factor",100);
     set("max_gin",600);
     set("gin",600);
     set("max_kee",1200);
     set("kee",1200);
     set("max_sen",800);
     set("sen",800);
     set("str",32);
     set("chat_chance",10);
     set("chat_msg",({
                "张财主背着手在大厅中踱来踱去,完全没有注意你!\n",
                "张财主用手指抠了抠鼻孔,仰着脸喃喃自语!\n",
                "庄家大屋,庄家大屋,唉... ...\n",
           }));
     set("inquiry",([
           "庄家大屋":(:whisper:),
           ]));
     set_skill("unarmed",150);
     set_skill("dodge",150);
     set_skill("parry",150);
     set_skill("force",150);
     set_skill("literate",100);
     setup();
     carry_object(__DIR__"obj/boot")->wear();
}
void whisper()
{
   object ob;
   ob=this_player();
   if (!ob||environment()!=environment(ob)) return;
   command("whisper "+ob->query("id")+" 听说庄家大屋有许多财宝,你只要给我\n
拿回来,我是不会小气的!嘿嘿.\n");
   return;
}
int accept_object(object who,object ob)
{      int value;
       if (ob->query("mask/庄"))
            {
                (int)value=ob->query("value");
                if (value<10000)
                  {     command("say 这东西也拿来显宝啊!看你辛苦一场,这几个钱拿去吧!\n");
                        add_money("silver",1+random(6));
                        command("give silver to "+who->query("id"));
                        return 1;
                  }
               command("say 哈哈哈哈,这真是我要的,好样的!\n");
               (int)value=value/10000;
               add_money("gold",1+random(value));
               command("give gold to "+who->query("id"));
               return 1;
           }
    command("say 这是什么破烂玩意儿,居然敢来骗你家老爷,我看你不要命了!\n");
   kill_ob(who);
   return notify_fail("");
}
   