// guozi.c

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("����", ({"guozi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ź���С���ӣ���֪���ܲ��ܳԡ�\n");
        }
        setup();
}

int do_eat(string arg)
{
	int sen,efsen,max;

	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	sen = me->query("sen");
	efsen = me->query("eff_sen");
	max = me->query("max_sen");

	if( sen >= max && efsen >= max)
	{
		message_vision("$N��С���ӳ�����ȥ��ʲô�о�Ҳû�С�\n", me);
		destruct(this_object());
		return 1;
	}

	if(efsen < max)
		me->add("eff_sen",(efsen+20)>max? max-efsen : 20);
	if(sen < max)
		me->add("sen",(sen+20)>max? max-sen : 20);

	message_vision("$N��С���ӳ�����ȥ���о�����ö��ˡ�\n", me);
	destruct(this_object());
	return 1;
}