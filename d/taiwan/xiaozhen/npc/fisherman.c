inherit NPC;
void dashou();
void create()
{
     set_name("���",({"fisherman","yufu"}));
     set("gender","����");
     set("age",42);
     set("long","���һ������,����������ʵ����!\n");
     set("max_force",700);
     set("force",700);
     set("combat_exp",50000);
     set_skill("dodge",40);
     set_skill("force",40);
     set_skill("parry",40);
     set_skill("literate",10);
     set_skill("unarmed",40);
     setup();
     carry_object("/clone/misc/cloth")->wear();
}
void init()
{object ob;
  ::init();
    if (interactive(ob=this_player())&&!is_fighting())
           {  remove_call_out("greeting");
              call_out("greeting",1,ob);
           }
}
void greeting(object ob)
{  if (!ob||environment()!=environment(ob))  return;
   command("say ���к�,����Ե�,�ü���û�Զ�����... ...\n");
   return;
}
int accept_object(object who,object ob)
{  if (ob->query("food_remaining"))
         {   command("say лл,��л��λ"+RANK_D->query_respect(who)+",�������ҵľ���������!\n");
             message("vision","�������"+ob->name()+"���̻��ʵس�������!\n","/d/taiwan/house");
             call_out("dashou",4,1);
             return 1;
          }
  command("say ��,�ⶫ������ûʲô�ð�!");
  return notify_fail("");
}
void dashou()
{object ob,ob1,ob2;
  string room;
 ob2=load_object("/d/taiwan/xiaozhen/house");
 ob=this_player();
 if (!ob||environment()!=environment(ob))  return;
 room="/d/taiwan/xiaozhen/house";
 if (!present("dashou",ob2))
{   clone_object("/d/taiwan/xiaozhen/npc/dashou")->move("/d/taiwan/xiaozhen/house");
    message("vision","ͻȻ������������һ����,������򲻶���Ц!\n",room);
}
ob1=present("dashou",ob2);
message_vision("$N�ٺ�һЦ:������÷���û����ô!�������õ�ʲô?
˵�ų���ǰȥ��$nһ�ٶ���!\n",ob1,this_object());
this_object()->unconcious();
return;
}