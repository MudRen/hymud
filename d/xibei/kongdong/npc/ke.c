inherit NPC;


void create()
{
        set_name("�����", ({ "jinxiang ke","ke" }) );
        set("gender", "Ů��" );
        set("age",60);

        set("combat_exp",2000);
        set("social_exp",2000);
        setup();    
	carry_object(__DIR__"obj/linen")->wear();
        add_money("coin",10);
}
