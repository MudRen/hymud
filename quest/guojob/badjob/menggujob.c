#include <ansi.h>
#include "/quest/givegift.c"
mixed names = ({
        ({
        "朱雀外门","青龙外门","白虎外门","玄武外门",
        }),
        ({
         "宋兵","流氓","偏将","佐将","小贩","男孩","郭芙","老先生",
         "小孩","书店老板","武三通","穷汉","铁匠","朱子柳","店小二","宋兵",
	 "樊一翁","郭芙","郭襄","简捷","史伯威","史季强","史孟捷","史叔刚",
	 "史仲猛","武敦儒","武修文","耶律齐","程英",
        }),
        });

string ask_job()
{ 
  object  ob, me,newob;
  int exp,position;
  string target,myfam,obfam,job_type;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if (interactive(ob) && ob->query_temp("menggu_job_target")
      && (int)ob->query_condition("menggu_mission"))  
       return "你上一次的任务还没完成!";
  if (interactive(ob) && !ob->query_temp("menggu_job_target")
      && (int)ob->query_condition("menggu_mission"))  
       return "你办事不力，先等会吧。";
   
   
         if ((int)me->query_condition("gf_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("feitian2_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("gf_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("gumu_job"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("hu_song"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("huang_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("huaxunshan"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("husong_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("hxsd_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lingjiu_song"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lingxiao2_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("ljjob2"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lyjob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("lyjob2"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("menggu_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("mingjiaojob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("mr_job"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("nonamejob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("quanzhenjob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("riyue_guard"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("riyuejob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("roomjob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("ry2_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("shaolin_song"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("taohuajob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("tz_job"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("wdj2_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("xsjob2"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("xsjob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("xh_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("wudangjob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("bt2_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("dali_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("emeijob"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("menpai_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("yl2_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";
       if ((int)me->query_condition("yue_busy"))  
       return "这是件危险工作，我看"+me->query("name")+"需要休息一会！\n";

   
    if (interactive(ob) &&
       (int)ob->query_condition("menggu_busy"))  
       return "现在我可没有给你的任务，等会再来吧。\n";

if (ob->query_skill("force",1)<100)
       return "我看你的武功还不够啊。\n";

if (ob->query("shen")>0)
       return "我看你到像是一个奸细。\n";
	
	if(exp<=100000)     
    return "你的武功太差了,等练强了再来吧。\n";
    job_type="刺杀";
   	ob->set_temp("menggu_job_type",job_type);
        
	if(job_type=="刺杀")
	{target = names[1][random(sizeof(names[1]))];
        ob->apply_condition("menggu_mission",30);    
	ob->set_temp("menggu_job_target", target);
	ob->set_temp("mgjob", 1);
        newob = new(__DIR__"ling");
        newob->set("long", "
        绑架令
" + target + "。
        大元\n");
        newob->move(ob);

    message_vision(HIW"$N，对$n说道:有消息又有武林人士来增援襄阳,他好像要到"+target+"，这里，你把他干掉并把"+target+"绑架过来!\n"NOR , me,ob);
     if( (string)this_player()->query("family/family_name")=="神龙教" ) 
{     
        newob = new(__DIR__"item1");
        newob->move(ob);
    message_vision(HIW"$N，对$n说道：听说神龙教对用石灰对敌有心德，这包石灰粉就给你了!\n"NOR , me,ob);
}
     if( (string)this_player()->query("family/family_name")=="星宿派" ) 
{     
        newob = new(__DIR__"item2");
        newob->move(ob);
    message_vision(HIW"$N，对$n说道：听说星宿派对用蒙汗药对敌有心德，这包蒙汗药就给你了!\n"NOR , me,ob);
}
     if( (string)this_player()->query("family/family_name")=="雪山寺" ) 
{     
        newob = new(__DIR__"item3");
        newob->move(ob);
    message_vision(HIW"$N，对$n说道：听说雪山寺对用阴阳和合散对敌有心德，这包阴阳和合散就给你了!\n"NOR , me,ob);
}

	return "如果失败了，我要你的命!";
	}
}


string ask_fangqi()
{
         object me;
         me = this_player();
         if(me->query_condition("menggu_mission")<=1)
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->clear_condition("menggu_mission");
me->apply_condition("menggu_busy",8);    
destruct(present("hehe san",me));
destruct(present("meng hanyao",me));
destruct(present("shi huifeng",me));
me->clear_condition("menggu_mission");
me->delete_temp("menggu_job_target");
me->delete_temp("menggu_job_type");
me->delete_temp("mgjob");
		 me->delete_temp("menggu_job_type");
         return "下次不允许失败!! 。";
}

int accept_object(object who, object ob,object me)
{
	int exp;
        if ( ob->query("name") != who->query_temp("menggu_job_target")) {
                command("say 你给我这个干吗?");
                return 0;
        }


        if ( userp(ob)) {
                command("say 你给我这个干吗?");
                return 0;
        }

        if ( !who->query_temp("menggu_job_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

        if( who->query_temp("mgjob")!=3){
                command("say 你没有把武林侠士干掉还来要赏?");
                return 0;
        }

        if( who->query_temp("menggu_job_type")=="刺杀")
		if (ob->query_temp("must_killby")!= who->query("id")
			||ob->query("victim_user") )
		{       command("shake");
                command("say 你抓错人了。");
                return 0;
        } 
command("say 做的好!!为我们大汗立了大功。");
who->add_temp("mpjobn6",1);
exp=400+random(300);
exp=exp/2+108;
addnl(who,"exp",exp);
who->add("shen",-100);
who->clear_condition("menggu_mission");
who->delete_temp("menggu_job_target");
who->delete_temp("menggu_job_type");
who->delete_temp("mgjob");
destruct(present("hehe san",who));
destruct(present("meng hanyao",who));
destruct(present("shi huifeng",who));
call_out("destroying", 0, ob);
        return 1;
}



void destroying(object ob)
{
        destruct(ob);
        return;
}