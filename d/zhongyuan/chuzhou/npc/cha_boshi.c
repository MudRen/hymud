// ���ݲ販ʿ /d/city/chuzhou/npc/cha_boshi.c
// by lala, 1997-12-14

#include <ansi.h>
 
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name( "�販ʿ", ({ "cha boshi","waiter"}) );
        set("gender", "����" );
        set("age", 36);
        set("long",
           "�����������վ�ڹ�̨���ϵĲ販ʿ������һ���衣\n"
        );
        set("combat_exp", 8000);
        
        set_temp("apply/attack", 20);
        set_temp("apply/attack", 30);
        set("chat_chance_combat", 10);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
        setup();
        carry_object("/clone/misc/cloth" )->wear();
    add_money( "coin", 10 + random(200) );
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
        say( "�販ʿ˵������λ" + RANK_D->query_respect(ob)
                + "������Ȳ軹�ǳԵ��ģ����ݵġ���˿���̡����Կ�ϧ������\n");
}

