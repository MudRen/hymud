#include <ansi.h>

inherit NPC;
int ask_job2();
void create()
{
	set_name("������",({"yang tiexin","yang"}));
   set("gender","����");
   set("mingwang",5000);
   set("combat_exp",60000);
   
set("age",45);
   set("qi",6000);
   set("max_qi",6000);
set("food",2500);
set("water",2500);
   set("neili",5000);
   set("max_neili",5000);
   set("force_factor",10);
set("pubmaster",1);
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("club",280);
   set_skill("yangjia-qiang",320);
        map_skill("club", "yangjia-qiang");
        set("inquiry", ([
        "��������" : (:ask_job2:) ,
         ]) );
   setup();
   add_money("silver",10);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tiespear")->wield();
}
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeh"))      
		who->set_temp("learn_timeh", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("yangjia-qiang",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("yangjia-qiang",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("yangjia-qiang",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeh",i);

      message_vision("�����Ķ�$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeh") <= 0) return 0;
else         
ob->add_temp("learn_timeh",-1);
return 1;
}


int ask_job2()
{

        object me = this_player();
        object ob,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        who=me;
        if(((int)me->query("jinyong/book5")!=1))
           {
                      message_vision("$N����$n˵�����������׻�û�п�ʼ��\n", this_object(), me);
	                      return 1;
            }

        if(!me->query_temp("book521"))
           {
                      message_vision("$N����$n˵����÷������˵�������� �ܰ��ҳ������ħͷ��?\n", this_object(), me);
	                      return 1;
            }    

        if(!me->query_temp("book522"))
           {
                      me->set_temp("book5222",1);
                      message_vision("$N����$n˵�����ܰ��ҽ̳��ҵ����Ӱ�ϧ����?\n", this_object(), me);
	                      return 1;
            }    

      if(!query("iskillok"))
      {
      message_vision("ͻȻ���С��ү���տ�����תɱ�˹��� ˵�����������ף���Ӯ���ˡ�!\n",this_object(),who);	
      	fang = load_object(__DIR__"wanyankang");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
return 1;
      }	



                    
        if(!me->query_temp("book524"))
           {
                      message_vision("$N����$n˵�������Ӯ���տ�����?\n", this_object(), me);
	                      return 1;
            } 
if((int)me->query("jinyong/book5")!=2)
{
message_vision("$N˵������л���������ֻ��÷���������ˣ�����Ϊ��������\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",2);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+9000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}		
                return 1;
                           
}