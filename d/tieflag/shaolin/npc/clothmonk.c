 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
        string *name = ({"��","ȫ","ƴ","��","��","��","��"});
        set_name("��"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
        create_family("������", 23, "����");
        set("long", "���Ƕ����´�����ר�������ر��ĺ���\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(1000)+1000);
        set("attitude", "friendly");
        set_skill("unarmed", 80+random(10));
        set_skill("jingang-quan",random(10)+70);
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"Ц������˵�ĳ��ϼ���ǰ��Ȼ��С��ɵ�����Ѱ����ѹ�˻�����\n",
        }) );
        set_skill("move",40);
        set_skill("force",20);
        map_skill("unarmed", "jingang-quan");
        set("chat_chance_combat", 10);
        set("neili",50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        set("max_neili",50);
        set("force_factor",2);
        set("cps",60);
	set("vendor_goods", ({
                __DIR__"obj/monk_cloth2",
	}));
        setup();
        carry_object(__DIR__"obj/monk23_cloth")->wear();
        carry_object(__DIR__"obj/ironfist")->wield();
} 
void init()
{ 	add_action("do_buy", "buy");
	add_action("do_list", "list");}        
