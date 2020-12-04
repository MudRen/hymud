// yu_fanzi.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string *valid_rooms = ({
"lu19",
"lu18",
"lu17",
"lu16",
"lu5",
});

void do_move();


void create()
{
	set_name("�㷷��", ({"yu fanzi"}));
	set("long", "����һλ�����⻬���㷷�ӡ�");
	set("gender","����");


        set("age",35);
        set("con",20);
        set("str",20);
set("no_get",1);

        set("combat_exp",3000);

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