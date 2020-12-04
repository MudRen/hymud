 //Tie
inherit NPC;
inherit F_VENDOR;
int tell_him();
int tell_him2();
void create()
{
        set_name("���ƹ�", ({ "li", "boss li" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "���˾ӵ��ƹ�Ҳ�����˾ӵ��ϰ壬��˵�����ܴ󣮣�����\n");
        set("combat_exp", 70000);
        set("attitude", "friendly");
        set("title", "���˾��ϰ�");
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set("vendor_goods", ({
                __DIR__"obj/mijiu",
                __DIR__"obj/sg",
                __DIR__"obj/sg2",
                __DIR__"obj/sg3",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
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
        switch( random(10) ) {
                case 0:
                        say(  name()+"Ц�����˵������λ"
                                + RANK_D->query_respect(ob)
                                + "��һ��Ǯһ�ֻ������ɱ��������Ŷ�� \n");
                        break;
                case 1:
                        say( name()+"Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����������Ѱɡ� \n");
                        break; 
        }
} 
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/mijiu":60,
                __DIR__"obj/sg":7,
                __DIR__"obj/sg2":8,
                __DIR__"obj/sg3":9,
        ]) );
}      
