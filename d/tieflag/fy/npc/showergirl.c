 inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
        set_name("СѾ��", ({ "yahuan" }) );
        set("gender", "Ů��" );
        set("age", 14);
        set("title", "�绨����");
        set("long",
                "һ��������а��СѾ��\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
                __DIR__"obj/white_towel",
        }));
    set("inquiry", ([
        "fatman" : (: tell_him :),
        "������" : (: tell_him:),
        ]));
        set_skill("unarmed",5);
        set_skill("jingang-quan",5);
        set_skill("dodge",5);
        set_skill("wuxing-dun",5);
        map_skill("dodge","wuxing-dun");        
        map_skill("unarmed","jingang-quan");
        setup();
        carry_object(__DIR__"obj/green_cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N�ڰ�æ��̧��ͷ����$nһ�ۡ�\n",this_object(),ob);
                        break;
        }
}
int tell_him()
{
    object me;
    me =this_player();
    tell_object(me,"СѾ�ߵ��������춼��������Ҳ�������ո��ߣ�\n");
        if(me->query_temp("marks/sword_almost")) {
                me->set_temp("marks/sword_almost2",1);
        tell_object(me,"�����Ƕ������ĵģ����ȥ����(search)˵���������Է��������µĶ�����\n");
        }
    return 1;
}      
