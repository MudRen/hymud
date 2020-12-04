 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("ҩ��С���", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 15);
        set("long",
"��С��Ƹ��Ӳ��ߣ���ɫ���ģ�һЦ��ʱ���¶��һ�Ž�׵����ݡ�
\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("per",23);
	set("vendor_goods", ({
                __DIR__"obj/astragalt",
                __DIR__"obj/dioscoreae",
                __DIR__"obj/codonopsis",
                __DIR__"obj/pilosulae",
                __DIR__"obj/lycii",
	}));
        set("inquiry", ([
                "���鲹Ѫ����" : "Ӵ�������Ҫ���ϰ��ˡ�\n",
                "soup" : "Ӵ�������Ҫ���ϰ��ˡ�\n",
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
command("say Ӵ���������ˣ�ûǮ��ҩô��\n");    
                        break;
        }
} 
int accept_object(object me, object obj)
{
        command("say ��л��λ" + RANK_D->query_respect(me) + "\n");     
        return 1;
} 
