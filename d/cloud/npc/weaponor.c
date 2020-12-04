
// weaponor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "weaponor" }) );
        set("title", "������");
        set("gender", "����" );
        set("age", 32);
        set("long", "���������Ǹ������ˣ������˰̡�\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 60);

        set("inquiry", ([
                "������" : "����ר�����ֳ��̱���", 
        ]) );
//        set("where","north");

        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));
        setup();
        add_money("silver", 50);
        add_money("coin", 300);
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�������ӵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "���Ը�����һ�����ֵı�����\n");
                        break;
                case 1:
                        say( "��������ͻȻ������񣬺�����������������\n");
                        break;
				case 2:
						say("��������ͻȻ���ص�˵��������������к���������Ӵ����\n");
						break;
        }
}
