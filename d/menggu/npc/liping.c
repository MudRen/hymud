#include <ansi.h>
inherit NPC;

string ask_huijia();
string ask_daojia();

void create()
{
   set_name("��Ƽ",({"li ping"}));
   set("long","������ĸ��,�������ɹ�!\n");
   set("score",5000);
   set("combat_exp",160000);
set("str",30);   
set("per",30);
set("age",43);
        set("attitude", "friendly");
        set("gender", "Ů��");
        set("age", 12);
	set("no_get", 1);
   set("jing",5800);
   set("max_jing",5800);
set("env/wimpy", 40);
set("no_get",1);
   set("qi",5800);
   set("max_qi",5800);
set("food",550);
set("water",550);
   set("neili",3000);
   set("max_neili",3000);
   //set("force_factor",10);
        set("inquiry", ([
        "����" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
         ]) );
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("whip",120);

   setup();
   add_money("silver",1);
carry_object(__DIR__"obj/cloth")->wear();
}


void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("book512") )
	this_player()->start_busy(1);
if (ob->query("lingsong") == 0 )
{
        remove_call_out("leave");
        call_out("leave",240);
}
}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "������ĸ�׼���������Ӧ,�Լ��뿪�ˡ�\n" NOR,this_object());
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

if(!me->query_temp("book512") )
return "�Ҳ���Ҫ���͡�\n";
if((int)me->query("jinyong/book5")>=1)
return "�Ҳ���Ҫ���͡���\n";


      if(!query("iskillok"))
      {
      message_vision("ͻȻ����Χɱ���˼��������ϸ ˵��������ȥ��������ү��!\n",this_object(),who);	
      	fang = load_object(__DIR__"duantiande");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
return "�ȶԸ����˰� \n";
      }	

        fang = present("duan tiande",where);
	if(fang)
	{
		who->start_busy(3);
return "�ȶԸ����˰� \n";
	}





me->apply_condition("menggu_song",35);
me->set_temp("lingsong",1);
set_leader(me);
ob->set_leader(me);
ob->set("lingsong",10);
return "��л��������С����ȥ�ɹż����Ƕ���.\n";
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

if(me->query_temp("book512") == 0 )
return "�Ҳ���Ҫ���͡�������\n";
if(me->query_temp("lingsong") == 0 )
return "�Ҳ���Ҫ���͡�������\n";



 if( environment(ob)->query("short")=="����é��")
         {


    

          set_leader(0);
          write("���ڵ����ˣ���л����.\n");

  	if(!me->query("jinyong/book5"))
	{
		
 	//i = 100+random(200);
	//me->set("jinyong/book5",1);
	//me->add("combat_exp",i+10);
	//me->add("potential",i);
	//me->add("mpgx",10);
	//me->add("expmax",2);

	//tell_object (me,"������"+chinese_number(i+10)+"�㾭��"+
	//           chinese_number(i)+"��Ǳ��.\n");

		
         }		
             me->set_temp("book513",1);  
             me->set_temp("book512",0);
             me->set_temp("lingsong",0);
             me->apply_condition("menggu_song",0);
        call_out("leavet",1);
	  
           return "��˵÷������������ڸ���ɽ�����֣���ȥ����ʦ�����������������? \n";  
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