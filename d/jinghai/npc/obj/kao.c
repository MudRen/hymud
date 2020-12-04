// kao.c

inherit ITEM;

void create()
{
        set_name("������", ({ "liao kao","kao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("material", "iron");
		set("long","����һ��ר��������(suo)���˵�������");
        }
        setup();
}

void init()
{
	add_action("do_kao","suo");
}

int do_kao(string arg)
{
	object who, me = this_player();

	if(!me || !arg)
		return 0;
	if(me->is_fighting())
		return notify_fail("������ս�����ڲ����������ˡ�\n");

	if( !objectp(who = present(arg,environment(me))) || !who->is_character() )
		return notify_fail("��Ҫ����������˭��\n");

	if( !who->is_fanren() )
		return notify_fail("������ֻ�����������ˡ�\n");

	if( objectp(who->query_master()) )
		return notify_fail(who->name()+"�Ѿ����������ˡ�\n");

	if(living(who))
	{
		message_vision("$N����$n����������ȥҲ�Ǹ���������ͺ�����������\n",who,me);
		who->kill_ob(me);
		me->fight_ob(who);
		return 1;
	}

	else
	{
		message_vision("$N�ó���������ॡ�һ����$n����������\n",me,who);
		who->set_master(me);
		this_object()->move(who);
		return 1;
	}
}
