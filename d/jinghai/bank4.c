// Room: /d/jinghai/bank4.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"



inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "С��ͷ");
	set("long", @LONG
������һ������ʯ�����ɵ�С��ͷ����ͷ�߼�����Ҫ������
������Ⱥ����ֻ�м���С����ͣ���ڰ��ߣ�����һ�ѷ��������
ӿȥ��������һ�ߴ����ȳ�һ��ƴ����ά��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bank3",
]));

	set_boat_file(__DIR__"duz_m");
	set_max_passenger(10);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫȥ���µ�������\n");

	set("outdoors", "jinghai");
	setup();
}

// �����������ʹ�������˲���Ǯ
protected int valid_passenger(object who)
{
	if(who->query("class") == "jinghai")
	{
		who->set_temp("payed_duchuan", 1);
		return 1;
	}

	else return ::valid_passenger(who);
}
