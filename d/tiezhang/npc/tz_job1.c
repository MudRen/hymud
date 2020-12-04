//tz_job1.c
#include <ansi.h>

string *names = ({"补寨栏","挖陷井","伐木",});
#include "/quest/givegift.c"

string ask_job1()
{
        object me;
        object ob;
        string target;
        mapping fam;
        ob=this_player();
        me=this_object();
        fam = ob->query("family");
        
        if(!fam || fam["family_name"] != "铁掌帮")
         return ("你不是我帮弟子，嘿嘿....来帮我们干活？是不是想混入铁掌帮当奸细？\n");
        if (ob->query_temp("job_name"))
         return ("你不是已经领了工作吗？还不快去做。\n");
        if ( (int)ob->query_condition("tz_job" ) > 0 )
                return RANK_D->query_respect(ob) + 
                "现在没有什么事可做，过段时间再来吧。";
         target = names[random(sizeof(names))];
         ob->set_temp("job_name",target);
         ob->apply_condition("tz_job", 3);
         return "铁掌帮既要防止官府对我们的清剿，还要防止江湖其它门派对我们帮会的寻仇，
你武功低微，先去" + target + "吧。";
}

int do_task(string arg)
{
        int pot,exp,shen,money;
        object ob,me,obj;
        ob=this_player();
        me=this_object();


        if(!(arg||arg=="ok")) return 0;
        if(!ob->query_temp("job_name")) 
            return notify_fail(MAG"裘千仞皱了皱眉，说道：没给你工作，你怎么跑来覆命了？\n"NOR);
        if(!ob->query_temp("mark/还了")) 
            return notify_fail(CYN"裘千仞说道：你先把工具还回工具房，再来覆命吧。\n"NOR);
        if(!(ob->query_temp("mark/伐完")||ob->query_temp("mark/挖完")
           ||ob->query_temp("mark/补完")))
            return notify_fail(CYN"裘千仞说道：你偷懒啊，叫你干活你不去干，跑来领功! \n"NOR);
        if( arg=="ok"&& (ob->query_temp("mark/伐完") || ob->query_temp("mark/挖完")
           || ob->query_temp("mark/补完")))
        {
          command("haha "+ob->query("id"));
          command("thumb"+ob->query("id"));
          command("say "+RANK_D->query_respect(ob)+"这是给你的奖赏！");

        money =(int)(ob->query_skill("guiyuan-tunafa",1)/12)+1;
        pot =45+random(10);
        exp =38+random(50);
        shen =random(200)+32;
        if (money> 5) money=5;
obj=new("/clone/money/silver");
obj->set_amount(money);
obj->move(ob);
exp=exp/2+8;
addnl(ob,"exp",exp);
        ob->add("shen",-shen);

        ob->delete_temp("job_name");
        ob->delete_temp("mark");        
        return 1;
        }
        return 1;
}

