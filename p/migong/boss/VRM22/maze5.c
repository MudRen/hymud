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
                __DIR__"npc/boss21": !random(5), 
                __DIR__"npc/boss22": !random(5), 
                __DIR__"npc/boss11": !random(5), 
                __DIR__"npc/boss12": !random(5), 
                __DIR__"npc/boss13": !random(5), 
                __DIR__"npc/boss14": !random(5), 
                __DIR__"npc/boss15": !random(5), 
                __DIR__"npc/boss16": !random(5), 
                __DIR__"npc/boss17": !random(5),
                __DIR__"npc/boss23": !random(5), 
                __DIR__"npc/boss24": !random(5), 
                __DIR__"npc/boss25": !random(5), 
                __DIR__"npc/boss26": !random(5), 
                __DIR__"npc/boss27": !random(5),
                __DIR__"npc/player": !random(6), 
        ]) );  

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/bossz3");

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
	set_entry_short(HIY"众神之宫殿"NOR);

	//入口房间描述
	set_entry_desc(HIY @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG
);

	//BOSS房间短描述
	set_exit_short(HIY"众神之王殿"NOR);

	//BOSS房间描述
	set_exit_desc(HIY @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short(HIY"众神之宫殿"NOR);

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(HIY @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}