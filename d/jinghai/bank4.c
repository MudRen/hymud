// Room: /d/jinghai/bank4.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"



inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "小码头");
	set("long", @LONG
这里是一个用岩石堆砌成的小码头，码头边挤满了要到靖海
岛的人群，但只有几艘小帆船停泊在岸边，人们一窝蜂地往船上
涌去，船夫们一边大声喝斥一边拼命地维持着秩序。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bank3",
]));

	set_boat_file(__DIR__"duz_m");
	set_max_passenger(10);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要去明月岛！！”\n");

	set("outdoors", "jinghai");
	setup();
}

// 重载这个函数使静海的人不收钱
protected int valid_passenger(object who)
{
	if(who->query("class") == "jinghai")
	{
		who->set_temp("payed_duchuan", 1);
		return 1;
	}

	else return ::valid_passenger(who);
}
