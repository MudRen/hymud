 inherit NPC;
inherit F_VENDOR; 
void create()
{
    set_name("֣��", ({ "zhengjia", "zheng" }) );
    set("gender", "����" );
    set("age", 39);
    set("title", "�鱦��");
    set("long", "�������������ϵȵ����񣬶��Ҽ�Ǯ����\n");
    set("combat_exp", 7000);
    set("attitude", "friendly");
    set_skill("dodge", 100);
    set_skill("parry", 120);
	set("vendor_goods", ({
        __DIR__"obj/jade1",
        __DIR__"obj/jade2",
        __DIR__"obj/jade3",
        __DIR__"obj/jade4",
	}));
    set("inquiry", ([
        "����" : "����û�е���������������򼸿�����Ȼ����ʯ���ӹ��\n",
        "yubotao" : "����û�е���������������򼸿�����Ȼ����ʯ���ӹ��\n",
        "��ʯ��" : "��ʯ��������������ģ��������ϵá�һʯ�ȵ��������ס���\n",
        "wang" : "��ʯ��������������ģ��������ϵá�һʯ�ȵ��������ס���\n",
        ]));
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
		add_action("do_buy", "buy");
	add_action("do_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " ֣��Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "����������֣��򼸿�ɣ� \n");
                        break;
                case 1:
                        say( " ֣��Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮����򼸿�ɡ� \n");
                        break; 
        }
}   
void reset()
{
    set("vendor_goods", ([
        __DIR__"obj/jade1":7,
        __DIR__"obj/jade2":7,
        __DIR__"obj/jade3":7,
        __DIR__"obj/jade4":7,
        ]) );
} 
