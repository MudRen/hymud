inherit NPC;
void whisper();
void create()
{
     set_name("�Ų���",({"caizhu","zhang","zhangcaizhu"}));
     set("gender","����");
     set("age",56);
     set("long","�Ų������̰��軧,��ѹ����,��ʮ��������޴�Ƹ�!\n");
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
                "�Ų����������ڴ�����������ȥ,��ȫû��ע����!\n",
                "�Ų�������ָ���˿ٱǿ�,������������!\n",
                "ׯ�Ҵ���,ׯ�Ҵ���,��... ...\n",
           }));
     set("inquiry",([
           "ׯ�Ҵ���":(:whisper:),
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
   command("whisper "+ob->query("id")+" ��˵ׯ�Ҵ��������Ʊ�,��ֻҪ����\n
�û���,���ǲ���С����!�ٺ�.\n");
   return;
}
int accept_object(object who,object ob)
{      int value;
       if (ob->query("mask/ׯ"))
            {
                (int)value=ob->query("value");
                if (value<10000)
                  {     command("say �ⶫ��Ҳ�����Ա���!��������һ��,�⼸��Ǯ��ȥ��!\n");
                        add_money("silver",1+random(6));
                        command("give silver to "+who->query("id"));
                        return 1;
                  }
               command("say ��������,��������Ҫ��,������!\n");
               (int)value=value/10000;
               add_money("gold",1+random(value));
               command("give gold to "+who->query("id"));
               return 1;
           }
    command("say ����ʲô���������,��Ȼ����ƭ�����ү,�ҿ��㲻Ҫ����!\n");
   kill_ob(who);
   return notify_fail("");
}
   