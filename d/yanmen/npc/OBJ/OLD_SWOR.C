#pragma save_binary
//old_sword.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIG "�� ��" NOR, ({ "old sword", "sword"}));
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
������ˮ���羢��֮�������ڷ棬���������˹���ڼ���������
˲�����������֣�����磬������ɽ���������
LONG
		);
		set("value", 100);
		set("material", "ͭ");
		set("skill", ([
		"name" :		"sword",
			"exp_required" :  2500,
            "jing_cost" : 20,
                    "difficulty" : 15,
            "max_skill" : 50
		]) );
        set("replica_ob", __DIR__"cola");
	}
}
		
