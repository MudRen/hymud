#include "/quest/where.h"
#include "/quest/givegift.c"

string ask_job()
{ 
  object  ob, me,gift,*team,obj;
  int exp,position,i;
  mapping target;
  string str;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if (interactive(ob) && (int)ob->query_condition("huang_mission"))  
       return ob->query("name")+"����һ�ε�����û���!";
  if (interactive(ob) && (int)ob->query_condition("huang_busy"))  
       return ob->query("name")+"�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
  if (interactive(ob) && (int)ob->query_condition("guojob2_busy"))  
       return ob->query("name")+"�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
       if ((int)ob->query_condition("gf_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("feitian2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("gf_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("gumu_job"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("hu_song"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("huang_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("huaxunshan"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("husong_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("hxsd_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lingjiu_song"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lingxiao2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("ljjob2"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lyjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lyjob2"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("menggu_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("mingjiaojob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("mr_job"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("nonamejob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("quanzhenjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("riyue_guard"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("riyuejob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("roomjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("ry2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("shaolin_song"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("taohuajob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("tz_job"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("wdj2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("xsjob2"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("xsjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("xh_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("wudangjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("bt2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("dali_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("emeijob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("menpai_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("yl2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("zzz_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("yue_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";


	if(exp<=500000)     
    return "����书̫����,����ǿ�������ɡ�\n";
    
	target = wheres[random(sizeof(wheres))];
    //for(i=100;i*i*i/10<=exp;i++);//i=maxpot
	//obj=new(__DIR__"killer1");
	if(random(10)>7)
	{obj=new(__DIR__"skiller"+sprintf("%d",random(3)+1));
	 i=i+10+random(10);
	 if (ob->query_skill("force",1)>=1) i=(int)ob->query_skill("force",1);
	 obj->do_copy(ob,i);
	 obj->set("title",HIR"����һ��"NOR);
	 ob->set_temp("huang_job_super",1);
	}
	else
	{ obj=new(__DIR__"killer");
	  i=i-random(10);
	  if (ob->query_skill("force",1)>=1) i=(int)ob->query_skill("force",1);
	  obj->do_copy(ob,i);
	}
	obj->move(target["weizhi"]);
	obj->set_temp("must_killby",ob->query("id")); 
	obj->set_name("����", ({ob->query("id")+" tufei","tu fei"}));
    ob->set_temp("huang_job_target", target["chinese"]);//where
    ob->apply_condition("huang_mission",30);
    ob->apply_condition("menpai_busy",13);
    ob->start_busy(2);
	command("nod");
	str=ob->query("name")+" ����ָ��������ڡ�"+target["chinese"]+"��һ����������";
	command("say "+str);
    return "��ȥѲ��һ�¡�";
	
}

int ask_jobover()
{
  object  ob, me,gift,*team,obj,who;
  int exp,position,i;
  int pot,count;
  mapping target;
  string str;
  ob=this_player();
  me=this_object();
  who=this_player();

        if ( !who->query_temp("huang_job_target") ) {
                command("say �ð��������������������");
                return 0;
        }
	       	if (!who->query_temp("must_killby"))
		{       command("shake");
                command("say ��ɱ�˵�������?");
                return 0;
        } 


	       	if (who->query_temp("must_killby")!= who->query("id"))
		{       command("shake");
                command("say ��ɱ�����ˡ�");
                return 0;
        } 

      who->set_temp("huang_given",1);
      who->set_temp("must_killby",0);
      who->delete_temp("must_killby");
      

        command("pat" + who->query("id"));
        command("say ���ĺã����͸�!");
        if(!who->query("huang_job_count"))
		who->set("huang_job_count",1);
        else
		who->add("huang_job_count",1);        
		count=who->query("huang_job_count");
		if (count>10) count=count/10;
		if (count>400) count=400;
		//for(i=0;i*i<count;i++);
		exp=320+random(18)+count;
        if(who->query_temp("huang_job_super"))
        {exp+=150;
		 who->delete_temp("huang_job_super");
		}
if (who->query("mud_age") - who->query_temp("mud_age") >100)		
{
if ((i = (who->query("combat_exp") - who->query_temp("temp_exp")) * 60
/ (who->query("mud_age") - who->query_temp("mud_age"))) > 100)
i = i*60;
if (exp>1500) exp=1500;
if (i > 30000)
{
exp=exp/3+1;
pot=pot/3+1;
}
}		
	who->add_temp("nbjob47",1);
exp=exp/2+38;
addnl(who,"exp",exp);
        
        who->clear_condition("huang_mission");
		who->delete_temp("huang_job_target");
        who->delete_temp("huang_given");
		who->apply_condition("huang_busy",3+random(3));

        return 1;

}





string ask_fangqi()
{
         object me;
         me = this_player();
         if(!me->query_temp("huang_job_target"))
         return "��û��������,������Ϲ����ʲ��?";
         if (me->query("combat_exp",1) > 50000) me->add("combat_exp",-100);
         me->apply_condition("huang_mission",18);
         me->delete_temp("huang_job_target");
	     return "û��ϵ,�´μ���Ŭ�� ��";
}

string ask_gonglao(object who)
{
  object me;
  int i;
           
  me = this_player();
  if(!me->query("huang_job_count"))
  i=0;
  else 
  i =(int)me->query("huang_job_count"); 
  message_vision(CYN"$N��$n˵��:���Ѿ������" + chinese_number(i) + "������\n"NOR,who,me);
  return "����Ŭ���ɣ�";
}
