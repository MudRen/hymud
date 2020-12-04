// /d/heifeng/up.c

inherit ROOM;
#include "up.h"

void init()
{
	add_action("do_pick","cai");
}

int do_pick(string arg)
{
	mapping quest;
	object me = this_player(),ob;

	if(arg != "��֥" && arg != "lingzhi")
		return notify_fail("��Ҫ��ʲô��\n");

	if(mapp(quest = me->query("quest/shaolin_quest"))
	&& quest["name"] == "����֥"
	&& undefinedp(quest["have_get"]))
	{
		if(sum <= 0)
		{
			message_vision("$NС�������Ų�������±ߣ�һ����ֻץ����һ����ݣ����������˵��¡�\n",me);
			return 1;
		}

		if(undefinedp(quest["killed_wugong"]))
		{
			message_vision("$NС�������Ų�������±ߣ�ͻȻ�ܳ���һ������򼡣\n",me);
			ob = new(__DIR__"npc/wugong");
			ob->move(this_object());
			ob->kill_ob(me);
			me->kill_ob(ob);
			return 1;
		}

		message_vision("$NС�������Ų�������±ߣ�������һ������֥��\n",me);
		ob = new(__DIR__"obj/lingzhi");
		if(!ob->move(me))
			ob->move(this_object());
		me->set("quest/shaolin_quest/have_get",1);

		sum--;
		if(!sum && (find_call_out("do_add") == -1))
			call_out("do_add",180);
		return 1;
	}
	message_vision("$NС�������Ų�������±ߣ�һ����ֻץ����һ����ݣ����������˵��¡�\n",me);
	return 1;
}

private void do_add()
{
	if(sum >= max)
		return;
	sum++;
	if(sum >= max)
		return;
	call_out("do_add",180);
}
