// xiaohe1.c

inherit ROOM;

void create()
{
        set("short","С�Ӱ���");
        set("long",@LONG                                   
��ǰ�����һ�����ɿ��С�ӡ�ͭɽ��֮���ԱȽϸ��ľ�
����Ϊ��������С�ӵ�ˮ���Թ��ũ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "southup" : __DIR__"tulu2",
        ]) );

        set("outdoors", "huayin");
        setup();
}

void init()
{
	add_action("do_fill","fill");
}

int do_fill(string arg)
{
	object me = this_player(),ob;

	if(!objectp(ob = present("shui piao",me)) || !ob->id(arg))
                return notify_fail("��Ҫ��ʲô��ˮ��\n");

	if(ob->is_full())
                return notify_fail("ˮư�Ѿ��������ˡ�\n");

	message_vision("$N����ˮư��С����Ҩ��һư��ˮ��\n",me);

	ob->do_fill();
        return 1;
}
