// Room: /d/jinghai/duz_m.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"



inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "海船");
	set("long", @LONG
这是一艘不小的海船，船头一面旗子上绣着“靖海派”。
LONG
	);

	set_boat_master(__DIR__"npc/sy_zm");
	set_boat_bank1(__DIR__"bank4");
	set_boat_bank2(__DIR__"moonlu5");
	set_bank1_desc("大陆");
	set_bank2_desc("明月岛");
	set_cross_msg("渡海");

	setup();
}
