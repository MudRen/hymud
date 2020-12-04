// Room: /d/jinghai/jhd10.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ��԰");
	set("long", @LONG
�˱ǵ��������㾫��һˬ������Ŀ�Ĺˣ����۴����ǲ�֪��
�Ĵش��ʻ����컨��֦����֮�䣬����С·���򻨴��������
�Ǿ�������ǰԺ�Ļ�԰������Ϊ���������߱�����飬�������
԰ɷ�Ƿ���һ�����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"jhd13",
  "northwest" : __DIR__"jhd11",
  "southwest" : __DIR__"jhd12",
  "east" : __DIR__"jhd9",
  "south" : __DIR__"jhd14",
]));
        set("outdoors","jinghai");
	set("valid_startroom", 1);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north" && me->query("class") != "jinghai" && !wizardp(me))
		return notify_fail("ͻȻ������ܳ���������ס��˵�����������أ����˲������ڣ�\n");
	return ::valid_leave(me,dir);
}
