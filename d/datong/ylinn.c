// Room: /open/dt/ylinn.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
������ջ�ǳ�����е����ҿ�ջ֮һ����Ϊ�������ţ�����
���۷ǳ����ˣ��������������������Ŀ�����Ǻ͹��������Ǿ�
����˵ĵط�����Ȼ����ķ�ɳ�ܴ󣬿�������ȴ��ɨ�ĸɸɾ�
����һ�����źں�����Բ���ĵ�С���������������æ���š�ǽ
�Ϲ���һ������(paizi)��
LONG
	);

	
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥�Ͽͷ���ÿ��һ��������\n",
	]));

	set("valid_startroom", 1);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu3",
  "up" : __DIR__"ylinn2",
]));

	set("objects",([
	__DIR__"npc/waiter" : 1,
]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ������ô�ţ����ס����\n");
	if( me->query_temp("on_rided") && dir == "up")  // �ж��Ƿ���������
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ���ô��ס��������أ�
���˻���ΪС���ź����أ��Ժ�˭��������\n");

	return ::valid_leave(me, dir);
}
