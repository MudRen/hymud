// design by ���ֺ�(find) . all right reserved.

// judge.c

inherit NPC;

void create()
{
        set_name("����", ({ "judge" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����ϵı���·��ǿ�������ڴ����Ǯһ�㡣\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "��" : "�͹�����Ǯ���Ҿ����ˡ�\n",
        ]) );

        setup();
        add_money("silver", 1);
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
        switch( random(2) ) {
                case 0:
                        say( "���ٺ������������İɣ���ȫɫ����һ��ˣ���\n");
                        break;
                case 1:
                        say( "���ٺ������������İɣ����˲Ƴ���԰�Ĺ��������ѡ������\n");
                        break;
        }
}
