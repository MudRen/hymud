// ren.c

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("��һ��", ({ "ren yili","ren" }) );
	set("title","���Ӵ���");

        set("gender", "����" );
        set("age", 42);
	set("sell_all_day",1);

	set("long","����һλ������������ˡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");

        
	set("vendor_goods", ({
__DIR__"obj/jiaozi"
	}));        
        setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}
