 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("�����", ({ "fishseller" }) );
        set("gender", "����" );
        set("age", 35);
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("per",1);
	set("vendor_goods", ({
                __DIR__"obj/freshfish",
                __DIR__"obj/shrimp",
     	}));
        set("chat_chance", 5);
        set("chat_msg", ({
                "����ĸ���ߺ�ȵ���ʮ��һ��ඣ���������������㣮����\n",
                "�����˵��������һ�����������\n",
                "�����˵��������һ�����������\n",
                "����ĵ�ͷ��˼������\n",
        }) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
		add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/freshfish" : 10,
                __DIR__"obj/shrimp" : 300,
        ]) );
} 
