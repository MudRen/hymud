#include <ansi.h>
inherit ITEM;
#include "/quest/givegift.c"
void create()
{
        set_name(HIR"�����ܼ�"NOR, ({ "mi jian"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ������ܼ�,�������������ؾ��ı�������\n");
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
        int i,exp,pot,count,base_exp,add_exp;
        object ob,me,*team;
              
		me=this_player();
        ob=this_object();
		if(!arg||arg!="mi jian") return notify_fail("��Ҫ����ʲô��\n");
        if(ob->query_temp("host")!= me->query("id")
			||!me->query_condition("zzz_busy")||!me->query_temp("team_count"))
		return notify_fail("����º������û��ϵ��?\n");
		if (!present("mi jian",me) )
        return notify_fail("������û���ܼ���\n"); 
        //check ok
		message_vision("$N�ӻ����ͳ�һֻ���۵�ȼ���ܼ���\n"+HIR"ֻ�����䡹��һ�����ܼ��ڻ���������Ϊ�ҽ� ��\n"NOR, me);
        count=me->query_temp("team_count");
		if (count<2) count=2;	
        base_exp=1600/count;
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("zzz_busy")
			&& environment(me)==environment(team[i]))
			{if(!team[i]->query("zzz_job_count"))
		     team[i]->set("zzz_job_count",1);
             else
		     team[i]->add("zzz_job_count",1);  
			 add_exp=team[i]->query("zzz_job_count")/10;
		     if (add_exp > 3800)  add_exp=3800;
		     exp=base_exp+random(200)+add_exp;
		     pot=exp*2/3+random(100)+100;
exp=exp*2/3+100;
addnl(team[i],"exp",exp);
			 tell_object(team[i],HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
			}
			} 
		}
		  me->delete_temp("team_count");
         	  
		  destruct(this_object());
          return 1;
}
