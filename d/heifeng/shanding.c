// Room: /d/heifeng/shanding.c

inherit ROOM;

void create()
{
	set("short", "ɽ���յ�");
	set("long", @LONG
�����Ǻڷ�ɽ����壬ɽ�����ǿ�������ܶ��Ƕ�ֱ��ɽ
�ڣ������������£�ż�������һ�۶����˲����������򶫱���
��������Լ�ܹ����������������յ�������һ�����ߵ����Ǵִ�
��ľ�ˣ��������һ��������ߵĺ��죬�������š��ڷ�կ����
������İ��֡�
LONG
	);

	set("outdoors","heifeng");

	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"downlu1",
]));
        set("objects", ([
             "/d/huanghe/yyd/npc/xiaozh" : 1,

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

	if(!arg || arg != "down")
		return 0;

	write("��С�������������ȥ��\n");
	me->start_busy(1);
	me->move(__DIR__"houshan");
	return 1;
}
