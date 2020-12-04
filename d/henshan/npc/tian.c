//NPC /d/henshan/npc/tian.c
#include <ansi.h>
inherit NPC;
string ask_me();
string ask_live();
string ask_tast();
string ask_job();
string ask_kill();
string ask_jiebai();
object me = this_player();

void greeting(object ob);
int accept_fight(object ob);
#include "/quest/givegift.c"
void create()
{
	seteuid(getuid());
	set_name("�ﲮ��", ({ "tian boguang", "tian" }));
        set("title","�ɻ�����");
        set("nickname",HIY"ǧ��ɻ��Ҷ���"NOR);
        set("long", 
                "�����ǽ�����һ������\n"
                "һ������еȵ�׳�����ӣ�ü���۽Ǵ�����������֮�⣬��ʱ��������ۡ�\n");
	set("gender", "����");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);

        set("per", 23);
	set("str", 85);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

set("pubmaster",1);
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 3800);
	set("max_jing", 3800);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 10);

	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("blade", 100);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("lingxu-bu", 150);
	set_skill("touch", 300);
	set_skill("kuangfeng-blade", 200);
         set("inquiry", 
               ([      "����" : (: ask_kill :),
                       "���" : (: ask_tast :),
                       "job" :  (:ask_tast:),
                       "����" : (: ask_job :),
                       "help" : (: ask_job :),
                       "����" : (:ask_job :),
                       "�ɻ�" : (:ask_tast:),
                       "�ؼ�" : (:ask_me :),
                       "����Ժ" : "�ǿ������ݳ���ĺ�ȥ�����������û�ٻ����ӵ�Ǯ" ,
                       "fuck" : "��ȳ���̥�����£����㻹�����ң�" ,
                       "�����" : "��ܺ�ӯӯ���ɾ�һ�������ǿ�"  ,
                       "����" : "���ǧ����������������ӿ����Ҫ���ҵ��������Ǹ�ɥ���ǰ���" ,
                       "���" : (:ask_jiebai :),
                       "girl" : (:ask_live :),
                       "woman" : (:ask_live :),
                       "jiebai" : (:ask_jiebai :),
               ]));

	map_skill("cuff", "touch");
	map_skill("unarmed", "touch");
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

        set("chat_msg_combat", ({
                (: perform_action, "blade.kuang" :),
        }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"�ﲮ��Ц�������Ҳû��ϵ�����ͷ���������¾���С�����ˡ�\n",
                "�ﲮ��̾�������Դ����˲�����ͺ¿�����������ѹ����������أ���֪���տ����١�\n",
                "�ﲮ�����������죬����˭�ܰ����Ҹ�椾ͺ��ˡ�\n",
                 "�ﲮ�ⴹͷɥ����˵����Ҳ��֪������Ժ����������ʲô�»�ɫ��\n",
                 "�ﲮ���Ȼ����һ�񣺡�ǰ����·��ɽ��С�壬�Ǹ��д��ĳ��Ŀ�������Ĳ�����\n",
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();
     add_action("do_want", "Ҫ");
     add_action("do_want", "yao");
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="Ů��")
	{
if (ob->query("age")<26) say("�ﲮ��Ц����������������һ��С���\n");     
else say("�ﲮ��Ц������������ϧ̫���˵㣬�ҿ�ûθ�ڡ�\n");     
	}
	else say("�ﲮ��Ц�������֣���λ"+RANK_D->query_respect(ob) + "�������������С��������Ҳûʲô�£����������ž��ǡ�\n");
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "Ů��")
	{
		write("�ﲮ��Ц���������ɱ��̫��ϧ�˵ġ�\n");
		return 0;
        }
	return 1;
}
 
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeg"))      
		who->set_temp("learn_timeg", 0);

    if (environment(who)->query("short")!="����¥")
         {
           command ("say ����ʲô�ط���,�����ǻ���¥��!");
           return 0;
          }

        if (userp(ob))
         {
           command ("say ����ҿɲ���Ҫ!");
           return 0;
          }

       if (ob->query("gender") == "Ů��"
       && ob->query("per") <= 22)
         {
           command ("say ��ô�ѿ��Ļ�ɫ���Լ����!");
           return 0;
          }
       
       if (ob->query("gender") == "Ů��" && ob->query("age") <= 25)
      {
          if  (this_player()->query_temp("findgirl"))
         {
           this_player()->set_temp("findgirlok",1);
           command ("thumb" + this_player()->query("id"));
           message_vision("�ﲮ��ɫ���Եؿ���$N����ͣ���ʿ�ˮ��\n",ob);
           message_vision("�ﲮ�����$N������Ц,�úã���Ҫ�ú�л�㣬˵�ɣ���Ҫʲô��\n" , this_player());
           tell_object(this_player(), "������ Ҫ(yao)  money, exp, ... \n");
       call_out("destroying", 0,ob);
           return 1;
          }
      }

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("touch",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("touch",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("touch",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeg",i);

      message_vision("�ﲮ���$N˵������Ȼ�������ͬ�����ˣ��Ҿͽ�����ְɡ�\n",who);


	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeg") <= 0) return 0;
else         
ob->add_temp("learn_timeg",-1);
return 1;
}
int do_want(string arg)
{
	int exp;
	       me = this_player();

        if (me->query_condition("menpai_busy"))
        {
                  tell_object(me,"����Ҫ��Ϣһ�ᣬ��Ȼ�������!\n");
                   return 0;
        }


        if ( !me->query_temp("findgirl"))
       { 
       command("kick " + me->query("id"));
       message_vision("�ﲮ�⳯$N��Ȼ��ŭ������ʲôҲû�ɣ�Ҳ����Ҫ�����������ӹ�һ��ȥ��\n", me);
      return 1;
        }
        if ( !me->query_temp("findgirlok"))
       { 
       command("kick " + me->query("id"));
       message_vision("�ﲮ�⳯$N��Ȼ��ŭ������ʲôҲû�ɣ�Ҳ����Ҫ�����������ӹ�һ��ȥ��\n", me);
      return 1;
        }

//       if (!me->query("tianjob") || stringp(me->query("tianjob")))       { 
//       command("kick " + me->query("id"));
//       message_vision("�ﲮ�⳯$N��Ȼ��ŭ������ʲôҲû�ɣ�Ҳ����Ҫ�����������ӹ�һ��ȥ��\n", me);
//      return 1;
//        }

      if( !arg || arg==""  ) return 0;
      if( arg == "money" ) 
      {    message_vision("�ﲮ�⳯$N�ٺ�һ�֣����벻��������λ���ԡ�\n", me);
           new("/clone/money/gold.c")->move(me);
           tell_object(me, "�ﲮ�����һЩ�ƽ�\n");
me->start_busy(3);
      }
      if ( arg == "exp" )
       {
           message_vision("�ﲮ�⳯$N���˵�ͷ:���������ˣ�����ȷʵ���ҵȿ���֮����\n", me);
       exp=50+random(100);
       exp=exp/2+18;
addnl(me,"exp",exp);
me->start_busy(3);
me->apply_condition("menpai_busy",4);
       }
       if ( arg ==  "all")
        {   command("faint " + me->query("id"));
            message_vision("�ﲮ�⾪�ȵض�$N����:���벻�����Ǹ����̰������ļһ\n", me);
            command("slap " + me->query("id"));
        }    
           this_player()->delete_temp("findgirl");
           this_player()->delete_temp("findgirlok");
           this_player()->add("tianjob", 1);
if (me->query("tianjob") || !stringp(me->query("tianjob")))
  { 
           if (me->query("tianjob") >1 && me->query("tianjob") <= 5)
           me->set("title", "�ɻ�С��");
           if (me->query("tianjob") >5 && me->query("tianjob") <= 20)
           me->set("title", "�ɻ���");
           if (me->query("tianjob") >20 && me->query("tianjob") <= 40)
           me->set("title", "�ɻ�����");
           if (me->query("tianjob") > 40)
           me->set("title", "�ɻ����");
}
           me->add("shen", -2000);
           message_vision("�ﲮ���Ȳ�������˵�������ˣ����Ҹ������裬������Ҫ��ȥ�����ˡ�\n" , me);
return 1;
          
        }   
string ask_me()
{
         return RANK_D->query_respect(this_player()) + 
                "��ѧ���ֶ�ԭҲ���ѣ��ɲ�֪�ܷ���ҽ����ȣ�";
}
string ask_live()
{            return "ԭ��" + RANK_D->query_respect(this_player()) +
        "��������ͬ�������ء�";
}
string ask_tast()
{       
             this_player()->set_temp("findgirl", 1);
            return  "�����ɣ��������̫��������Ҹ㼸��椰ɣ��һ�ú�л��ġ�";
}
string ask_job()
{
//             command("chat* touch " + this_player()->query("id"));
              return "������ܰ���ɱ�˲�������ͺ���ң��ң���Ҫʲô�Ҹ�ʲô��";
              this_player()->set_temp("killmonk", 1);
}
string ask_kill()
{               if (this_player()->query("jiebai1"))
                return "�����Լ��ֵ��ˣ����������Ц��";
                command ( "say ԭ����������ͺ¿��ͬ�������ˣ���������");
                kill_ob(this_player());
                return "�������ҵ����絶�£�Ҳ������컯��";
 }
 string ask_jiebai()
{            
               if (!this_player()->query("tianjob") || stringp(this_player()->query("tianjob")))
              {
                  message_vision("�ﲮ�⳯$N����һ�ۡ�\n", this_player());
                  return "����˭��?";
               }

                  if (this_player()->query("jiebai1"))
              {
                  message_vision("�ﲮ�⳯$N����һ�ۡ�\n", this_player());
                  return "�����Լ��ֵ��ˣ����������Ц��";
               }
  
               if (this_player()->query("tianjob") <= 20)
       {         message_vision("�ﲮ�⳯$N�����һƲ�졣\n", this_player());
                 command("say ����ĳ���䲻�ţ��ɽύ��Ҳ���Ƕ������صĺ�����"); 
                 return "����Ŭ���ɰɡ�";
        }
                if (this_player()->query("tianjob") <= 60)
            {    message_vision("�ﲮ�⳯$N���ȵؿ���һ�ۡ�\n", this_player());
                message_vision("�ﲮ�⳯$N���˼��۾���\n", this_player());
                return "��Ҫ�����ֵܣ����ٶ�Ϊ�ֵ�Ū����椲��У����㹻������˼�ˡ�";
            }
                 if (this_player()->query_temp("bujie") < 1)
                {
                   command("say��Ϊ������ȷʵ�����£�ֻ���ⲻ�䲻������ίʵ���Ұ����ǡ�");
                   return "�����ɣ���ȥ����������������ͺ¿��������ô���Ǻ��ֵܣ�����и�ͬ����Σ�";
                 }
                 {
                     me->delete_temp("bujie");
                     command("say �ã��ã�����ĳ�����ʶ���㣬�������ĸ��ˡ�");
                     command("chat �Ӽ�����"+this_player()->name(1)+"��������ĳ�˵ĺ��ֵܣ����ͬ��ͬ�ѣ������츣��");
                     this_player()->set("jiebai1", 1);
                     return "�ӽ����ʲô���£��ֵܾ��ܷԸ�����ĳ�������ǡ�";
                   }
          }

void destroying(object ob)
{   
   if(!ob) return;
if (!userp(ob))
{
if(ob) destruct(ob);
}
}
