// zhulin6.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
�ߵ������ͻȻ�о���ǰһ����һ��С·�����������ǰ��
���ͷ�Զ�ʱ�ָ������ѣ�һ��С������ԼԼ����ǰ�档
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"south" :  __DIR__"zhulin2",
		"north" :  __DIR__"xiaolu1",
	]));

	setup();
	replace_program(ROOM);
}
