// tang.c ���ϰ� 

#include <ansi.h>
inherit NPC;
inherit F_BANKER;

int redeem(string arg);

void create()
{
       set_name("���Ͽ�", ({ "banker" }) );;
        set("title", "��Դ�ϰ�");
        set("gender", "����" );
        set("age", 26);
	set_max_encumbrance(100000000);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
                
"���Ͽ��Ǹ��������൱˹�ĵ������ˣ�������ʱ�����Щ�Ĳ����ɵ�\n"
                
"���ӣ���Զ�ǵľ�������Ͽ¶������е�����Ī��ĸо���Ϊʲ����\n"
                
"����������Ϊһ�Ҵ�Ǯׯ���ϰ壬������һ��ϡ��Źֵ��书����\n"
                
"�����Ͽ��ƺ������񵭣�������Щ���ߵķ�ǣ�ֻҪ���˲�ȥ������\n"
                "��Ҳ������ȥ�������ˡ�\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}


void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}

