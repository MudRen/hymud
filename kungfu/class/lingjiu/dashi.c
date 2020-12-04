//snowman 28/02/98
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
int ask_rob();
void create()
{
        set_name(HIG"��ɽͯ��"NOR, ({ "tong lao","tonglao"}));
	set("long",
	    "�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
	    "էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.\n"+
	    "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
        set("attitude", "friendly");
        set("gender", "Ů��");
        set("age", 12);
	set("no_get", 1);
        set("per", 35);
        set("str", 40);
        set("int", 47);
        set("con", 46);
        set("dex", 88);
        set("qi", 15500);
        set("max_qi", 15500);
        set("jing", 15600);
        set("max_jing", 15600);
        set("neili", 18000);
        set("max_neili", 18000);
set_skill("dodge",400);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
        set_skill("sword",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");	        
        set("inquiry", ([
        "�ع�" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
         ]) );
        set("env/wimpy", 40);
        set_temp("apply/attack", 200);
        set_temp("apply/defense",200);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 100);
        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("lingjiujob") )
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
                message_vision(HIG "СŮ������������Ӧ,�Լ��뿪�ˡ�\n" NOR,this_object());
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

if(me->query_temp("lingjiujob") == 0 )
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";
if(((int)me->query("jinyong/book4")!=6))
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";


      if(!query("iskillok"))
      {
      message_vision("ͻȻ����Χɱ���˼������ָ��� ˵���������ţ������������!\n",this_object(),who);	
      	fang = load_object("/kungfu/class/lingjiu/zuo");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/kungfu/class/lingjiu/duanmu");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
return "�ȶԸ����˰� \n";
      }	

        fang = present("duanmu yuan",where);
	if(fang)
	{
		who->start_busy(3);
return "�ȶԸ����˰� \n";
	}

        fang = present("zuo zimu",where);
	if(fang)
	{
		who->start_busy(3);
return "�ȶԸ����˰� \n";
	}



me->apply_condition("lingjiu_song",32);
me->set_temp("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "��С�����������ع����ع������н���.\n";
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

if(me->query_temp("lingjiujob") == 0 )
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";
if(me->query_temp("lingsong") == 0 )
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";

if(((int)me->query("jinyong/book4")!=6))
return "�ҿ��������ϴ��������Ǽ�ϸ�ɡ�����\n";

 if( environment(ob)->query("short")=="���հ��ɽ�")
         {


      if(!query("iskillok1"))
      {
      message_vision("ͻȻ����Χɱ���˼������ָ��� ˵���������ţ������������!\n",this_object(),who);	
      	fang = load_object("/kungfu/class/lingjiu/sang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/kungfu/class/lingjiu/zhuo");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok1",1);
     set("iskillok1",1);
return "�ȶԸ����˰� \n";
      }	

        fang = present("zhuo bufan",where);
	if(fang)
	{
		who->start_busy(3);
return "�ȶԸ����˰� \n";
	}

        fang = present("sang tugong",where);
	if(fang)
	{
		who->start_busy(3);
return "�ȶԸ����˰� \n";
	}

          set_leader(0);
          write("���ڵ������ˣ��㻤���й�.\n");

  	if(((int)me->query("jinyong/book4")==6))
	{
		
 	i = 1900+random(2900);
	me->set("jinyong/book4",7);
	me->add("combat_exp",i+15880);
	me->add("potential",i*20);
	me->add("mpgx",10);
	me->add("expmax",2);

	tell_object (me,"��Ӯ����"+chinese_number(i+15880)+"�㾭��"+
	           chinese_number(i*20)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		
         }		

             me->set_temp("lingjiujob",0);
me->set_temp("lingsong",0);
             me->apply_condition("lingjiu_song",0);
        call_out("leavet",1);
	  
           return "�һع�ȥ��.....\n";  
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