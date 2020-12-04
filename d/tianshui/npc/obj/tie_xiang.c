// tie_xiang.c
inherit ITEM;

private int lock = 1;
void create()
{
        set_name("����", ({ "tie xiang" , "xiang"}) );
        set_weight(50000);
        set_max_encumbrance(8000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "ֻ");
		set("long", "����һֻ��Ƥ�䣬�м����һ�Ѵ���(lock)���������ŷ�����������д�ţ������⡣\n");
		set("value", 1);
		set("no_get",1);
		set("no_drop",1);
        }
}

int is_container() { return 1; }

void init()
{
	add_action("do_pi",({"pi","za"}));
	add_action("do_get","get");
	add_action("do_put","put");
}

int do_get(string arg)
{
	string what;
	if(!arg) return 0;
	if(sscanf(arg, "%s from %s", arg, what)==2)
	{
		if(id(what))
		{
			if(lock)
			{
			write("���䱻�����ˡ�\n");
			return 1;
			}
			else if(arg == "all" || arg == "qsword")
			{
			write("������䣬");
			return 0;
			}
		return 0;
		}
	return 0;
	}
	else return 0;
}

int do_put(string arg)
{
	string what;
	if(!arg) return 0;
	if(sscanf(arg, "%s in %s", arg, what)==2)
	{
		if(id(what))
		{
			if(lock)
			{
			write("���䱻�����ˡ�\n");
			return 1;
			}
		return 0;
		}
	return 0;
	}
	else return 0;
}

int do_pi(string arg)
{
	object weapon,me = this_player();
	if(!arg || arg == "")
		return notify_fail("��Ҫ��ʲô��\n");
	if(arg != "lock" && arg != "����" && arg != "��")
		return notify_fail("��Ҫ��ʲô��\n");
	if(!lock)
		return notify_fail("�����Ѿ����ҿ��ˡ�\n");

	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����Ҫ�ҿ����������ǲ��С�\n");

	message_vision("$N�Ӷ����е�"+weapon->query("name")+"�������ȥ��\n",me);
	if(me->query("force") < 100 ){
	message_vision("���������˿û����\n",me);
	return 1;
	}
	message_vision("��������ॡ�һ�����ҿ��ˡ�\n",me);
	lock = 0;
	me->add("force",-100);
	set("long", "����һֻ��Ƥ�䣬��������Ѿ���֪��˭�ҿ��ˡ�\n");
	return 1;
}
