#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// 迷宫进入要求最低等级。

        set_lonely_create(1);


	//迷宫房间里的怪物。
        set_maze_npcs(__DIR__"npc/0009/man3");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0009/zhuangzhu3");

	//迷宫的单边长
        set_maze_long(6); 

        set_npcs_rate(66);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"vrm09out1");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm09out2");

	//入口房间短描述
	set_entry_short("采石矶");

	//入口房间描述
	set_entry_desc(@LONG
采石矶，是长江下游著名的风景古迹，其周十五里，高百仞，西接大
江，三面俱绕清溪，在历史上向来是兵家必争之地，隋初朝擒虎伐陈夜袭
采石矶，明初常遇春也曾以两下采石，大破元军。
LONG
);

	//BOSS房间短描述
	set_exit_short("采石矶");

	//BOSS房间描述
	set_exit_desc(HIB"
采石矶，是长江下游著名的风景古迹，其周十五里，高百仞，西接大
江，三面俱绕清溪，在历史上向来是兵家必争之地，隋初朝擒虎伐陈夜袭
采石矶，明初常遇春也曾以两下采石，大破元军。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("采石矶");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
采石矶，是长江下游著名的风景古迹，其周十五里，高百仞，西接大
江，三面俱绕清溪，在历史上向来是兵家必争之地，隋初朝擒虎伐陈夜袭
采石矶，明初常遇春也曾以两下采石，大破元军。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
