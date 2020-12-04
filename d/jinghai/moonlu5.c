// Room: /d/jinghai/moonlu5.c
#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "С��ͷ");
	set("long", @LONG
վ�ں��ߣ���ᷢ�������и����塣�����ɽ�³ʰ�����һ
ֱ���ӵ���������ĺ�ˮ�峺���ף���ɫ���˻������ų����
�����ߵ���ʯ��һ��ľ���ɵ���ͷ̤�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"moonlu4",
]));

	set_boat_file(__DIR__"duz_m");
	set_max_passenger(10);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫȥ��½������\n");

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
