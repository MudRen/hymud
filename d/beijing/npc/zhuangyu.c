// zhuangyu.c
inherit NPC;
#include <ansi.h>
int ask_weiwang();
string ask_huijia();
string ask_daojia();
void create()
{
	set_name("ׯ�ʳ�", ({ "zhuang yuncheng", "zhuang","yuncheng" }) );
	set("gender", "����" );
	set("age", 40);
	set("int", 28);
	set("long","���Ǹ�����ʫ�飬ȴ���޸���֮����������\n��༭����ʷ���ԡ�������֮�ٸ淢��ȫ�Ҵ��뾩�С�\n" );
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("noget", "ׯ�ʳ�̾�����Ҳ����ˣ����߰ɡ������ҵ����Ҽ����˰���\n");
	set("chat_chance", 5);
	set("chat_msg", ({
	"\nׯ�ʳ�˵����ֻ���ҵ������ģ������м��˽�Ҷ��������\n"
	"˭�������Ĺ��εļһﾹȻ��ȥ�淢���ҡ���...\n",
	"\nׯ�ʳ�˵����˭Ҫ����֮��ץ��ׯ���ͺ��ˡ�\n",
	"ׯ�ʳ�ͻȻ˵��: ������������Ҫ�������ߴ��кô�����\n",
	"\nׯ�ʳ�̾�˿�����˵������֪�������鷿�����ܣ�ֻ��ϧ�ҳ���ȥ����\n",
	"ׯ�ʳ�˵����˭Ҫ�����ң���һ������֪���Ķ���������\n",
	}));
	set("inquiry", ([
		"����" : "���ݵ��鷿���б�����",
		"�鷿" : "�鷿���Ƿ�������ѧ�ʡ�",
		"��"   : "�ƶ��Ƿ���ʱ�����з���ġ�",
		"����" : "�ƶ��Ƿ���ʱ�����з���ġ�",
		"����" : "������һ�£�������һ�¾����ˡ�",
		"����" : "�ǿɲ������������������ѧ�ʵġ�",
		"��֮��" : "�����͵�ׯ��ȥ�кô���",
		"����" : (: ask_weiwang :),
		"��������" : (: ask_weiwang :),
	        "����" : (:ask_huijia:) ,
        "����" : (:ask_daojia:) ,
	]) );
	
        set("str", 65);
	set("int", 25);
	set("con", 25);
	set("dex", 65);
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("combat_exp", 50000);
	set("score", 50000);
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say( "ׯ�ʳ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("ׯ�ʳ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}

void init()
{
	object ob = this_player();
	int i;

	if(!userp(ob)) return;
	if(interactive(ob) && !is_fighting() ) 
	say("ׯ�ʳǹ���Ц�������������������ˣ�\n��λ" + RANK_D->query_respect(ob)+"�������ı����ɲ��ٰ�����Ҫ��ʲô�����׵ģ��������Ұɡ�\n");
	i=(int)this_player()->query("weiwang");
	if(i<20) 
	{
		i=i+10;
		this_player()->set("weiwang",i);
		message_vision(HIC"\n$N�Ľ�����������ˣ�\n"NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(i));
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("name") == "��ʷ����") 
	{
		write(HIC "\nׯ�ʳ�Ц���������н�Ҷ�ӣ��ѵ��㲻֪����\n" NOR);
		write(HIC "ׯ�ʳ�˵�����Ұ���֮������ץ��ׯ��ȥ�ɣ��Ҳ����ˡ�\n" NOR);		
		write("ׯ�ʳǴ��˿�������˵��ׯ���ھ��Ƕ����ߡ�\n");
	}		
	return 1;
}





string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(!me->query("jinyong/book7") )
return "�Ҳ���Ҫ���͡�\n";
if((int)me->query("jinyong/book7")!=2)
return "�Ҳ���Ҫ���͡���\n";
me->set_temp("lingsong",1);
set_leader(me);
ob->set_leader(me);
ob->set("lingsong",10);
return "��л�������һؼҼ����ǿ����ķ���.\n";
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

if(!me->query("jinyong/book7")  )
return "�Ҳ���Ҫ���͡�\n";
if(me->query_temp("lingsong") == 0 )
return "�Ҳ���Ҫ���͡���\n";



 if( environment(ob)->query("short")=="ׯ������")
         {


    

          set_leader(0);
          write("���ڵ�����.\n");


             me->set_temp("book733",1);

             me->set_temp("lingsong",0);
             //me->apply_condition("menggu_song",0);
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