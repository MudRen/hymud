// #pragma save_binary
//old_sword.c

#include <ansi.h>

inherit ITEM;
//inherit F_UNIQUE;

void create()
{
    set_name( "�򼲷羢����", ({ "book" }) );
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
ֱ���������紵����ֹ�������п��������Ʈ������˹�˾�����

						   ������
LONG
		);
		set("value", 100);
        set("material", "paper");
		set("skill", ([
        "name" :        "parry",
            "exp_required" :  20000,
            "jing_cost" : 30,
                    "difficulty" : 15,
            "max_skill" : 50
		]) );
        set("replica_ob", __DIR__"cola");
	}
}
