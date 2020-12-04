// Room: /d/jinghai/wm16.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ɨ�ĺܸɾ����м������Ŵ����ӣ����������һ��
��ʮ���ˡ�������ི�֪����ʲô������ð����������������
�������Ρ�����Ѿ��������ʰ�߲ˡ�һ��С�������ػص��ܸ���
ͣ������ڴ����֡���Ҫ�ǿ��˿�������Ҩ(drink)ˮ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"wm14",
]));
        set("objects", ([
            __DIR__"obj/mifan"       : 3,
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

