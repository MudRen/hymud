 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("��ҩ��", ({ "medseller" }) );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "һ�������õ���ҩ�ĵĻ��\n");
        set("combat_exp", 5);
        set("chat_chance", 2);
        set("chat_msg", ({
                "��ҩ�ĸ߽е���ม��������ϰ�ҩ����\n",
                "��ҩ�ĸ߽е���ม����������衫��\n",
                "��ҩ�ĸ߽е���ม���������衫��\n",
                "��ҩ�Ľе������ģ�֪����Ȫ֮ˮ�𣿺�����Ȫˮ���ٶ������ţ�\n",
                "��ҩ�Ľе����������ҩ����������Ȫˮ���������ģ���ĵط�������ȥ��\n", 
        }) ); 
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/sendrug",
                __DIR__"obj/keedrug",
                __DIR__"obj/gindrug",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{
        add_action("do_buy", "buy");add_action("do_list", "list");
}     
