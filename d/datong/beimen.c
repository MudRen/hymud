// Room: /open/dt/beimen.c

inherit ROOM;

void create()
{
	set("short", "��ͬ������");
	set("long", @LONG
��ͬ�ǹ�����ӽ������һ�����У������Ӵ�ͬ���ı���
������ֻ��ٷ��Ĺ��򣬱㵽���������������Ź��ˡ��߲��ı�
��¥���������ڷ�ɳ����Ϯ�£��Ե�ʮ�ֲ�����׳������ÿ�쿪
�ŵ�ʱ��̣ܶ���Ҫ����Ϊ�˷�ֹ����Ļ�ɳ���޼ɵ��ĳ�ˢ��
�еĽֵ���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jinyangjie1",
  "north" : __DIR__"out_datong_n",
]));
/*
// gate settings
// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["north" : __DIR__"out_datong_n"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
��ͬ�ǹ�����ӽ������һ�����У������Ӵ�ͬ���ı���
������ֻ��ٷ��Ĺ��򣬱㵽���������������Ź��ˡ�������ɫ
���������Ѿ������ˡ�
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","��ͬ������" );

// end.
*/
	set("outdoors","datong");

	set("objects",([
	__DIR__"npc/guard" : 3,
]));

	setup();
	replace_program(ROOM);
}
