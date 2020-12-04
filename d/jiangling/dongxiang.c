//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "���᷿");
	set ("long", @LONG
����֪�����˺ͼҾ���ӵĴ���������һ�ŵ񻨴�ľ�������϶ѵ�
�Ž������廨��ͷ��������һ�����ȣ�������һ�����ԣ���Լ��������
�������㡣������һ����(men)��
LONG);
	set("exits", ([
		"north" : __DIR__"zoulang",
		"west"  : __DIR__"huapu",
	]));
		set("objects", ([
		__DIR__"npc/gaoshou" : 1,
	]));
	
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("sleep_room", 1); 
	set("coor/x", -1480);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}

void init()
{
        add_action("do_kai", "open");
        add_action("do_kai", "kai");
        if (present("gao shou", environment(this_player())))
                delete("exits/north");
}
int do_kai(string arg)
{
        object ob;
        if (query("exits/north"))
                return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
        if (!arg || (arg != "men" && arg != "north"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!(ob = present("tong yaoshi", this_player())))
                return notify_fail("����Կ��������ת�˼���,������ôҲ�򲻿���\n");
        set("exits/north", __DIR__"zoulang");
        message_vision("$N����ͭԿ�״򿪷��ţ�����Կ��ȴ���ˡ�\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("gao shou", environment(me))) && 
                (dir == "north"))
                return notify_fail("�������ֵ�ס���㣺��������լ��ʲô? \n");
        return ::valid_leave(me, dir);
}
