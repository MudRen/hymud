// Room: /d/jinghai/zhuque3.c


#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
������һ������ʯ�����ɵ�С��ͷ����ͷ�߼�����Ҫ������
������Ⱥ����ֻ�м���С����ͣ���ڰ��ߣ�����һ�ѷ��������
ӿȥ��������һ�ߴ����ȳ�һ��ƴ����ά��������һ����վ
�ڰ������Ѽ�Ӱ����Ⱥ����ɢ�����������Ǹ����µģ�Ҫ�ϴ�
�ÿ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"zhuque2",
  "west" : __DIR__"zhuque12",
]));
        set("objects",([
        __DIR__"npc/wei" : 1,
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(10);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫȥ���µ�������\n");

	set("outdoors","jinghai");
	setup();
}

