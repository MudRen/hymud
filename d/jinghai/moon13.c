// Room: /d/jinghai/moon13.c

inherit ROOM;

void create()
{
	set("short", "ɽկ�﷿");
	set("long", @LONG
�޴��ľ����������������ɼ�ʮ���˵Ļ﷿��������ż�
�ų�������������������˲͵�ĺ��ˮ���������߾Ͳͣ�����
���ǵĻ�ʳ��̫�ã���Ҷ��������Ͱ�Ŵ�׷�����Ҫ�ǿ��˿���
����Ҩ(drink)ˮ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"moon6",
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
