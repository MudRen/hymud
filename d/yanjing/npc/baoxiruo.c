#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
void create()
{
   set_name("��ϧ��",({"bao xiruo"}));
   set("gender","Ů��");
   set("long","���ڵ�����,�����ٰ�ţ�Ҵ�����ɩ��!\n");
   set("mingwang",6000);
   set("combat_exp",6000);
   set("title","����");
set("str",30);   
set("per",30);
set("age",38);
   set("jing",5800);
   set("max_jing",5800);
set("env/wimpy", 40);
   set("qi",5800);
   set("max_qi",5800);
set("food",550);
set("water",550);
   set("neili",3000);
   set("max_neili",3000);

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("club",130);
   set_skill("literate",120);
   set("inquiry",([
   "������":"����,��֪��?��ϧ��������ʮ������!\n",
   "�￵":"�⼸�첻֪����,�ϰ�����Ժ��!\n",
   "��ǹ":"�����ɷ�����������,�ɲ��ܸ���.\n",
        "����" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
  ]));
   setup();
   add_money("silver",6);
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/haltspear");
}
void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("book5222") )
	this_player()->start_busy(1);

}



string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(!me->query_temp("book5222") )
return "�Ҳ���Ҫ���͡�\n";
if((int)me->query("jinyong/book5")>=2)
return "�Ҳ���Ҫ���͡���\n";
me->set_temp("lingsong",1);
set_leader(me);
ob->set_leader(me);
ob->set("lingsong",10);
return "��л��������С����ȥ�����ǿ����ķ��.\n";
}

string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp;
	int i;
	object fang,who,where;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);

if(me->query_temp("book5222") == 0 )
return "�Ҳ���Ҫ���͡�\n";
if(me->query_temp("lingsong") == 0 )
return "�Ҳ���Ҫ���͡���\n";



 if( environment(ob)->query("short")=="��������")
         {


    

          set_leader(0);
          write("���ڵ����������.\n");


             me->set_temp("book522",1);
             me->set_temp("book5222",0);
             me->set_temp("lingsong",0);
             me->apply_condition("menggu_song",0);
        call_out("leavet",1);
	  
           return "��л����. \n";  
      }
        else {
                return "��û����!���벻������?\n";
        }
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"�������ڲ�����guard��\n");
        return 1;
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	