//Writen by lnwm (May.28.1997)
//woman.c

inherit NPC;

void create()
{
        set_name("����", ({ "fu ren","woman" }) );
        set("gender", "Ů��" );
        set("age", 35);
        set("long",
"һ�����͵��Ĵ�����Ů�ˣ����ǿ�����ææµµ�ġ�\n"
        );
        set("combat_exp", 1000);

        set("inquiry", ([
        "����"          : "����һ���к���һ��Ů��",     
        "�к�"          : "������С���������㿴�������ڻ�û�л���",
        ]) );

        set("chat_chance", 10);
        set("chat_msg",({                             
"Ů�˷�������Ļ���˿�����˵�����Ǹ�С����ô����������\n",
"Ů�˷�������Ļ���˿����棬תͷ���ɷ�˵����Ҳ����ȥ���ҡ�\n",
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
            call_out("greeting", 2, ob);
        }
}                            

void greeting(object ob)
{
    object obj;
    if( !ob || environment(ob)!= environment(this_object()) )
        return;
        write("\nŮ�˿����������Ц��Ц��˵:'�����'.\n");
        write("\nŮ��˵���볢�������Լ����Ĳ�Ҷ��\n");
/*
    if( objectp(present("hua cha",ob) ) && !me->query_temp("marks/lnwm/���")�)
    {
        write("\nŮ�˵ݸ���һ����衣\n");
        obj = new( __DIR__ "obj/tea");
            obj -> move(ob);
        
    }
*/
}                                                     




