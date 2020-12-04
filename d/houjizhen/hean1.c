// hean.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ӱ�");
        set("long", @LONG
�����ǹ�ͺͺ�ĺӰ����������(river)���������¶����ҷأ���
��һ�����ѵ�С·�����˶���ʯ(shi)������Χ��ȥ��������һ������
���ѳɵĳ�ǽ���ܶദ����̮����
LONG);

        set("outdoors", "houjizhen");

        set("exits", ([
		"south" : __DIR__"muqiao",
		"north" : __DIR__"miao",
        ]));

	set("item_desc", ([
		"river" : "С�Ӻܿ���ˮ��������ԼԼ��ʲô�������㿴���塣\n",
		"shi":"һ�����СС�Ķ���ʯ�����̲�ס���(jian)����������\n",
	]));

        setup();
//	replace_program(ROOM);
}

void init()
{
      add_action("do_jump", "jump");
      add_action("do_jian", "jian");
}

int do_jump(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "river")
                return notify_fail("��Ҫ��������\n");
        message_vision(HIY"$N��ͨһ����ӿ�������˱���ĺ�����\n"NOR, me);
        me->set("water", me->max_water_capacity()+ 100);
        me->move(__DIR__"hemian");
        tell_room(environment(me), me->name() + "�Ӱ�������������\n", ({ me }));
        return 1;
}

int do_jian(string arg)
{
        object me,ob;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "shi")
                return notify_fail("��Ҫ����ʲô��\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 92) 
                return notify_fail("��ĸ��ɲ���̫��Ķ����ˣ�\n");
        switch  (random(3)){
        case 0: ob = new(__DIR__"obj/shi1"); break;
        case 1: ob = new(__DIR__"obj/shi2"); break;
        case 2: ob = new(__DIR__"obj/shi3"); break;
        }
        ob->move(me);
        message_vision("$N���������ӵ��ϼ�����һ��"+ob->name()+"��\n",me);
        return 1;
}

int get_object(object ob)
{
       return userp(ob);
}