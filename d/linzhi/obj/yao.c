#include <ansi.h>

inherit ITEM;
mapping *data=({
(["name":"�˲ι�",	"id":"yaocai",	"mw":-1,	]),
(["name":"ѩ����",	"id":"yaocai",	"mw":-1,	]),
(["name":"��ĸ",	"id":"yaocai",	"mw":-1,	]),
(["name":"�����Ĳ�",	"id":"yaocai",	"mw":-1,	]),				
(["name":"�쾰��",	"id":"yaocai",	"mw":-1,	]),				
(["name":"��ԭ��֥��",	"id":"yaocai",	"mw":-1,	]),				
(["name":"�غ컨",	"id":"yaocai",	"mw":-1,	]),				
(["name":"����",	"id":"yaocai",	"mw":-1,	]),					
(["name":"��������",	"id":"yaocai",	"mw":-1,	]),					
(["name":"������",	"id":"yaocai",	"mw":-1,	]),						
});

void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
	}
	setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	message_vision("$N����һ��" + name() + "��\n", me);

	if ((me->query("eff_jing") / me->query("max_jing")) < 0.9)
	{
		me->receive_curing("jing", (int)me->query("max_jing") / 50);
	}

	if ((me->query("eff_qi") / me->query("max_qi")) < 0.9)
	{
		me->receive_curing("qi", (int)me->query("max_qi") / 50);
	}

	me->start_busy(2);
	destruct(this_object());
	return 1;
}

