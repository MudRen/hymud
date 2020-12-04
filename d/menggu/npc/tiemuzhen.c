inherit NPC;
#include <ansi.h>
int ask_job2();
int ask_job3();
void create()
{
   set_name("��ľ��",({"tiemuzhen"}));
   set("gender","����");
   set("title", HIR"�ɹŴ�"NOR);
      set("long","��ľ�����ɹŲ�ԭ��Ӣ��!\n");
   set("shen",25000);
   set("combat_exp",500000);
     set("age",45);
set("pubmaster",1);
    set("food",250);
    set("water",250);
   set("qi",65000);
   set("max_qi",65000);

   set("jing",25000);
   set("max_jing",25000);
   
   set("neili",25000);
   set("max_neili",25000);
   set("force_factor",60);
	set("inquiry", ([
                "����ĸ��" : (: ask_job2() :),
	"�˱�" : (:ask_job3:) ,
	"��ƽ" : (:ask_job3:) ,
	]) );
	
  set("qi", 93900);
        set("max_qi", 93900);
        set("jing", 93900);
        set("max_jing", 93900);
        set("neili", 91500);
        set("max_neili", 91500);
        set("jiali", 50);

        set("combat_exp", 9500000);
        set("score", 200000);
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("hand",500);
        set_skill("staff", 500);
        set_skill("taixuan-gong", 550);

set_skill("huanhe-dao", 580);
set_skill("sata-shenfa", 550);
set_skill("sumi-jian", 550);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 550);
set_skill("strike", 500);
set_skill("cuff", 500);
set_skill("unarmed", 500);
set_skill("blade", 500);
set_skill("sword", 500);
set_skill("club", 500);
set_skill("finger", 500);
set_skill("qinnashou", 580);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);


	setup();
   carry_object("/clone/weapon/gangdao")->wield();
   carry_object("clone/cloth/cloth")->wear();
	add_money("gold",1);
}


int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timea"))      
		who->set_temp("learn_timea", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("qinnashou",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("qinnashou",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("qinnashou",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timea",i);

      message_vision("��ľ���$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);
      tell_object(who,"�������������ľ��ѧϰ�ˡ�\n");

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timea") <= 0) return 0;
else         
ob->add_temp("learn_timea",-1);
return 1;
}



int ask_job2()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;


                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��˵����ĸ���Ǳ������ݺ��ӵ����������ѵġ�");
                command("say " + RANK_D->query_respect(me) + " ������С��ɽ�������أ����п�ȥ�������ɡ�\n" NOR);
                me->set_temp("book511", 1);

                return 1;
                           
}

int ask_job3()
{



 object me = this_player();
        object ob,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        who=me;
        
                if(((int)me->query("jinyong/book5")!=8))
           {
                      message_vision("$N����$n˵����ûʲô�����˵ġ�\n", this_object(), me);
	                      return 1;
            }
        
        if(!me->query_temp("book590"))
           {
                      message_vision("$N����$n˵����Ҫ���˱���Ҫ��һ�����׵������\n", this_object(), me);
	                      return 1;
            }  

        if(!me->query_temp("book591"))
           {
                      message_vision("$N����$n˵����Ҫ���˱���Ҫ��һ���ܱ�������\n", this_object(), me);
	                      return 1;
            }  

        if(!me->query_temp("book592"))
           {
                      message_vision("$N����$n˵����Ҫ���˱���Ҫ��һ�²��̨�������\n", this_object(), me);
	                      return 1;
            }  

        if(!me->query_temp("book593"))
           {
                      message_vision("$N����$n˵����Ҫ���˱���Ҫ��һ�²������������\n", this_object(), me);
	                      return 1;
            }  
        if(!me->query_temp("book594"))
           {
                      message_vision("$N����$n˵����Ҫ���˱���Ҫ��һ������������\n", this_object(), me);
	                      return 1;
            }  

if((int)me->query("jinyong/book5")==8)
{
message_vision("$N˵�����ã���Ҳ���ˣ���Ҳ�䲻�˴���ˣ��Ϳ�����ķ��ϣ���ʱ�˱���\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",9);
		who->add("combat_exp",i+19000);
		who->add("potential",i*19);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+19000)+"�㾭��"+
		           chinese_number(i*19)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}		

                return 1;
                           

                           
}