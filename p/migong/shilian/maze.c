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
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM ); 
                        
        //Ψһ����
        //set_unique_room( unique_rooms ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                __DIR__"npc/lev1": random(2),
                __DIR__"npc/lev2": random(2),  
                __DIR__"npc/lev3": !random(3), 
                __DIR__"npc/lev4": !random(4), 
                __DIR__"npc/lev5": !random(5), 
                __DIR__"npc/lev6": !random(6), 
                __DIR__"npc/lev7": !random(7), 
                __DIR__"npc/lev8": !random(8), 
                __DIR__"npc/lev9": !random(9), 
                __DIR__"npc/mob": !random(10), 
        ]) );                   
        
        //��������
        //set_true_death_room(1);

        //�Թ��ĵ��߳� 
        set_maze_long(11); 
        set_npcs_rate(50);
        //set_npcs_rate(50);
        
        set_lonely_create(1);
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("east"); 
                        
        //�������������ӷ��� 
        set_link_entry_dir("east"); 
                        
        //�������������ӵ����� 
        set_link_entry_room(__DIR__"enter"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("west"); 
                        
        //��������������ӵ����� 
        set_link_exit_room(__DIR__"out"); 

        // �Թ����ڵĹ��
        //set_exit_npcs( ([
//                "/d/city/npc/liumang" : 1,
//        ]) );
        // �Թ���ڵĹ��
//        set_entry_npcs( "/d/city/npc/liumang" );

        set_maze_boxs(1);
        set_maze_traps(6); 
                        
        //�������������
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //��ͨ��������
        set_maze_room_short(HIG"����֮ɭ"NOR);
                        
        set_maze_room_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG); 

        //��ڷ�������� 
        set_entry_short(HIR"����֮ɭ���"NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);
                        
        //���ڷ�������� 
        set_exit_short(HIY"����֮ɭ�в�"NOR); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(1);                                                

       // �Թ�ˢ��ʱ��
        set_maze_refresh(1800); 
        
        // �Թ��ݻ�ʱ��
        set_remove_time(3600); 
        //set_remove_time(1); 
} 

string query_my_map(){  return read_file(__DIR__"maze.map");}

