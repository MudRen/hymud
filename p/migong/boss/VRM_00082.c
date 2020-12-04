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
        set_maze_npcs(__DIR__"npc/0008/man3");

	// 迷宫中的怪物出现可能性
        //set_npcs_rate(50);

	//迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0008/zhuangzhu3");

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
	set_link_entry_room(__DIR__"vrm08out1");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"vrm08out2");

	//入口房间短描述
	set_entry_short("拉哈苏");

	//入口房间描述
	set_entry_desc(@LONG
荒僻而守冷的地方，每到重阳前后就冰封雪冻，直到第二年清明才
解冻，封达七个月之久。久居此地的人，对封江的时刻总有种奇妙的预
感，因此他们在封江的前见天，就把准备好的木架子抛入江中，用绳子
牢牢系住，封江后，这段江面就变成了一条又长又宽的水晶大道，而浮
在江面上的木架，也冻得生了根，再上梁加椽，铺砖盖瓦，用沙土和水
筑成墙，一夜之后，就冻得坚硬如石。于是，一幢幢大大小小、各式各
样的房子，就在江上盖了起来，这就是“拉哈苏”。几天之后，这个地
方就会变成个很热闹的市镇，各行各业的店铺也随之开张，屋子外虽滴
水成冰，屋子里却温暖如春。所以，老屋的人对封江的七个月并不反感
，因为这段日子他们过得也多彩多姿、丰富有趣。
LONG
);

	//BOSS房间短描述
	set_exit_short("拉哈苏");

	//BOSS房间描述
	set_exit_desc(HIB"
荒僻而守冷的地方，每到重阳前后就冰封雪冻，直到第二年清明才
解冻，封达七个月之久。久居此地的人，对封江的时刻总有种奇妙的预
感，因此他们在封江的前见天，就把准备好的木架子抛入江中，用绳子
牢牢系住，封江后，这段江面就变成了一条又长又宽的水晶大道，而浮
在江面上的木架，也冻得生了根，再上梁加椽，铺砖盖瓦，用沙土和水
筑成墙，一夜之后，就冻得坚硬如石。于是，一幢幢大大小小、各式各
样的房子，就在江上盖了起来，这就是“拉哈苏”。几天之后，这个地
方就会变成个很热闹的市镇，各行各业的店铺也随之开张，屋子外虽滴
水成冰，屋子里却温暖如春。所以，老屋的人对封江的七个月并不反感
，因为这段日子他们过得也多彩多姿、丰富有趣。
"NOR);

	//迷宫房间的短描述
	set_maze_room_short("拉哈苏");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
荒僻而守冷的地方，每到重阳前后就冰封雪冻，直到第二年清明才
解冻，封达七个月之久。久居此地的人，对封江的时刻总有种奇妙的预
感，因此他们在封江的前见天，就把准备好的木架子抛入江中，用绳子
牢牢系住，封江后，这段江面就变成了一条又长又宽的水晶大道，而浮
在江面上的木架，也冻得生了根，再上梁加椽，铺砖盖瓦，用沙土和水
筑成墙，一夜之后，就冻得坚硬如石。于是，一幢幢大大小小、各式各
样的房子，就在江上盖了起来，这就是“拉哈苏”。几天之后，这个地
方就会变成个很热闹的市镇，各行各业的店铺也随之开张，屋子外虽滴
水成冰，屋子里却温暖如春。所以，老屋的人对封江的七个月并不反感
，因为这段日子他们过得也多彩多姿、丰富有趣。
LONG
);


        // 迷宫摧毁时间
        set_remove_time(3000); 

	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
