//tz_job1.c
#include <ansi.h>

string *names = ({"��կ��","���ݾ�","��ľ",});
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
        
        if(!fam || fam["family_name"] != "���ư�")
         return ("�㲻���Ұ���ӣ��ٺ�....�������Ǹɻ�ǲ�����������ưﵱ��ϸ��\n");
        if (ob->query_temp("job_name"))
         return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
        if ( (int)ob->query_condition("tz_job" ) > 0 )
                return RANK_D->query_respect(ob) + 
                "����û��ʲô�¿���������ʱ�������ɡ�";
         target = names[random(sizeof(names))];
         ob->set_temp("job_name",target);
         ob->apply_condition("tz_job", 3);
         return "���ư��Ҫ��ֹ�ٸ������ǵ���ˣ���Ҫ��ֹ�����������ɶ����ǰ���Ѱ��
���书��΢����ȥ" + target + "�ɡ�";
}

int do_task(string arg)
{
        int pot,exp,shen,money;
        object ob,me,obj;
        ob=this_player();
        me=this_object();


        if(!(arg||arg=="ok")) return 0;
        if(!ob->query_temp("job_name")) 
            return notify_fail(MAG"��ǧ��������ü��˵����û���㹤��������ô���������ˣ�\n"NOR);
        if(!ob->query_temp("mark/����")) 
            return notify_fail(CYN"��ǧ��˵�������Ȱѹ��߻��ع��߷������������ɡ�\n"NOR);
        if(!(ob->query_temp("mark/����")||ob->query_temp("mark/����")
           ||ob->query_temp("mark/����")))
            return notify_fail(CYN"��ǧ��˵������͵����������ɻ��㲻ȥ�ɣ������칦! \n"NOR);
        if( arg=="ok"&& (ob->query_temp("mark/����") || ob->query_temp("mark/����")
           || ob->query_temp("mark/����")))
        {
          command("haha "+ob->query("id"));
          command("thumb"+ob->query("id"));
          command("say "+RANK_D->query_respect(ob)+"���Ǹ���Ľ��ͣ�");

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

