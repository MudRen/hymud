#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���Ƥ", ({ "huo bopi" }) );
        set("gender", "����" );
        set("title", "�����ϰ�");
        set("long",
"���Ƥ��Ȼ�����ջ���ʵ��Ҳ��̫��Ƥ�������Ҳ�����ι������ϵ�\n��ˮ���ѵ�Ȼ�ε��൱���ס���ֵ���Խ�������ˮ����Խ�����֡�\n������������ֻ����˵�Ұ���ӣ������ձ����۾�˵����ʱ��������\n�۽ǿ��������ʱ��ض��ڴ��������ϵĶ�������ֵ�������ӡ�\n");
        set("chat_chance",1);
        set("age", 55);
        set("chat_msg", ({
        "���Ƥ�޺޵�������˵������Ƕ���������������������ķ�������\n���ࡱ�ֽ���������������û����ѽ����Ǯ�ò��Ĳź��أ�\n",
                                })  ); 
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("per",30);
        set("no_arrest",1);
        set_skill("unarmed",80);
        set("richness",100000);
        set_skill("dodge",100);
        setup();
        carry_object("/clone/misc/cloth")->wear();
     add_money("gold", 2);
}
void init()
{       
        ::init();
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}      
