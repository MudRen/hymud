// Room: /d/jinghai/jhd25.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @LONG
���趣�����У����߽��˾������ĳ�����ֻ����ʮλ��ʦ��
������æµ�ţ�������߲�ˮ�����ǵ��ϲ��ľӶ࣬��ʱҲ��½
����ȥ�ɹ�һЩ����ȱ������Ʒ������ĳ�ʦ���ռ��ѣ�������
�����ɳ�ʦ���˵�����������һ������Ҫ��ˮ��������Ҩ��ˮ
�����ˮ(drink)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jhd23",
]));

        set("objects", ([
            __DIR__"obj/mifan"       : 10,
]));

	setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();

        if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");

        message_vision("$N��ˮ�ױ��ñ���Ҩ��ˮ���˼��ڡ�\n", me);
        me->add("water", 20);
        return 1;
}
