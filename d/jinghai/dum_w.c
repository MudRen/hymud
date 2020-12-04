// Room: /d/path2/duchuan.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"


inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "渡船");
	set("long", @LONG
这是一条很小的渡船。木头结构，可以容纳五六个人的样子
。站在上面遥遥晃晃，让人感觉很不塌实。
LONG
	);
	
	set("no_clean_up",1);
	set("invalid_fuji", 1);

	set_boat_master(__DIR__"npc/chuanjia");
	set_boat_bank1(__DIR__"moon38");
	set_boat_bank2(__DIR__"wm12");
	set_bank1_desc("明月岛");
	set_bank2_desc("无名岛");
	set_cross_msg("渡海");

	setup();
}
