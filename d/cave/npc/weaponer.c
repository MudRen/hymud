 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void healing(); 
void create()
{
        set_name("ŷ��˷", ({ "ouyang shuo" }) );
        set("gender", "����" );
        set("age", 39);
        set("title", MAG"�ϵ���˪������"NOR);
        set("long",
                "һ����������������ˣ���̸ֹ�����š�\n");
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("class","beggar");
        set("per",30); 
        set("force",1800);
        set("max_neili",1800);
        set("force_factor",80);
        set("str",36);
        	set("vendor_goods", ({
        __DIR__"obj/shuangyi",
        __DIR__"obj/dragonsword",
        __DIR__"obj/dragonwhip",
        __DIR__"obj/fengblade",
        __DIR__"obj/duanshan",
        __DIR__"obj/meispear",  
        __DIR__"obj/pilihammer",    
	}));

        
        

        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("unarmed",140);

        

        
        setup();
        carry_object(__DIR__"obj/oucloth")->wear();
} 
void init()
{

	add_action("do_buy", "buy");
	add_action("do_list", "list");
        ::init();
}  

