// kedian.c
// by dicky

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","�м�͵�");
	set("long", 
"����һ�ҿ�ջ����Ȼ���Ǻ��Ψһһ�ҿ�ջ�����������Եø��������
��ֻ�м�λ�����������������ͷ���žƣ����Ǽ��������ֻ����΢��̧��ͷ
�����������۹�ɨ������һ�£����ֵ���ͷȥ�����Լ��ľƣ��·����Ѿ�����
���ڡ���С��û����Ԥ�ϵ��������飬��ֻ��ԶԶ��վ�ڹ�̨ǰ�����۾�ϸϸ
�������㣬����Ҳ������������ת�������������������Լ�����ָ����ջ��
���ǽ�Ϲ���һ����Ŀ������(paizi)��\n");
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
	        "south" : __DIR__ "shilu1.c",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��ô�ţ����ס����\n");
	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");
	return ::valid_leave(me, dir);
}
