// miao.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�㲽�������һ�۱㿴��һ�����������ᵹ��һ�ߣ������ܵ�
ǽ�ǲ�����֩�����������м�ֻ֩�����ȴ��������Զ���������������
������һ���񰸣����浽�������˻ҳ���ǽ���м����Ѿ���������ֻ��
ѻͣ�����棬һ�߷���"����"�Ľ�����
LONG );
	
	set("exits", ([
		"south"  : __DIR__"hean1",
	]));

	set("objects", ([
		__DIR__"npc/wuya" : 1,
	]));

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_find","find");
}

int do_find()
{
       	object me;
        me = this_player();

	if (this_player()->query_temp("ganjiang/heshang"))
 	{   
	message_vision("$N���˰��죬ͻȻ������������һ���ص�����������˽�ȥ��\n", me);
     	me->move(__DIR__"midao");
	me->delete_temp("ganjiang/heshang",1);
     	return 1;
 	}
	return notify_fail("�����˰��죬Ҳû���ҵ�ʲô���õĶ����� \n");
}


