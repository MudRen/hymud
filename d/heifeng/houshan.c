// Room: /d/heifeng/houshan.c

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�����Ǻڷ�ɽ�ĺ�ɽ�������Ƕ��͵�ɽ�ڣ������濴ȥ����
�����£�����ǿ����ɽ�磬���˾���ҡҡ��׹�������ӻ��ǸϽ�
�뿪����Ϊ�á�
LONG
	);

	set("outdoors","heifeng");

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaolu4",
]));

	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if(!arg || arg != "up")
		return 0;

	if(me->query_skill("dodge") < 150)
		return notify_fail("��˳��ɽ�ڷ����������˼��£�����ʵ���޴����֣�������������\n");

	write("������ɽ�ڷ�����ɽ��ȥ��\n");
	me->start_busy(2);
	call_out("do_up",2,me);
	return 1;
}

void do_up(object me)
{
	tell_object(me,"����������������\n");
	me->receive_damage("qi",60);
	me->move(__DIR__"shanding");
}
