 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���ƹ�", ({ "old zhanggui", "zhanggui" }) );
        set("gender", "����" );
        set("age", 69);
        set("long","��λ���е����ƹ�����æ������ž�������������ˡ�\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) 
              {
                case 0:
                message_vision("$N�������ϻ��ۿ���$nһ�ۣ�˵������ӭ��λ"+RANK_D->query_respect(ob)+
                               "���ٱ����У�\n",this_object(),ob);
                break;
                
                case 1:
                message_vision("$N���ᴷ�˴�����ļ��˵������λ"+RANK_D->query_respect(ob)+
                          "��Ҫ��ʲô��ʽ�Ĵ���\n",this_object(),ob);
                break;
                
                case 2:
                message_vision("$N˵������Ҫѯ���⴬�ļ۸���ο�����ļ۸��ƣ�����\n",this_object(),ob);
              }
} 
int accept_object(object who, object ob)
{
        int val;
        object paper; 
//        message_vision(CYN"$N˵������̫�󣬺�����ͣ��\n"NOR,this_object());
//        return 0;
      val = ob->value();
    if ( val < 5000 ) 
           {
         message_vision("$N������üͷ������λ�͹٣�Ǯ��������\n",this_object());
             return 1;
           }
        paper = new(__DIR__"obj/contract");
    if ( val>=5000 && val < 500000 ) paper->set("shiptype", 0);
    else if ( val >=500000 && val < 5000000 ) paper->set("shiptype", 1);
    else if ( val >=5000000) paper->set("shiptype", 2);
        paper->set("employer",who->query("name"));      
        paper->move(who);
        say( "���ƹ�˵������л��λ" + RANK_D->query_respect(who) +
             "��˱����У�����������Լ����ͷ���Ϻ��ꡣ\n");
        return 1;
}      
