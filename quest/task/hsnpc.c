#include <ansi.h>
inherit NPC;

string ask_huijia();
string ask_daojia();
#include "/quest/givehdgift.c"
void create()
{
   set_name("��������",({"wulin renwu"}));
   set("long","�����������׷ɱ!\n");
   set("score",5000);
   set("combat_exp",160000);
set("str",35);   
set("dex",35);   
set("per",random(20)+10);
set("age",random(30)+14);
        set("attitude", "friendly");
if (random(2)==0)
        set("gender", "Ů��");
else      set("gender", "����");
        set("age", 12);
	set("no_get", 1);
   set("jing",12800);
   set("max_jing",12800);
set("env/wimpy", 40);
   set("qi",12800);
   set("max_qi",12800);
set("isteamjob",1);
set("moveok",1);
set("no_get",1);
set("food",550);
set("water",550);
   set("neili",5000);
   set("max_neili",5000);
   //set("force_factor",10);
        set("inquiry", ([
        "����" : (:ask_huijia:) ,
        "start" : (:ask_huijia:) ,        
        "����" : (:ask_daojia:) ,
        "over" : (:ask_daojia:) ,
         ]) );
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("whip",120);

   setup();

carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        object ob = this_object();

if(ob->query("hsr")==this_player()->query("id") )
	this_player()->start_busy(1);
        remove_call_out("leave");
        call_out("leave",1200);

}



void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIG "���������Լ��뿪�ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}



string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(me->query("id")!=ob->query("hsr") )
return "�Ҳ���Ҫ�㻤�͡�\n";
if (!ob->query("iskill"))
{
me->apply_condition("mp2_kill",12);
ob->set("iskill",1);
this_object()->set("iskill",1);
}
set_leader(me);
ob->set_leader(me);
return "��л����������ȥĿ�ĵ�.\n";
}

string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp,maxskill;
	int i;
	object fang,who,where;
        int count,add_exp;
        object *team,boss;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);

if (ob->query("hsr")!=me->query("id"))
		return "����˭�����Ҳ���ʶ��! \n"; 

 if( base_name(environment(ob))+".c"==ob->query("hstg")
 )
         {
          set_leader(0);


       
          write("���ڰ�ȫ�����ˣ���л����.\n");
if(me->query_temp("nhdjob2lb")=="���ڻ���" || me->query_temp("nhdjob2lb")=="����̽Ѱ" )
{
exp=3888+random(1888);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("hndjobsl",1)*30);
me->add_temp("nhdjobsl",1);
me->clear_condition("taskjob_busy");
if (me->query("hyvip",1)==4) exp=exp/2+200;
tell_object(me,HIR"��ɹ��������һ�����������!\n"+
NOR);
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add("max_neili",3);
if (me->query("shen")>0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
tell_object(me,"�������������������޺���ٵ���!\n");
if (random(9)==0)
	 {
tell_object(me,"������ɹ���������!\n");
	 me->add("mpgx",1);
}

if(me->query_temp("nhdjob2lb")=="���ڻ���" )
{
me->clear_condition("taskjob_busy");
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(0,who,me);
else
"/adm/daemons/taskd"->give_gift3(3,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$Nͨ������������µõ���һ������:\n" + me->query_temp("nhdjob2sc") + "��\n", me);
}
me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
me->clear_condition("taskjob_busy");
}
	


if(me->query_temp("nhdjob2lb")=="����̽Ѱ" )
{
me->clear_condition("taskjob_busy");
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(8,who,me);
else
"/adm/daemons/taskd"->give_gift3(0,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$Nͨ������������µõ���һ������:\n" + me->query_temp("nhdjob2sc") + "��\n", me);
}
me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");

}

if(me->query_temp("nhdjob2lb")=="���ڻ���" || me->query_temp("nhdjob2lb")=="����̽Ѱ" )
{
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
me->delete_temp("nhdjob2sc");
}
}		

		  		
me->clear_condition("mp2_kill");

        call_out("leavet",1);
	  
           return "���Ǿʹ˷ֱ��! \n";  
      }
        else {
                return "��û����!���벻������?\n";
        }
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