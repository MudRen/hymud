//Writen by lnwm (May.28.1997)
//man.c

inherit NPC;

void create()
{
        set_name("����", ({ "nan ren","man","ren" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
"һ�����͵��Ĵ�ũ�����彡׳����������ʵ����\n"
        );
        set("combat_exp", 3000);

        set("inquiry", ([
        "����"          : "����һ���к���һ��Ů��",     
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({                             
"����ʰ���������ũ�ߡ�\n",
"����ת��ͷ������˵��������������£��к���.\n",
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
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
        if( !ob || environment(ob) != environment(this_object()))
             return;
        write("\n���˿�����������������һ��ͷ���ֽ���æ����Ļ\n");
}                                                     




