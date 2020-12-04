 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�ձ��Ϻ�", ({ "han" }) );
        set("gender", "����" );
        set("age", 55);
        set("long",
                "��λ�Ϻ�����첻���ˣ�����\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
                __DIR__"obj/nujiu",
                __DIR__"obj/xiaocai",
        }));
        set_skill("unarmed",5);
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
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N���صĴ����ţ���ǿ̧��ͷ��$nһ�ۡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$Nֱ��ֱ������ǿ��$n�������֡�\n",this_object(),ob);
                   break;
        }
}
