 // waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("ЦЦ", ({ "xiao xiao", "cici"}) );
        set("gender", "Ů��" );
        set("title",HIR"̽����"NOR);
        set("age", 22);
        set("long", "ЦЦ��Ц����˵������˼���в�����֮�£�һЦ��ǧ�
ЦЦ������Ϊ������裬�ϲˣ��˼��˰���\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("no_fly",1);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "ЦЦ˵���͹���Ҫ��ˮ���Ƕ���ˮ����\n",
                "ЦЦ˵���͹��벻Ҫ�ڴ˴򶷣����ǻ������˵�ม�\n", 
        }) );        
        set("resistance/kee",100);
        set("resistance/sen",100);
        set("resistance/gin",100);       
        
 	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/d/city/npc/obj/sniurou",
		"/d/city/npc/obj/sjiudai",
	//"/clone/misc/newpaper",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        
} 
void init()
{       
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
