inherit ROOM;

void create()
{
        set("short", "ɽׯ����");
        set("long", @LONG
�������ɽׯ����.
LONG
);

        set("exits", ([
                "north"  : __DIR__"taohuayuan",
]) );
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


