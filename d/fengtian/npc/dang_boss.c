// dang_boss.c

inherit NPC;

void create()
{
	set_name("�����ϰ�", ({ "dangpu laoban" }) );
	set("gender", "����" );
	set("age", 42);
	set("long","����һλ������թ�������ˣ����
��Ŀ�����һ�ۡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;
        command("say ����ȫ��Ӫҵ������׿������ӭ�ݹˡ�\n");
}
