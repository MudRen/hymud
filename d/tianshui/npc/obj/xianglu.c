// design by ���ֺ�(find) . all right reserved.

// xianglu.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��¯", ({ "xiang lu", "lu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����С����¯��������������Ů�ǲ���(cha)��Ը��\n");
                set("value", 1000);
                set("material", "gold");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();
}

void init()
{
	add_action("do_cha","cha");
}

int do_cha(string arg)
{
	object me,have_xiang;
	me = this_player();
	if( !arg || arg == "")
		return notify_fail("��Ҫ��ʲô����¯�\n");
	if( arg != "xiang" )
		return notify_fail("��Ҫ��ʲô����¯�\n");
	have_xiang = present("xiang", me);
	if( !have_xiang)
		return notify_fail("������û�и��㡣\n");
	if( !have_xiang->query("fire"))
		return notify_fail("���㻹û�е�ȼ�أ���ô��������\n");
	message_vision("$N�Ѹ�������¯�����˼��ݡ�$N�о�������ƽ�����ˡ�\n",me);
	destruct(have_xiang);
	if( (me->query("bellicosity") > 0))
	me->add("bellicosity", -(random((int)me->query("kar")) + 50));
	return 1;
}
