#include <ansi.h>
inherit ITEM;
#include "/quest/menpai/givegift.c"
void create()
{
        set_name(HIR"门派密件"NOR, ({ "mi jian"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
                        "一封军机密件,记载着各个门派情况。最好把他销毁了(xiaohui)。\n");
                set("value", 0);
                set("material", "paper");
		 
         }
}
void init()
{    
	add_action("do_xiaohui", "xiaohui");
}

int do_xiaohui(string arg)
{
	string msg;
 object ob;
int exp,pot,base_exp,a;
	int i;
	object fang,who,where;
        int count,add_exp;
        object *team,boss,me;
object maxpot,obj;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);
              
		me=this_player();
        ob=this_object();
		if(!arg||arg!="mi jian") return notify_fail("你要销毁什么？\n");
        if(ob->query("okname")!= me->query("id")
			||me->query("mjb2job")!="夺宝")
		return notify_fail("这件事好像和你没关系吧?\n");
		if (!present("mi jian",me) )
        return notify_fail("你身上没有密件。\n"); 
        //check ok

        fang = present("sha shou",where);
	if(fang)
	{
		who->start_busy(3);
         return notify_fail("你先解决现有的强敌吧！\n");
	}

        fang = present("boss killer",where);
	if(fang)
	{
		who->start_busy(3);
 return notify_fail("你先解决现有的强敌吧！\n");
	}

    if( me->is_busy() )
	return notify_fail("你的动作还没有完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正打得热闹呢!。\n");

      if(!ob->query("iskillok") && (random(20)==0 || wizardp(me)))
      {
      message_vision("突然突然杀进一个武林高手 对$N说道： 把你的小命交出来吧!\n",who);	
      	fang = load_object("/quest/menpai/boss");
	fang->move(environment(who));	
	fang->initlvl(me->query_skill("force",1)+50);
        fang->set("combat_exp",me->query("combat_exp",1));
        fang->set("str", me->query("str"));
        fang->set("dex", me->query("dex"));
        fang->set("per", me->query("per"));
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (!i) i=1;
        fang->set("qi",fang->query("max_qi")*i);
        fang->set("eff_qi",fang->query("max_qi")*i);
        fang->set("max_qi",fang->query("max_qi")*i);

        fang->set("jing",fang->query("max_jing")*i);
        fang->set("eff_jing",fang->query("max_jing")*i);
        fang->set("max_jing",fang->query("max_jing")*i);

        fang->set("neili",fang->query("max_neili")*i);
        fang->set("max_neili",fang->query("max_neili")*i);
	fang->kill_ob(who);
     ob->set("iskillok",1);
     where->set("iskillok",1);
      return 1;  
      }	

		message_vision("$N从怀中掏出一只火折点燃了密件。\n"+HIR"只听「轰」的一声，密件在火中慢慢化为灰烬 。\n"NOR, me);
       count=me->query_temp("team_count");
		if (count<2) count=2;	
               
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
if (!count)
{
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);

addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	

}	

		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb2_busy"))
			{ 
			 add_exp=100;
		     exp=random(800)+800;
		     pot=exp*2/3+random(200);
		     team[i]->delete_temp("team_count");

             if (environment(me)==environment(team[i])) addnl(team[i],"exp",exp);;

team[i]->clear_condition("mjb2_busy");		
team[i]->clear_condition("mp2_kill");
team[i]->delete("quest");
team[i]->delete("task_time");
team[i]->delete("mjb2job");
team[i]->delete_temp("team_count");
			}
			} 
		}



    me->start_busy(3);
       
		  me->delete_temp("team_count");
         	  
		  destruct(this_object());
          return 1;
}

