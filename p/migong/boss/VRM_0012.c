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
        set_maze_npcs(__DIR__"npc/0012/man");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0012/zhuangzhu");

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
	set_link_exit_room(__DIR__"vrm12out1");

	//入口房间短描述
	set_entry_short("杀人庄");

	//入口房间描述
	set_entry_desc(@LONG
从外面看上去，杀人庄堂皇、宏大，实际上是充满疯狂、变态
、恐怖之地。在这里，任何人都可能被杀，也绝没有人救他。之所
以形成这种局面皆因这个庄子有一条特殊的庄规：每代庄主都必须
同自己的同胞姐妹结为夫妻，这样一代代的近亲繁殖所生也的后代
，也就越来越变态、疯狂、不具人性，身为庄主后也常常做出荒诞
、血腥的事情，终于弄得不可收拾，杀人庄已发成一座鬼窟。
LONG
);

	//BOSS房间短描述
	set_exit_short("聚义堂");

	//BOSS房间描述
	set_exit_desc(HIB"
这本来是聚义庄的聚义堂，随着主人家的衰败，这里只留下一
些没人带走的朽木梁柱。不过，现在整个大厅已经重新收拾过，白
布缠梁，白纱盖柱，大厅的当中，是一个简单庄重的灵位，许多江
湖人的挽联花圈挂在四周。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("杀人庄");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
从外面看上去，杀人庄堂皇、宏大，实际上是充满疯狂、变态
、恐怖之地。在这里，任何人都可能被杀，也绝没有人救他。之所
以形成这种局面皆因这个庄子有一条特殊的庄规：每代庄主都必须
同自己的同胞姐妹结为夫妻，这样一代代的近亲繁殖所生也的后代
，也就越来越变态、疯狂、不具人性，身为庄主后也常常做出荒诞
、血腥的事情，终于弄得不可收拾，杀人庄已发成一座鬼窟。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
