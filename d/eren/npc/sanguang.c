#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title","��������");
        set("nickname","��⣬�ع⣬��Ҳ��");
        set("long", "һ���ɰ˵ĺ������ڹ�̨�����Ŀ�������ȸ������ϡ���˫�����������
���滹�����˺����׵�ë�����ֱ��ϥ�ǡ�\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren");
                        
        set("max_atman",1000);
        set("atman",1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1500);
        set("neili",1500);
                set("no_get_from", 1);
                set("no_get", 1);
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );

        set_name("��ԯ����",({"sanguang","san guang"}));
        set("age",40);
        set("gender","����");
   set("str",50);
        set("force_factor",100);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}
void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
