// 

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;
void create()
{
	set("short", "С��ͷ");
	set("long", @LONG
�˴�����һ����ͷ�������ˮ��ǳ����������ͷ�������н�
��ĵط�бб������һ��ջ�ţ�ջ�ž�ͷ�������ͣ����һ��С
������ͷ�ߵĸ��������϶���һ��ľ�壬����д�ţ������µ�ר
����ͷ������Ҫ�ɺ��������Ұ�(yell)��
LONG );

	set("exits", ([
	"west" : __DIR__"moon16",
]));

	set("item_desc", ([
		"sea" : "��������ͣ��һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
]));

	set_boat_file(__DIR__"dum_w");
	set_max_passenger(6);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫȥ������������\n");

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

