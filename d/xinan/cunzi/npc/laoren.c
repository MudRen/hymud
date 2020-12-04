//Writen by lnwm (May.28.1997)
//laoren.c

inherit NPC;
string do_accept();
void create()
{
        set_name("����", ({ "lao ren","ren","man" }) );
        set("gender", "����" );
        set("age", 70);
        set("long",
"һ���޶���Ů����ͷ���ݵò������ӣ���˵����ǰ�ӻ����������ס����\n"
        );
        set("combat_exp", 100000);
        set("social_exp", 200000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 40);


        set("inquiry", ([
        "����"          : "���Ǹ��޶���Ů������,����ʲô����",     
        "�����ң��"    : (:do_accept:),
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({
"���������̾�˿���\n",
"�����������컨�壬�·�Ҫ�������Ƶģ�Ȼ���Ȼ�����:�Ҿ�����˭?\n",
"����ת��ͷ��������һ�ۣ���Ȼ˵:�����Ϻ��䣬˭�ܸ��Ұ�һ�뽪��?\n",
        }) );
        
        setup();
        carry_object(__DIR__"obj/pocloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}                            

void greeting(object ob)
{
        if ( !ob || environment(ob) != environment(this_object()) )
            return;
        write("\n���ϵ�����ת��ͷ������һ�ۣ��������ذ�ͷת�˻�ȥ\n");
}

int accept_fight(object me)
{
        write("\n������ֵؿ�����һ�ۣ�ת��ͷ��������\n");
        return 0;
}

int accept_object(object who, object ob)
{
        if(ob->query("id") == "jiang tang")
        {
            command("say ��λ"+RANK_D->query_respect(who)+"\n");
            command("say �����Ǹ�������,���ں����˲����� \n");
           write("\n���˺����˽���,���������ö���\n");
            command("thank "+ who->query("id"));
            remove_call_out("destroy");
            call_out("destroy",1,ob);
                who->set_temp("marks/niceman",1);
            return 1;
        }
        return 0;
}

string do_accept()
{       
        string msg;
        object me,ob;
        me = this_player();
        if((int)me->query_temp("marks/yunyou"))
        {
                if((int)me->query_temp("marks/niceman"))
                {
                write("����һ�´Ӵ�����������\n");
                command("say ����,��Ȼ�������˼ǵ��Ϸ������!");
                command("laugh");
                msg = "�ѵ����ĺ�.�Ϸ�ûʲô��������,������Ϸ����ղض��꣬���ھ��͸����.";

//����ط��ƺ�Ӧ�ټӵ�ö���,һ�������̫����??????????

                ob = new(__DIR__"obj/nicebook");
                ob->move(me);
                me->delete_temp("marks/niceman");
                me->delete_temp("marks/yunyou");
                }
                else
                {
                write("����ͻȻһ����,�����Ȼ��ľ�������\n");
                command("say ����ô֪����?");
                msg = "������ô��,��������ô��?";
                command("heng");
                }            
        }
        else
        {
                command("shake");
                msg = "��һ���Ǹ����";
        }
        return msg;

}

int destroy(object ob)
{
        destruct(ob);
        return 1;
}

