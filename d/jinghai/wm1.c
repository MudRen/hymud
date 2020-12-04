// Room: /d/jinghai/wm1.c
#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "����������ͷ");
	set("long", @LONG
�˴�����һ����ͷ�������ˮ��ǳ����������ͷ�������н�
��ĵط�бб������һ��ջ�ţ�ջ�ž�ͷ�������ͣ����һ��С
������ͷ�ߵĸ��������϶���һ��ľ�壬����д�ţ���������ר
����ͷ����
LONG
	);

	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"wm11",
]));
	set("item_desc", ([
		"sea" : "��������ͣ��һ��ս����Ҳ��(yell)һ�����Ҿ���������\n",
]));

	set_boat_file(__DIR__"dum_ws");
	set_max_passenger(6);
	setup();
	//replace_program(ROOM);
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
