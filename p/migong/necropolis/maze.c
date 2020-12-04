// write by starfish

#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X	0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create() 
{ 
        // �Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM );  
			
        //Ψһ����
        set_unique_room( ({
                "/p/migong/necropolis/unique_room/skeleton_room",
                "/p/migong/necropolis/unique_room/ghost_room",
                "/p/migong/necropolis/unique_room/zombie_room",
                "/p/migong/necropolis/unique_room/rest_room",
                "/p/migong/necropolis/unique_room/quest_room",
        }) ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                "/p/migong/necropolis/npc/skeleton": 1+random(2),  
                "/p/migong/necropolis/npc/skeleton_fighter": 1,
                "/p/migong/necropolis/npc/skeleton_mage": 1,
                "/p/migong/necropolis/npc/zombie": 1+random(2),  
                "/p/migong/necropolis/npc/zombie_blood": 1,
                "/p/migong/necropolis/npc/zombie_power": 1,
                "/p/migong/necropolis/npc/ghost": 1+random(2),  
                "/p/migong/necropolis/npc/ghost_fire": 1,
                "/p/migong/necropolis/npc/ghost_eye": 1,
        ]) );	
	//��������		
        //set_no_death_room(1);
        
        //�Թ��ĵ��߳� 
        set_maze_long(12); 
			 set_lonely_create(1);
        //��ڷ���(�����ڶ���) 
        set_entry_dir("north"); 
			
        //�������������ӷ��� 
        set_link_entry_dir("north"); 
			
        //�������������ӵ����� 
        set_link_entry_room(__DIR__"enter"); 
			
        //��������������ӷ��� 
        set_link_exit_dir("south"); 
			
        //��������������ӵ����� 
        set_link_exit_room(__DIR__"out"); 
			        // �Թ����ڵĹ��
        //set_exit_npcs( ([
//                "/d/city/npc/liumang" : 1,
//        ]) );
        // �Թ���ڵĹ��
//        set_entry_npcs( "/d/city/npc/liumang" );
        //�������������

        set_maze_boxs(1);
        set_maze_traps(3); 

        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
			
        //��ͨ��������
        set_maze_room_short(RED "����Ĺ԰" NOR);
			
        set_maze_room_desc(@LONG
Ĺ԰��û��һ�����������ϵ����ǿ�֦��Ҷ��ż������һЩ
�ɿݵĶ���ʬ�������˲�������������ɢ����һ��ʬ�׸��õ�
ζ����������һ˿������ڡ�
LONG); 
			
        //��ڷ�������� 
        set_entry_short(HIR "����Ĺ԰���" NOR); 
			
        //��ڷ������� 
        set_entry_desc(@LONG
Ĺ԰��û��һ�����������ϵ����ǿ�֦��Ҷ��ż������һЩ
�ɿݵĶ���ʬ�������˲�������������ɢ����һ��ʬ�׸��õ�
ζ����������һ˿������ڡ�
LONG); 
			
        //���ڷ�������� 
        set_exit_short(HIW "����Ĺ԰����" NOR); 
			
        //���ڷ������� 
        set_exit_desc(@LONG
Ĺ԰��û��һ�����������ϵ����ǿ�֦��Ҷ��ż������һЩ
�ɿݵĶ���ʬ�������˲�������������ɢ����һ��ʬ�׸��õ�
ζ����������һ˿������ڡ�
LONG); 

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(1); 
       // �Թ�ˢ��ʱ��
        set_maze_refresh(1800); 
        
        // �Թ��ݻ�ʱ��
        set_remove_time(1800); 
						
} 

string query_my_map(){  return read_file(__DIR__"maze.map");}
