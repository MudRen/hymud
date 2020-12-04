 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�鱦��", ({ "jade seller", "seller" }) );
        set("gender", "����" );
        set("age", 49);
        set("long", "����һλ������˪�ĵ��ƹ�\n");
        set("combat_exp", 700000);
        set("str", 300);
        set("attitude", "friendly");
        set_skill("blade", 130);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 130);
        set_skill("dodge", 100);
        set_skill("parry", 120);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
	set("vendor_goods", ({
		__DIR__"obj/jade1",
		__DIR__"obj/jade2",
		__DIR__"obj/jade3",
		__DIR__"obj/jade4",
		__DIR__"obj/jademonk",
		__DIR__"obj/snake_drug",
		__DIR__"obj/amber1",
	}));

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/jadeblade")->wield();
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
        switch( random(2) ) {
                case 0:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "���������� \n");
                        break;
                case 1:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮���Į���飬������һ�鵲�ְɡ� \n");
                        break; 
        }
}  

