 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("����", ({ "lenghong" }) );
        set("gender", "Ů��" );
        set("age", 21);
        set("title", "��ҩ���ϰ���");
        set("long",
                "��λ�ϰ�����б���ڹ�̨�ߣ�Ц����������㡣\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
	set("vendor_goods", ({
                __DIR__"obj/egg",
                __DIR__"obj/renshen",
                __DIR__"obj/lurong",
                __DIR__"obj/xiong", 
	}));         
        set_skill("unarmed",550);

        set_skill("dodge",550);

        setup();
        carry_object(__DIR__"obj/bigcloth")->wear();
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
message_vision("$N������Ц��������������۽����$nһ�ۡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����΢�ڣ�¶����֬�����ۣ���$n�������֡�\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N����$nһ�ۣ�����������ӣ��С����Ц������\n",this_object(),ob);
                        break;
        }
} 
