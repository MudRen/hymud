#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"����С��"NOR, ({ "newspaper" }) );
    set_weight(1);
           set("base_value", 99);
           set("value", 99);
            set("unit", "��");
            set("material", "paper");
            set("long", "�³��Ľ���С���������˸��ֽ�����Ϣ��\n");
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
           set("base_value", 99);
           set("value", 99);
            set("unit", "��");
            set("material", "paper");
            set("long", "�³��Ľ���С���������˸��ֽ�����Ϣ��\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "kan");
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        message_vision( "$N�ó��˽���С��������һ�£�����������Ľ����������˽�!\n", me);
	me->set_temp("istask",1);
	destruct(this_object());
	return 1;
}