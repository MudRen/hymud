// Room: /d/datong/out_datong_n.c

inherit ROOM;

void create()
{
	set("short", "��ͬ��������");
	set("long", @LONG
������Ǵ�ͬ���ı������ˣ��߲��ı���¥���������ڷ�ɳ
����Ϯ�£��Ե�ʮ�ֲ�����׳������ÿ�쿪�ŵ�ʱ��̣ܶ���Ҫ
����Ϊ�˷�ֹ����Ļ�ɳ���޼ɵ��ĳ�ˢ���еĽֵ���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beimen",
   "north" : "/d/taiyuan/sroad1",
]));
/*
// gate settings
// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["south" : __DIR__"beimen"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
������Ǵ�ͬ���ı������ˣ��߲��ı���¥���������ڷ�ɳ
����Ϯ�£��Ե�ʮ�ֲ�����׳��������ɫ���������Ѿ������ˡ�
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","��ͬ������" );

// end.
*/
	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
