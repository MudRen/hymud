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
                __DIR__"npc/lev1": random(2),
                __DIR__"npc/lev2": random(2),  
                __DIR__"npc/lev3": random(2), 
                __DIR__"npc/lev4": random(2), 
                __DIR__"npc/lev5": !random(5), 
                __DIR__"npc/lev6": !random(6), 
                __DIR__"npc/player": !random(8), 
        ]) );  

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/boss1");

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
	set_link_entry_room(__DIR__"out");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"out2"); 

	//入口房间短描述
	set_entry_short(YEL"永恒的沙漠"NOR);

	//入口房间描述
	set_entry_desc(YEL @LONG
  由于火元素的影响，这附近全是砂漠，这是一片一望
无际的大沙漠。你一进来就迷失了方向。看来要走出这
块沙漠并非易事。
LONG
);

	//BOSS房间短描述
	set_exit_short(YEL"永恒的沙漠的尽头"NOR);

	//BOSS房间描述
	set_exit_desc(YEL"
  由于火元素的影响，这附近全是砂漠，这是一片一望
无际的大沙漠。你一进来就迷失了方向。看来要走出这
块沙漠并非易事。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short(YEL"永恒的沙漠"NOR);

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(YEL @LONG
  由于火元素的影响，这附近全是砂漠，这是一片一望
无际的大沙漠。你一进来就迷失了方向。看来要走出这
块沙漠并非易事。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}