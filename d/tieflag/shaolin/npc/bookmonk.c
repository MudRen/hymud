 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("����", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
        create_family("������", 23, "����");
        set("long", "���Ƕ����´�����ר�������ر��ĺ���\n");
        set("vendetta_mark","shaolin");
        set("class","shaolin");
        set("combat_exp", 120000);
        set("attitude", "friendly");
        set("cps",60);
        set("neili",250);
        set("max_neili",250);
        set("force_factor",20);
        
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"Ц������˵�ĳ��ϼ���ǰ��Ȼ��С��ɵ�����Ѱ����ѹ�˻�����\n",
        }) );
        
        set_skill("unarmed", 100);
        set_skill("jingang-quan",random(10)+70);
        set_skill("dodge",60);
        set_skill("shaolin-shenfa",60);
        set_skill("move",40);
        set_skill("force",20);
        map_skill("dodge","shaolin-shenfa");
        map_skill("unarmed", "jingang-quan");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
	set("vendor_goods", ({
                __DIR__"obj/tuoben",
	}));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/ironfist")->wield();
} 
void init()
{
	 	add_action("do_buy", "buy");
	add_action("do_list", "list");
	 
	 } 
