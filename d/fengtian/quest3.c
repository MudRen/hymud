// Room: /d/fengtian/quest3.c

inherit ROOM;

private int ok;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ���������С�����������ϲ���һֻ��ѡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"quest2",
  "north" : __DIR__"quest4",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north")
	{
		if(!ok)
			return notify_fail("ͻȻ�����Ϸɳ����ѷɵ������������ס�����ȥ·��\n");
	}

	call_out("do_refresh",1);
	return ::valid_leave(me,dir);
}

private void do_refresh()
{
	ok = 0;
	set("exits/out",__DIR__"quest2");
}

void do_check()
{
	call_out("do_count",1);
}

private void do_count()
{
	object *obs;

	obs = all_inventory(this_object());
	foreach(object ob in obs)
		if(ob->is_rain_quest())
			return;

	ok = 1;
}
