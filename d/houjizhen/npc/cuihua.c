// tuihua.c
// by dicky

#include <ansi.h>
inherit NPC;
int ask_me1();
int ask_me();

void create()
{
        set_name("�仨", ({"cui hua"}) );
        set("nickname", HIG"ɽҰһ֦��"NOR);
        set("gender", "Ů��" );
        set("age", 12+random(6));
        set("long",
          "���Ǹ���ޢ������С�����˵��̤ѩɽׯ��һ�����������á�\n"
          "�ֽ��ڿ죬����ϲ������������΢ʾ�⣬���ȥ�Ӳ赹ˮ��\n");

        set("attitude", "friendly");
        
        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("per", 28);

        set("max_qi", 200);
        set("max_jing", 200);
        set("max_sen", 200);
        set("combat_exp", 2000);
        set("score", 1000);
        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 30);
        set_skill("parry", 20);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);
/*
         set("inquiry", ([
           "��ҩ����" : (: ask_me :),
           "rumor" : (: ask_me1 :),
             ]) );
*/
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("�仨Ц������˵������λ" + RANK_D->query_respect(ob)
             + "����������" + "����͸����ϲ衣\n");
}

void serve_tea(object who)
{
        object obn;
        object room;

        if( !who || environment(who) != environment() ) return;
        if( !who->query_temp("marks/sit") ) return;
        
        if( !objectp(room = environment()) ) return;
        if ( (int)who->query_temp("tea_cup") <= 0 )
        {
                obn = new("/d/houjizhen/obj/dawancha");
                obn->move(room);
                message_vision("�仨������������������ϵĴ���赹����\n",
                        who);
        } else 
        {
                who->add_temp("tea_cup", -1);
                obn = new("d/d/houjizhen/obj/xiangcha");
                obn->move(room);
                message_vision("�仨�ó�������С��������˱���裬�������ϣ�\n",
                        who);
        }
        obn = new("/d/houjizhen/obj/mitao");
        obn->move(room);
        message_vision("�仨�ó�һ�����ʵ�ˮ���ң��������ϣ�\n", who);
        
        return;
}


/*
int ask_me()
{
        object me, ob;
        ob = this_player();
        me = this_object();
       
        command("nod " + ob->query("id"));
    	command("say ż��������������Ϊ����ͣ��Ǹ��ܺõ��ˡ�\n");
	return 1;
}
int ask_me1()
{
        object me, ob;
        ob = this_player();
        me = this_object();
        if(!ob->query_temp("marks/ask2")){
         command("say " + RANK_D->query_respect(ob) + "��֪���Ƿ�������飿\n");
         return 1;
         }
        command("say ��˵��һλ���������ں�ɽ�����Ǻ��ٿ�������Ҳ��֪�������Ǽ١�\n");
        ob->set_temp("marks/taohua",1);
	return 1;
} 
*/ 