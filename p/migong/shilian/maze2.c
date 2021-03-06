#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
        __DIR__"unique_room/snakehole",
        __DIR__"unique_room/bearlair",
        __DIR__"unique_room/wolfcave",
        __DIR__"unique_room/tigerhill",
        __DIR__"unique_room/dragonland",
});

void create() 
{ 
        //迷宫房间所继承的物件的档案名称。 
        set_inherit_room( ROOM ); 
                        
        //唯一房间
        set_unique_room( unique_rooms ); 
        set_npcs_rate(50);
        //迷宫房间里的怪物。 
        set_maze_npcs( ([
                __DIR__"npc/mob": random(2),
                __DIR__"npc/toad": !random(3),
                __DIR__"npc/rabbit": !random(5),  
                __DIR__"npc/wolf_baby": !random(5), 
                __DIR__"npc/wolf_big": !random(5), 
                __DIR__"npc/wolf_king": !random(6), 
                __DIR__"npc/tiger_baby": !random(4), 
                __DIR__"npc/tiger_big": !random(5), 
                __DIR__"npc/tiger_king": !random(10), 
                __DIR__"npc/bear_baby": !random(3), 
                __DIR__"npc/bear_big": !random(5), 
                __DIR__"npc/bear_king": !random(6), 
                __DIR__"npc/snake_baby": !random(4), 
                __DIR__"npc/snake_big": !random(5), 
                __DIR__"npc/snake_king": !random(6), 
                __DIR__"npc/dragon_baby": !random(5), 
        ]) );                   
        
        //不算死亡
        //set_true_death_room(1);

        //迷宫的单边长 
        set_maze_long(11); 

        //set_npcs_rate(50);
        
        set_lonely_create(1);
                        
        //入口方向(出口在对面) 
        set_entry_dir("east"); 
                        
        //入口与区域的连接方向 
        set_link_entry_dir("east"); 
                        
        //入口与区域的连接档案名 
        set_link_entry_room(__DIR__"enter2"); 
                        
        //出口与区域的连接方向 
        set_link_exit_dir("west"); 
                        
        //出口与区域的连接档案名 
        set_link_exit_room(__DIR__"out2"); 

        // 迷宫出口的怪物。
        set_exit_npcs( ([
                __DIR__"npc/boss" : 1,
                __DIR__"npc/lev9" : 2,	
                __DIR__"npc/mob" : 2,		
        ]) );
        // 迷宫入口的怪物。
//        set_entry_npcs( "/d/city/npc/liumang" );

        set_maze_boxs(2);
        set_maze_traps(8); 
                        
        //以下是入口坐标
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //普通房间描述
        set_maze_room_short(HIG"试炼之森深处"NOR);
                        
        set_maze_room_desc(@LONG
试炼之森树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
这是一片茂密的树林，阵阵黑雾飘来，只觉头晕目眩。好象被人
设计了一种阵，一走进来，你仿佛迷失了方向。不时有腥风吹来，
发出阵阵恶臭。
LONG); 

        //入口房间短描述 
        set_entry_short(HIR"试炼之森深处"NOR); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
试炼之森树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
这是一片茂密的树林，阵阵黑雾飘来，只觉头晕目眩。好象被人
设计了一种阵，一走进来，你仿佛迷失了方向。不时有腥风吹来，
发出阵阵恶臭。
LONG); 
                        
        //出口房间短描述 
        set_exit_short(HIY"试炼之森深处"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
试炼之森树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
这是一片茂密的树林，阵阵黑雾飘来，只觉头晕目眩。好象被人
设计了一种阵，一走进来，你仿佛迷失了方向。不时有腥风吹来，
发出阵阵恶臭。
LONG); 

        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                


       // 迷宫刷新时间
        set_maze_refresh(1800); 
        
        // 迷宫摧毁时间
        set_remove_time(3600); 
} 

string query_my_map(){  return read_file(__DIR__"maze2.map");}

