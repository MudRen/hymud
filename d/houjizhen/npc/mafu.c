// mafu.c
// by dicky

inherit NPC;

void create()
{
        set_name("���", ({ "ma fu", "mafu", "ma"}));
        set("age", 32);
        set("gender", "����");
        set("long", "�������ѱ���С��ƣ�ƽʱ����������ƥ��\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set("chat_chance",2);

        setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        say("��������˵�����Լ�����ϵ�ã�����ʧ�ˣ������Լ������飿\n");
}

