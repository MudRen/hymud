inherit NPC;
#include <ansi.h>
int ask_job2();
void create()
{
   set_name("ͯ�����",({"guo jing"}));
   set("gender","����");
   set("long","�����������ɹ�,�潭������ѧ��!\n");
   set("shen",50000);
   set("combat_exp",100000);
   
set("age",17);
   set("qi",1900);
   set("max_qi",1900);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
	set_skill("club", 40);
	set_skill("zhongping-qiang", 40);
   set_skill("whip",80);
   set_skill("sword",80);
   set_skill("blade",80);
        set("inquiry", ([
        "ĸ��" : (:ask_job2:) ,
         ]) );
   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/jindao")->wield();
}


int ask_job2()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        if(((int)me->query("jinyong/book5")>1))
           {
                      message_vision("$N����$n˵����лл������ĸ�׻�����\n", this_object(), me);
	                      return 1;
            }

        if(!me->query_temp("book511"))
           {
                      message_vision("$N����$n˵��������˭���������������?\n", this_object(), me);
	                      return 1;
            }    

        if(me->query_temp("book512"))
           {
                      message_vision("$N����$n˵������ĸ�׽ӻ�������?\n", this_object(), me);
	                      return 1;
            }                      

                command("thank " + me->query("id"));
                command("say " + RANK_D->query_respect(me) + " ��ĸ�ױ������ץ��ţ�Ҵ�ȥ�ˡ�");
                command("say " + RANK_D->query_respect(me) + " �ܷ���ҽ̽���ĸ�׻ص�����é��? \n" NOR);
                me->set_temp("book512", 1);
                me->set("quest/quest_type", "����");
                me->set("quest/quest", "��ĸ");
                me->set("task_time", time() + 580);
                me->apply_condition("menpai_busy",22);
                ob = new(__DIR__"liping",1);
                ob->move("/d/jiaxing/guojia");
                ob->set("combat_exp", me->query("combat_exp"));
                return 1;
                           
}