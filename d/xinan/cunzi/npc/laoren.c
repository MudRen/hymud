//Writen by lnwm (May.28.1997)
//laoren.c

inherit NPC;
string do_accept();
void create()
{
        set_name("老人", ({ "lao ren","ren","man" }) );
        set("gender", "男性" );
        set("age", 70);
        set("long",
"一个无儿无女的老头，瘦得不成样子，据说几年前逃荒来到这里，就住下了\n"
        );
        set("combat_exp", 100000);
        set("social_exp", 200000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 40);


        set("inquiry", ([
        "来历"          : "我是个无儿无女的老人,还有什么来历",     
        "青城逍遥子"    : (:do_accept:),
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({
"老人轻轻地叹了口气\n",
"老人眼望着天花板，仿佛要看穿它似的，然后忽然自语道:我究竟是谁?\n",
"老人转过头来看了你一眼，忽然说:我身上好冷，谁能给我熬一碗姜汤?\n",
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
        write("\n床上的老人转过头看了你一眼，又无力地把头转了回去\n");
}

int accept_fight(object me)
{
        write("\n老人奇怪地看了你一眼，转过头不再理你\n");
        return 0;
}

int accept_object(object who, object ob)
{
        if(ob->query("id") == "jiang tang")
        {
            command("say 这位"+RANK_D->query_respect(who)+"\n");
            command("say 您真是个好心人,现在好心人不多了 \n");
           write("\n老人喝下了姜汤,精神看起来好多了\n");
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
                write("老人一下从床上坐了起来\n");
                command("say 哈哈,居然还真有人记得老夫的名字!");
                command("laugh");
                msg = "难得你心好.老夫没什么做见面礼,这幅画老夫已收藏多年，现在就送给你吧.";

//这个地方似乎应再加点好东西,一本书好象太少了??????????

                ob = new(__DIR__"obj/nicebook");
                ob->move(me);
                me->delete_temp("marks/niceman");
                me->delete_temp("marks/yunyou");
                }
                else
                {
                write("老人突然一回身,眼神忽然变的精光四射\n");
                command("say 你怎么知道的?");
                msg = "是又怎么样,不是又怎么样?";
                command("heng");
                }            
        }
        else
        {
                command("shake");
                msg = "你一定是搞错了";
        }
        return msg;

}

int destroy(object ob)
{
        destruct(ob);
        return 1;
}

