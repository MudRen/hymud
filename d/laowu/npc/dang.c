 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�ƿ���", ({ "keqing" }) );
        set("gender", "Ů��" );
        set("age", 21);
        set("long",
                "��λ�ƿ���Ц����������㡣\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);

	set("vendor_goods", ({
                __DIR__"obj/egg",
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));        
        set("force",300);
        set("max_neili",300);
        set_skill("unarmed",100);

        setup();
        carry_object(__DIR__"obj/bigcloth")->wear();
}
void init()
{
 	add_action("do_buy", "buy");
	add_action("do_list", "list");
        ::init();
} 
