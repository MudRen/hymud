
// box_boss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����ү", ({ "boxboss", "lin" }) );
        set("title", "�ײ����ϰ�");
        set("gender", "����" );
        set("age", 55);
        set("long", "��λ��Ŀ���Ƶ����˾�Ӫ�ײ����Ѿ��кܶ����ˡ�\n");
        set("str", 29);
        set("int", 14);
	set("max_kee",800);

	
	set("vendor_goods", ({
		__DIR__"obj/zhiqian",
		__DIR__"obj/zhihua",
		"/d/city/npc/obj/baozi",
	}));	
        set("combat_exp", 2000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
	set_temp("apply/armor",20);

        set("inquiry", ([
                "�ײ�" : "����ô�����Ҫ�ײģ����˵�ɣ�",
                "������" : "��Ҳ֪��'�̺�����'����¥���ڽֶ��棬�ҳ�ȥ�ġ�", 
        ]) );

        setup();
        add_money("silver", 4);
        add_money("coin", 100);
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
message_vision("$N����$nһ�۵���ľ��û���������ˣ�̪�������ˡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N��$n�ʵ���˭���ˣ�\n",this_object(),ob);
                        break;
        }
}
