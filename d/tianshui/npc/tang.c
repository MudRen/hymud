// tang.c

inherit NPC;

void create()
{
        set_name("���ƹ�", ({ "tang zhanggui","tang" }) );
        set("gender", "����" );
        set("age", 42);
        set("long",
                "�Һ�����ϳ���һ˫�������۾���\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
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
	say("���̾������˵����ţ���������׿������ӭ�ݹˡ�\n");
}