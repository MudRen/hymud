// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "�����" NOR, ({ "yg wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵ����������˵���˿��Ըı���������\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
int max;
        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        max = me->query_skill("force")*10 + me->query("combat_exp")/1000;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query_condition("killer"))
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        } else
{
if (random(12)==1)
{
me->delete("szj/failed");
message_vision(HIG"$N�ٴλ���ƽ����վ��Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==2)
{
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N�ٴλ�ý�����ϲ�Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==3)
{
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N�ٴλ�ý�����²�Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==4)
{
me->delete("zhou/jieyi");
me->delete("zhou/fail");
me->delete("zhou/failed");
message_vision(HIG"$N�ٴλ�ý�˫�ֻ����Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==5)
{
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N�ٴλ�ý������Ĺ�Ļ��ᣡ\n"NOR, this_player());
}	
me->clear_condition();
me->set("betrayer",0);
message_vision(HIG"$N����ʦ�������㣡\n"NOR, this_player());

}
        destruct(this_object());
	return 1;
}
