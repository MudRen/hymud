#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM ); set("no_clean_up",1);
        set_lonely_create(1);

	//迷宫的单边长
        set_maze_long(8); 

        set_npcs_rate(66);
        



        set_maze_boxs(2);
        set_maze_traps(6); 


	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/0009/beast");



	//迷宫房间里的BOSS。
	set_exit_npcs(__DIR__"npc/0009/leishen");



	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room("/d/city/wumiao");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room("/d/city/wumiao");

	//入口房间短描述
	set_entry_short("九天雷云");

	//入口房间描述
	set_entry_desc(HIC"
	你站在云端，向四周望去，四面是一望无际的云海，头顶是碧蓝的天空。
向下望去，只见一片青翠的绿色，偶尔有一些细细的白线贯穿其中。一只小黄莺
悄悄地从云丛中探出头来，很惊讶地看着你。
"NOR);

	//BOSS房间短描述
	set_exit_short("九天雷云");

	//BOSS房间描述
	set_exit_desc(HIC"
	你站在云端，向四周望去，四面是一望无际的云海，头顶是碧蓝的天空。
向下望去，只见一片青翠的绿色，偶尔有一些细细的白线贯穿其中。一只小黄莺
悄悄地从云丛中探出头来，很惊讶地看着你。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("九天雷云");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(HIC"
	你站在云端，向四周望去，四面是一望无际的云海，头顶是碧蓝的天空。
向下望去，只见一片青翠的绿色，偶尔有一些细细的白线贯穿其中。一只小黄莺
悄悄地从云丛中探出头来，很惊讶地看着你。
"NOR);
        // 迷宫摧毁时间
        set_remove_time(3000); 
	// 迷宫房间是否为户外房间？
	//set_outdoors(1);
}
