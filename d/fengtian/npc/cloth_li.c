// cloth_li.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;



mapping clothes = ([
	"t_chougua" : ([
		"name" : HIC"���д��"NOR,
		"value": 250000,]),
	"b_chougua" : ([
		"name" : HIB"�������"NOR,
		"value": 220000,]),
	"s_skirt"   : ([
		"name" : WHT HIM"�λ���ȹ"NOR,
		"value": 250000,]),
	"l_skirt"   : ([
		"name" : WHT HIG"����ȹ"NOR,
		"value": 300000,]),
]);

void create()
{
        set_name("����", ({ "boss li","li" }) );
	set("title","����");
        set("gender", "Ů��" );
        set("age", 45);
        set("long","����һλ���ɵ����긾Ů��\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
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
	carry_object(__DIR__"obj/hua_skirt")->wear();
}


void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");

}