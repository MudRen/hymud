#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
        "/p/migong/forest/unique_room/snakehole",
        "/p/migong/forest/unique_room/bearlair",
        "/p/migong/forest/unique_room/wolfcave",
        "/p/migong/forest/unique_room/tigerhill",
        "/p/migong/forest/unique_room/dragonland",
});

void create() 
{ 
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM ); 
                        
        //Ψһ����
        set_unique_room( unique_rooms ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                "/p/migong/forest/npc/toad": random(2),
                "/p/migong/forest/npc/rabbit": random(2),  
                "/p/migong/forest/npc/wolf_baby": random(2), 
                "/p/migong/forest/npc/wolf_big": random(5), 
                "/p/migong/forest/npc/wolf_king": random(2), 
                "/p/migong/forest/npc/tiger_baby": random(2), 
                "/p/migong/forest/npc/tiger_big": random(5), 
                "/p/migong/forest/npc/tiger_king": !random(10), 
                "/p/migong/forest/npc/bear_baby": random(2), 
                "/p/migong/forest/npc/bear_big": random(5), 
                "/p/migong/forest/npc/bear_king": random(2), 
                "/p/migong/forest/npc/snake_baby": random(2), 
                "/p/migong/forest/npc/snake_big": random(5), 
                "/p/migong/forest/npc/snake_king": random(2), 
                "/p/migong/forest/npc/dragon_baby": random(2), 
        ]) );                   
        
        //��������
        //set_true_death_room(1);

        //�Թ��ĵ��߳� 
        set_maze_long(12); 

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
        set_maze_traps(3); 
                        
        //�������������
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //��ͨ��������
        set_maze_room_short(HIG"ԭʼɭ��"NOR);
                        
        set_maze_room_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG); 

        //��ڷ�������� 
        set_entry_short(HIR"ԭʼɭ�����"NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);
                        
        //���ڷ�������� 
        set_exit_short(HIY"ԭʼɭ�ֳ���"NOR); 
                        
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
        set_remove_time(1800); 
} 

string query_my_map(){  return read_file(__DIR__"maze.map");}

