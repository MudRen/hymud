// yang.c ���ϰ� 
#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("Ǯ��", ({ "qian bo" }));
	set("title", "�ӻ����ϰ塸�������塹");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"һ�����ֵ��ϰ壬��һЩ��ͨ����Ʒ����ʹ�� list �鿴�ɹ������Ʒ��\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/beixin",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
		"/d/xingxiu/obj/fire",
		"/clone/weapon/changjian",
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/d/city/npc/obj/sniurou",
		"/d/city/npc/obj/sjiudai",
	        "/d/bawang/npc/obj/shaoji",
	        "/d/welcome/npc/lbook1",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}



void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();
add_action("do_list", "list");
        add_action("do_buy", "buy");
	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}


}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

			say( HIG"Ǯ��Ц��˵������λС�ֵ�������Щʲô������㿴 ����ָ�� "+HIR+"list\n"NOR);
			say( HIG"Ǯ��Ц��˵���������Ҫ�� ����ָ�� "+HIR+"buy ��Ʒid\n"NOR);


}
