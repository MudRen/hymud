 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("���˵�", ({ "caifan" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ��Ϊ��������ձ�����С���ˣ�\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "�϶���");
        set("chat_chance", 3);
        set("chat_msg", ({
                "���˵�Ц������һ��������ɣ��߲�һ��Ҷ�³�ʤ����\n",
        }) ); 
        set("vendor_goods", ({
                __DIR__"obj/smallvege",
                __DIR__"obj/bigvege",
                __DIR__"obj/midvege",
                __DIR__"obj/tomato",
                __DIR__"obj/cucumber", 
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        add_action("do_buy", "buy");add_action("do_list", "list");
} 