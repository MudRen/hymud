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
        set_maze_npcs(__DIR__"npc/0010/man2");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0010/zhuangzhu2");

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
	set_link_entry_room("/d/city/wumiao");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm10out1");

	//入口房间短描述
	set_entry_short("天机石府");

	//入口房间描述
	set_entry_desc(@LONG
昔日一代大侠天机上人隐居处。位于梵净山鹰悉涧中，曲径蜿蜒、
幽深，外人鲜有知之者。罗刹余孽莫洪、单能、卫中三魔发现后，将此据
为藏身之窟。
LONG
);

	//BOSS房间短描述
	set_exit_short("天机石府");

	//BOSS房间描述
	set_exit_desc(HIB"
昔日一代大侠天机上人隐居处。位于梵净山鹰悉涧中，曲径蜿蜒、
幽深，外人鲜有知之者。罗刹余孽莫洪、单能、卫中三魔发现后，将此据
为藏身之窟。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("天机石府");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
昔日一代大侠天机上人隐居处。位于梵净山鹰悉涧中，曲径蜿蜒、
幽深，外人鲜有知之者。罗刹余孽莫洪、单能、卫中三魔发现后，将此据
为藏身之窟。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
