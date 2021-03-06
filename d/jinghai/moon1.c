// Room: /d/jinghai/moon1.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "明月弯码头");
	set("long", @LONG
站在海边，你会发现这里有个港湾。西北方的山崖呈半月形
一直伸延到这里。蓝蓝的海水清澈见底，白色的浪花翻滚着冲击
着海岸边的岩石。这里就是有名的明月湾了。一条木板搭成的码
头踏板伸向海里。傍边停靠着两只小木船。一条小路通向西北方
向的山崖。小路旁有一间简陋的小茅屋在风中摇晃着。
LONG
	);
	set("outdoors", "jinghai");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/boy1" : 1,
  __DIR__"npc/fisher1" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"moon37",
  "west" : __DIR__"moon22",
  "northwest" : __DIR__"moon2",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(10);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要去大陆！！”\n");

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
