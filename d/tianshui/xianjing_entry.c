// Room: /d/tianshui/xianjing_entry.c

inherit ROOM;

void create()
{
	set("short", "ɽ������");
	set("long", @LONG
����������ɽ���ĳ����ˣ�ǰ��͸����һ�����⣬�˱Ƕ�
�������󻨲ݵ���������ֻ��һ��ʲô���ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xianjing",
  "south" : __DIR__"hole",
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north" || dir == "n")
	{
	if(me->query("bellicosity") > 0)
		return notify_fail("ֻ���õ�һ����͵�����ס���㡣\n");
	return ::valid_leave(me,dir);
	}
	return ::valid_leave(me,dir);
}