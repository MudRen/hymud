#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "openbeg");
}

void create()
{
	set_name(HIY"���ְ�"NOR, ({"nb bao", "nbbao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ְ����ƺ����Դ�(openbeg)��\n");

set("no_put", 1);
set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");




message_vision(HIY "$N�������ְ�!����˺ܶ౦��!\n" NOR, me);





corpse=new("/clone/money/gold");
corpse->set_amount(10000);
corpse->move(me);
tell_object(me,HIY"���ҵ���һ�����ƽ�!\n"+NOR);

corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);

tell_object(me,HIY"���ҵ���ʮ��������!\n"+NOR);

        if (me->query("per") < 25)
        {
                tell_object(me, HIY "������ƺ��Լ�����ò�����˱仯��\n" NOR);
                me->set("per", 25);
        }


        if (me->query("kar") < 25)
        {
                tell_object(me, HIY "������ƺ��Լ��ĸ�Ե�����˱仯��\n" NOR);
                me->set("kar", 25);
        }

	me->add("mpgx", 8);
	destruct(this_object());
	return 1;
}