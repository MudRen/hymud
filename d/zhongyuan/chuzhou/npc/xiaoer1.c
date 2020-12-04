// ���ݿ͵��С�� /d/city/chuzhou/npc/xiaoer1.c

inherit NPC;

void create()
{
        set_name("��С��", ({ "xiao er","waiter"}) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��С�����಼��������Ц���еؿ����㣬�����ⷿ��\n"
        );
        set("combat_exp", 10000);
        set("chat_chance_combat", 5);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
        
        set("chat_msg_combat",({
                "��С���������������㲻Ҫ���ˣ����ڳ��ݳ���ɱ�˷Ż��ˣ���������\n",
                "��С���ߴ�ߺ�����ɱ����������������������\n",
        }) );
        set("inquiry", ([
                "�ⷿ" : "�������͹�Ҫ�ⷿ���ã�һ��������ӡ���",
                "ס��" : "���͹���Ҫ�ⷿ�ɣ���",
        ]) );
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
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
        say( "��С��Ц�����˵��������λ" + RANK_D->query_respect(ob)
                + "������ЪЪ�Űɡ��������ס���ģ���\n");
}

int accept_object(object who, object ob)
{
        if( ob->value() >= 8000 ) {
                say("��С������Ǯ��Ц���е�˵����������������\n");
                who->set_temp("can_sleep", 1);
                return 1;
        } 
        return 0;
}
