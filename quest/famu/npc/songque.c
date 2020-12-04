
#include <ansi.h>

inherit NPC;
int give_work();
void create()
{
      set_name("��ȱ",({"songque","jiangong","song"}));
      set("gender","����");
      set("nickname","�๤");
      set("age",40+random(40));
      set("shen_type",-1);
      set("combat_exp",130000+random(400000));
      set("str",45);
      set("per",16);
      set("inquiry",([
              "work":(:give_work:),
              "job":(:give_work:),
              "����":(:give_work:),
      ]));
      set_skill("unarmed",315);
      set_skill("parry",315);
      set_skill("dodge",315);
      setup();
      carry_object(__DIR__"obj/cloth")->wear();
      add_money("gold",1);
 }
void init()
{  object ob;
    ::init();
      if (interactive(ob=this_player())&&!is_fighting())
          {   remove_call_out("greeting");
               call_out("greeting",1,ob);
           }
   add_action("do_say","say");
}
void greeting(object ob)
{   if(!ob||environment(ob)!=environment()) return;
    if (ob->query_temp("work/kan")==1) return;
       if (ob->query_temp("work/kan")==2)
             {    command("say ��,"+ob->query("name")+"�Ѿ������ˣ�����(say ������)(say over).\n");
                  return;
             }     
    command("say ��λ"+RANK_D->query_respect(ob)+"��Ҫ�ҹ���ô������(ask song about work).\n");
    return;
}
int give_work()
{
    object me;
    me=this_player();
    if (!me||environment(me)!=environment()) return 0;

    if (me->query("combat_exp",1)>500000 && me->query("nbjob")!=28)
   {    command("say ���С�������Ҫ��ү������??\n");
            return 1;
       }
    if (me->is_busy())
   {    command("say ������æ!\n");
            return 1;
       }
       
    if (me->query_temp("work/kan")==1)
   {    command("say ��ղŵĻû�����!\n");
            return 1;
       }
    if (me->query_temp("work/kan")==2)
     {        command("say ��Ĺ�Ǯ��û���أ��ҿɲ����㱣��!\n");
               return 1;
     }
    command("say ��!����͵����������ȥ��ľ��!\n");
    me->set_temp("work/kan",1);
    return 1;
}
int do_say(string str)
{   object ob,ob1;
     int money,exp,pot;
    ob=this_player();
    if (!str||(str!="������" && str!="������" && str!="over")) return 0;

    if (ob->is_busy())
       {    command("say ������æ!\n");
             return 0;
        }

    if (ob->query_temp("work/kan")!=2)
       {    command("say ����ƭǮô����!\n");
             return 0;
        }


    money=1+random(10);
    command("say �ɵúã�������Ĺ�Ǯ.\n");
    ob1=clone_object("/clone/money/silver");
    ob1->set_amount(money);
    ob1->move(ob);
    ob->start_busy(5);
exp = 8+random(8);
if (ob->query("combat_exp",1)>500000) exp=2;

pot = exp*0.8;


ob->add("combat_exp",exp);
ob->add("potential",pot);
     
tell_object(ob,HIY"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n"NOR);

    message_vision("$N�ݸ�$nһЩ����!\n",this_object(),ob);
    ob->delete_temp("work/kan");
    ob->add_temp("nbjob27",1);
    return 1;
} 