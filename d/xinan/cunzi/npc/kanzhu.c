//Writen by lnwm
//kanzhu.c

inherit NPC;

void create()
{
        set_name("������", ({ "kanzhu ren","ren" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
"һλ����ææµµ�����ӵ�����ũ��������һ�ɲ񵶡�\n"
        );
        set("combat_exp", 5000);

        set("inquiry", ([
        "����"          : "����������������ɽ��ȥ��",     
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({                             
"�����˰ѿ��µ���������һ����\n",
"�����˲������ϵĺ������������������ͱ���ɽȥ����\n",
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/chaidao")->wield();
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
    if( !ob || environment(ob) != environment( this_object() ) )
        return;

        write("\n�����˿��������߹���������һ��ͷ���ֽ���æ����Ļ\n");
}                                                     




