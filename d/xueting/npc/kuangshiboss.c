// kuangshiboss.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��ʯ��", ({ "kuangshi boss" }) );
//	set("title","    ");
        set("gender", "����" );
        set("age", 42);
        set("long","����ʲô��ʯ�������Ͷ��ˡ�\n");
        set("combat_exp", 50);
        set("sell_all_day",1);
        set("attitude", "friendly");


        setup();
	carry_object("/clone/misc/cloth")->wear();
}
