// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/wangshan.c

inherit NPC;inherit F_DEALER;

void create()
{
        ("huangfeng_wangshan_huangfeng");
         set_name("����", ({"wang an", "wang","lao ban"}));
        set("title", "���ϰ�");
        set("gender", "����");
        set("age", 25);
        set("long", "һ����׳�ĺ��ӣ���ü��Ŀ
����Ŀ���䵽������ϣ��㷢�������о���������������ֱ�ӣ�\n");

        set("combat_exp", 70000);

	set("neili", 200);
	set("max_neili", 200);
	set("force_factor", 5);

        set("vendor_goods", ({
                "/d/obj/armor/niupi",
                "/d/obj/weapon/sword/changjian",
                "/d/obj/weapon/blade/blade",
                "/d/obj/weapon/spear/tieqiang",
                "/d/obj/weapon/staff/chanzhang",
                "/d/obj/weapon/hammer/tongchui",
        }));

        setup();
        carry_object("/d/obj/cloth/hei")->wear();
        carry_object("/d/obj/weapon/hammer/tongchui")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
}

int accept_fight(object me)
{
        command("say �ðɣ��ͱȻ������ӣ������ܶൢ�����кö��û���أ�\n");
        return 1;
}

