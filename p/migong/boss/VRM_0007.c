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
	set_maze_npcs(__DIR__"npc/0007/beast");



	//迷宫房间里的BOSS。
	set_exit_npcs(__DIR__"npc/0007/baihuaxianzi");



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
	set_entry_short("百花谷");

	//入口房间描述
	set_entry_desc(HIM"
	一片平坦谷地，四周是青山环绕，山腰间白云悠悠，真是一片神仙福地。
谷内四季常春，各色鲜花，竞相争艳，满目青翠萦目，红紫迎人，好一片锦绣乾
坤，花花世界。
"NOR);

	//BOSS房间短描述
	set_exit_short("百花谷中");

	//BOSS房间描述
	set_exit_desc(HIM"
	一片平坦谷地，四周是青山环绕，山腰间白云悠悠，真是一片神仙福地。
谷内四季常春，各色鲜花，竞相争艳，满目青翠萦目，红紫迎人，好一片锦绣乾
坤，花花世界。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("百花谷内");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(HIM"
	一片平坦谷地，四周是青山环绕，山腰间白云悠悠，真是一片神仙福地。
谷内四季常春，各色鲜花，竞相争艳，满目青翠萦目，红紫迎人，好一片锦绣乾
坤，花花世界。
"NOR);
        // 迷宫摧毁时间
        set_remove_time(3000); 
	// 迷宫房间是否为户外房间？
	//set_outdoors(1);
}
