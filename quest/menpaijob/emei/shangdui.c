//snowman 28/02/98
#include <ansi.h>
#include "/quest/givegift.c"
inherit ITEM;
int j=3;
void create()
{
        set_name("���̶���", ({ "mingjiao"}));
        set("unit", "ֻ");
        set_weight(90000000);
        set("long", "
һֻԶ�����������̵��ӣ������в��ٸ��֡��м��
��һ����죬�ƺ�д�š����̡��������֡�����\n");
        set("no_get", 1);
        set("no_drop", 1);
	 set("no_put",1);
}

void init()
{ remove_call_out("aaa");
  call_out("aaa", 380, this_object());  
  add_action("do_rob", "xiaomie");
}

int do_rob()
{
   object me, ob;   
   string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
   arg = query("arg");

   if(!living(me)) return 0;
   if(!me->query_temp("rob_start")) 
       return notify_fail("�㵨�Ӳ�С���������������ԣ�\n");
   if(objectp(present("mingjiaodizi", environment(me))))
       return notify_fail("���̵��ӿ����书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  

   message_vision(HIY"$N����$n���һ����"+me->name()+"�ڴˣ�������Щħ�̵���,��������\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}
void make_bs(object me, object ob)
{
   object obj, obj1;
      object n_money;
   int exp,pot,kar;
	if (j>0){
	  obj = new(__DIR__"biaoshi");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"biaoshi");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          j=j-1;     }
else {
       message_vision(HIW"$N���Ѿ��޻��ˣ��������������ϵ��������ڻ����\n"NOR, me);    
       ;    
       //obj=new(__DIR__"red");
       //obj->move(me);
       //obj->set("owner", me->query("id"));
       me->add("combat_exp", 100);
       me->add("shen", 100);
	tell_object(me,"�㱻������\nһ�ٵ㾭��ֵ��\n");
       me->delete_temp("rob_start");
       me->delete_temp("xx_rob");
       me->delete_temp("rob_job");
       me->delete_temp("j");       
       message_vision("$Nת������Сɽ��Ͳ����ˡ�\n",ob);
if (me->query_temp("emjob2",1)>2)
{
   kar = random(me->query("kar")) * 10;
if (kar >500) kar=500;
if (kar <150) kar=150;
   exp = 550 + kar;	
   exp=550;
   exp=exp/2+188;
   addnl(me,"exp",exp);

  me->add("shen",100);
  me->add("score",10);
   tell_object(me, "�������������ǿ�ˣ���Ľ���������ǿ�ˡ�\n");
}	
me->set_temp("emjob2",0);
me->delete_temp("emjob2");
   me->delete_temp("xx_rob");
   me->delete_temp("job_asked");
   me->delete_temp("robjob_exp");
   me->delete_temp("biaoshi");
       destruct(ob);
    }
}

void aaa(object me)
{
       message_vision("$Nת������Сɽ��Ͳ����ˡ�\n",me);       
       destruct(me);
       return;
}

