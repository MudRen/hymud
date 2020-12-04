// guofu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_huijia();
string ask_daojia();
void create()
{
    set_name("����", ({"guo xiang", "guo", "xiang"}));
    set("gender", "Ů��");
    set("age", 15);
    set("long", "���ǹ������ص�СŮ������а��ҩʦ��С����Ů������ʲô�ɰ���\n");

    set("attitude", "peaceful");
       
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 0);
       
    set("combat_exp", 80000);
    set("score", 0);
       
    set_skill("force", 80);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("luoying-zhang", 80);
    set_skill("dodge", 80);
    set_skill("anying-fuxiang", 80);
    set_skill("parry", 80);
    set_skill("sword", 80);
    set_skill("luoying-shenjian", 80);
    set_skill("qimen-wuxing", 80);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
         set("inquiry", ([
        "Ӫ��" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
         ]) );      
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("lingjiujob") )
	this_player()->start_busy(1);

}


string ask_huijia()
{
	int i;
	object who,where,fang;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(((int)me->query("jinyong/book10")!=7))
return "�Ҳ���ʶ�㰡������\n";

        fang = present("jinlun fawang",where);
	if(fang)
	{
		who->start_busy(3);
return "���ַ����ڣ��ܰ��ҶԸ�����? \n";
	}
if (!ob->query("killfw"))
{
      	fang = load_object(__DIR__"fawang");
	fang->move(environment(who));	
	fang->kill_ob(who);
ob->set("killfw",1);
set("killfw",1);
}

if(!me->query_temp("book10101"))
return "��ֻ���Ŵ�ܽ��ַ����Ĵ�Ӣ�ۡ�\n";

me->set_temp("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "��������һ�������ֿڡ��Ҹ�ĸ��úø�л��ġ�\n";
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

if(((int)me->query("jinyong/book10")!=7))
return "�Ҳ���ʶ�㰡������\n";

 if( environment(ob)->query("short")=="��ֿ�")
         {




          set_leader(0);
          write("���ڵ������ˣ���л��İ�æ��\n");

  	if(((int)me->query("jinyong/book10")==7))
	{
		
 	i = 2000+random(3900);
	me->set("jinyong/book10",8);
	me->add("combat_exp",i+31880);
	me->add("potential",i*28);
	me->add("mpgx",20);
	me->add("expmax",2);

	tell_object (me,"��Ӯ����"+chinese_number(i+31880)+"�㾭��"+
	           chinese_number(i*28)+"��Ǳ��"+"��ʮ�����ɹ��� ����ɳ����ޣ���\n");
message("channel:chat", HIB"������III����˵"+who->name() + "�����������µ���������!"NOR"\n", users());
		
         }		

             me->set_temp("lingjiujob",0);
me->set_temp("lingsong",0);
             me->apply_condition("lingjiu_song",0);
        call_out("leavet",1);
	  
           return "��ȥ���Ҷ���ȥ��.....\n";  
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