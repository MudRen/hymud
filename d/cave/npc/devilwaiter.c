 // waiter.c
inherit NPC;
#include <ansi.h>
inherit F_VENDOR;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("���³���", ({ "devil waiter","waiter" }) );
        set ("nickname",HIR"�˳�"NOR);
        set ("title","������ �ֶ����");
        set("gender", "����" );
        set("age", 52);
        set("long",
        "û����֪�����˵��������������س�������������ʮ��Ķ������ɵ������֣�\nҲû��֪������ʲô��ֻ֪�����ǰ��³��˷ֶ�֮�е�Ψһ��һ������\n�����������Ҳֻ�й�����ɱ��������ˡ�\n");
        set("attitude", "friendly");
        
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("class","bat");
        set("force",1000);
        set("max_neili",1000);
        set("force_factor",50);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("blade",150);
        set_skill("bat-blade",500);
        set_skill("meng-steps",150);
        set_skill("move",200);
        set_skill("blade",150);

        
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
   map_skill("blade","bat-blade");
        map_skill("parry","bat-blade");

        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
        "���³��������������ϵ�Ѫ�������������ӣ��૵���������ƺ�û���ˣ�\n��ȥŪЩ���ʵĲ��ǡ���\n",
        "���³����з����۾�������һ�ۣ�ҹ�ɰ��Ц�������ʳ��������������\n�ٺ٣���ζ�����ϡ�\n",
        }) ); 
        set("rank_info/respect", "�˳�");

        
        	set("vendor_goods", ({
		__DIR__"obj/renroubao",
		__DIR__"obj/bloodleg",
	}));
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/butcherknife")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(4));
} 
void init()
{       
        object ob;
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}   
