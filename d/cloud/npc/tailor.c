
// tailor.c
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�÷�", ({ "tailor" }) );
        set("title", "��ׯ");
        set("gender", "����" );
        set("age", 42);
        set("long", "һλ����ȥ�ܺͰ����ϲ÷죬���ڷ����·���\n");
	set("str", 12);
	set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

//        set("where","north");
        set("inquiry", ([
		"������" : "��Ҳ֪��'�̺�����'����¥����б���棬�ҳ�ȥ�ġ�", 
        ]) );
set("vendor_goods", ({
		"/d/city/npc/cloth/belt",
		"/d/city/npc/cloth/boots",
		"/d/city/npc/cloth/bu-shoes",
		"/d/city/npc/cloth/cloth",
		"/d/city/npc/cloth/color-dress",
		"/d/city/npc/cloth/fu-cloth",
		"/d/city/npc/cloth/gui-dress",
		"/d/city/npc/cloth/hat",
		"/d/city/npc/cloth/jade-belt",
		"/d/city/npc/cloth/liu-dress",
		"/d/city/npc/cloth/marry-dress",
		"/d/city/npc/cloth/mini-dress",
		"/d/city/npc/cloth/moon-dress",
		"/d/city/npc/cloth/pink-dress",
		"/d/city/npc/cloth/qi-dress",
		"/d/city/npc/cloth/red-dress",
		"/d/city/npc/cloth/scarf",
		"/d/city/npc/cloth/sha-dress",
		"/d/city/npc/cloth/xian-cloth",
		"/d/city/npc/cloth/xiu-cloth",
		"/d/city/npc/cloth/xiu-scarf",
		"/d/city/npc/cloth/yan-dress",
		"/d/city/npc/cloth/zi-dress",
	}));

	setup();
	add_money("silver", 2);
	add_money("coin", 50);
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�ϲ÷�̧��ͷ������һ�ۣ��ʵ����͹��򲼻�������?\n");
                        break;
                case 1:
                        say( "�÷���ֽ�������������Ȼ�����˶����ˡ�\n");
	}
}

