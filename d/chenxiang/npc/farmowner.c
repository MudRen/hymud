 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("ũ�ߵ��ϰ�", ({ "owner" }) );
        set("gender", "����" );
        set("age", 35);
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("per",1);
set("vendor_goods", ({
                 __DIR__"obj/b1",
                __DIR__"obj/b2",
	}));
        set("inquiry", ([
                "ɱ�˰�" : "�Ǽһ��аѵ��������ĵ���������ɱ�ģ�\n",
                "murder" : "�Ǽһ��аѵ��������ĵ���������ɱ�ģ�\n",
        ])); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{        
        ::init();
		add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void reset()
{
        set("vendor_goods", ([
                 __DIR__"obj/b1" : 12,
                __DIR__"obj/b2" :6,
        ]) );
}
