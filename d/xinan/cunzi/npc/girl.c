//writen by lnwm
//girl.c

inherit NPC;

void do_smile();
void create()
{
        set_name("С����", ({ "little girl","girl" }) );
        set("gender", "Ů��" );
        set("age", 16);
        set("long",
          "һ��ǧ�����ĵ�С�������һ���������
���������Ц��\n"
        );
        set("combat_exp", 1000);

        set("chat_chance",10);
        set("chat_msg",({
"С����˵�����\n",
"С����˵����һ�����˺�Զ��·��\n",
"С����˵�����ܲ����ҳ�����\n",
//"С����˵����ʵ���Ѿ���С��\n",
        (:do_smile:),
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
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
     if( !ob || environment(ob) != environment(this_object()) )
         return;
     message_vision( "С����'ѽ'�ؽ���һ������Ȼ��$N����һ��\n", ob );
             
}

void do_smile()
{
        //string name;
        //name->query_id(thisplayer());
        //    command("shy");
    message_vision("С�����ߴ��ؿ�����һ��\n",this_player());
}       

