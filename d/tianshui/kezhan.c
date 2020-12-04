// Room: /d/tianshui/kezhan.c

inherit ROOM;

void create()
{
	set("short", "��ˮ��ջ");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��
������ţ���С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ�
�͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣ǽ�Ϲ�
��һ������(paizi)��
LONG
	);

	
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥�Ͽͷ���ÿ�����������\n",
	]));

	set("objects", ([
		__DIR__"npc/waiter" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"eroad1",
		"up" : __DIR__"kezhan2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
	if( me->query_temp("on_rided") && dir == "up")  // �ж��Ƿ���������
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
