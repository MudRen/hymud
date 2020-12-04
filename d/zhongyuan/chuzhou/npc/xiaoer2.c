// ���ݾ�¥�ĵ�С�� /d/city/chuzhou/npc/xiaoer2.c
// by lala, 1997-12-14

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��С��", ({ "xiao er", "waiter"}) );
        set("gender", "����" );
        set("age", 22);
        set("long",
        "��С�����಼���������ϴ��ſ�ײ�������æ���к����ˡ�\n"
        );
        set("combat_exp", 1200);
        set("chat_chance_combat", 5);
        set("chat_msg_combat",({
                "��С���������������㲻Ҫ���ˣ����ڳ��ݳ���ɱ�˷Ż��ˣ���������\n",
                "��С���ߴ�ߺ�����ɱ����������������������\n",
        }) );
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
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
        switch( random(5) ) {
        case 0 : case 1 :
                break;
        case 2:
                say( "��С���ü��ϵİײ���Ĩ��Ĩ���ӣ�˵��������λ" + RANK_D->query_respect(ob)
                        + "�������������\n");
                break;
        case 3:
                say( "��С��˵��������λ" + RANK_D->query_respect(ob)
                + "�������г�����Ͼƣ����볢������\n");
                break;
        case 4:
                say("��С���ü��ϵİײ���Ĩ��Ĩ���ӣ�˵��������λ" + RANK_D->query_respect(ob)
                + "�������������ݵĵط����ˣ���\n");
                break;
        }
}
