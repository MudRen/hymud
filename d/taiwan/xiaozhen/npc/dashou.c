//musix  yangzhou's liumang.c 

inherit NPC;
void about_money();

void create()
{
	set_name("����", ({ "dashou","da shou", "da" }));
	set("gender", "����");
	set("age", 24);
	set("long", "���ϲƹ�Ӷ�Ĵ���,���������ծ.\n");
	
	set("combat_exp", 10000);
	set("mingwang", -1);

	set("attitude", "peaceful");
      set("chat_chance",30);
           set("chat_msg",({
                    (:about_money:),
              }));
      set("inquiry",([
               "����":"��С��Ƿ���Ų�����ʮ������,��ô,����������?\n",
               "silver":"��С��Ƿ���Ų�����ʮ������,��ô,����������?\n",
               "�ϰ�":"�Ҽ��������ϲ�,��һ�����˲�֪,���˲���,\n
Ƿ�ʻ�Ǯ,�쾭�ص�,��С��Ƿ����ʮ������,��Ȼ����!\n",
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
 command("say Ƿ���ϰ�����Ӳ���,��Ȼ���ڴ�Դ��!\n");
 return;
}
int accept_object(object who, object ob)
{
  if (ob->query("money_id")&&ob->value()>=5000)
       {   
           message("vision","���ֵ��˵����е�����,������:�ױ�������С��!\n","/d/taiwan/xiaozhen/house");
           this_player()->set_temp("taiwan/���");
           command("go west");
           call_out("out",1,1);
           return 1;
      }
  command("say ������ǲ��Ҵ�ү!\n");
this_object()->kill_ob(who);
  return notify_fail("");
}
void out()
{ destruct(this_object());
  return;
}