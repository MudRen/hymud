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
        set_maze_npcs( ([
                __DIR__"npc/lev4": random(2), 
                __DIR__"npc/lev5": random(2), 
                __DIR__"npc/lev6": !random(3), 
                __DIR__"npc/lev7": !random(3), 
                __DIR__"npc/lev8": !random(4), 
                __DIR__"npc/lev9": !random(5), 
                __DIR__"npc/leva": !random(5),
                __DIR__"npc/levb": !random(5),
                __DIR__"npc/levc": !random(5),
                __DIR__"npc/player": !random(6), 
        ]) );  

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/boss");

	//迷宫的单边长
        set_maze_long(6); 

        set_npcs_rate(88);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"out3");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room("/d/city/wumiao"); 

	//入口房间短描述
	set_entry_short(HIM"不归的迷宫"NOR);

	//入口房间描述
	set_entry_desc(HIM @LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。城市大道在
这里被瓦砾堆给堵死了。这片残破萧条的景像和城门附近雄伟瑰丽的建筑
真是个极为讽刺的对比，你的直觉告诉你还是往回走才能找到出路。
LONG
);

	//BOSS房间短描述
	set_exit_short(HIM"不归的迷宫"NOR);

	//BOSS房间描述
	set_exit_desc(HIM @LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。城市大道在
这里被瓦砾堆给堵死了。这片残破萧条的景像和城门附近雄伟瑰丽的建筑
真是个极为讽刺的对比，你的直觉告诉你还是往回走才能找到出路。
LONG);

	//迷宫房间的短描述
	set_maze_room_short(HIM"不归的迷宫的尽头"NOR);

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(HIM @LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。城市大道在
这里被瓦砾堆给堵死了。这片残破萧条的景像和城门附近雄伟瑰丽的建筑
真是个极为讽刺的对比，你的直觉告诉你还是往回走才能找到出路。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}