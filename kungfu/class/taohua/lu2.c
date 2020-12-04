//yan.c
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();


void create()
{
        object ob;

        set_name("½��˫", ({ "lu wushuang","wushuang" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
½��˫������½��ׯ��ǧ��С�㣬���ٻ����󡣸�ĸȴ����Ī����ɱ
�������ҵ������������㡣��������Ī����Ϊͽ�ܡ�
TEXT );
        set("per", 30);
        set("nickname", HIG "½��ǧ��" NOR);
        set("class", "scholar");
set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("blade",200);
	set_skill("ruyi-dao",200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("lingboweibu", 200);
	set_skill("beiming-shengong",200);
	set_skill("liuyang-zhang", 200);
	set("chat_chance_combat", 30);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
           
	}) );
	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");

        set("force", 500);
        set("max_force", 500);
        set("force_factor",0);

        set("inquiry", ([
        "����" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
         ]) );
        //create_family("�һ���", 3, "����");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}



void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("lingjiujob") )
	this_player()->start_busy(1);

}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "½��˫����������Ӧ,�Լ��뿪�ˡ�\n" NOR,this_object());
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

if(((int)me->query("jinyong/book10")!=1))
return "�Ҳ���ʶ�㰡������\n";

me->set_temp("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "��λ���ѣ���������һؼ����Ϻ����һ�úø�л��ġ�\n";
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


if(me->query_temp("lingsong") == 0 )
return "�Ҳ���ʶ�㰡������\n";

if(((int)me->query("jinyong/book10")!=1))
return "�Ҳ���ʶ�㰡������\n";

 if( environment(ob)->query("short")=="�����Ϻ�")
         {




        fang = present("li mochou",where);
	if(fang)
	{
		who->start_busy(3);
return "��ʦ���ڣ��ܰ��ҶԸ�����? \n";
	}



          set_leader(0);
          write("���ڵ������Ϻ��ˣ���л��İ�æ����˵����Ҫ�������ִ���ˡ��һ�ȥ�����ġ�\n");

  	if(((int)me->query("jinyong/book10")==1))
	{
		
 	i = 900+random(2900);
	me->set("jinyong/book10",2);
	me->add("combat_exp",i+11880);
	me->add("potential",i*18);
	me->add("mpgx",10);
	me->add("expmax",2);

	tell_object (me,"��Ӯ����"+chinese_number(i+11880)+"�㾭��"+
	           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		
         }		

             me->set_temp("lingjiujob",0);
me->set_temp("lingsong",0);
             me->apply_condition("lingjiu_song",0);
        call_out("leavet",1);
	  
           return "��ȥ���ұ��ȥ��.....\n";  
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