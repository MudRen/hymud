// Room: /open/dt/nanmen.c

inherit ROOM;

void create()
{
	set("short", "��ͬ������");
	set("long", @LONG
�ߴ����ϵ�����¥�����������ǰ��һ�ӹٱ���������Ĳ�
����������߹������Ǿ�����������Ĵ���������µľ�����
������������סһ������������ʲô���������ĳ�ǽ�����ż�
�Ÿ�ʾ�������ǹٸ����ڰ참��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lukou",
  "south" : __DIR__"out_datong_s",
]));
/*
// gate settings
// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["south" : __DIR__"out_datong_s"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
������Ǹߴ����ϵĴ�ͬ�����ţ�������ɫ���������Ѿ�
�����ˡ�
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","��ͬ������" );

// end.
*/
	set("outdoors","datong");

	set("objects",([
	__DIR__"npc/guard" : 1,
]));

	setup();
	replace_program(ROOM);
}
