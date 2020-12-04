#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0



void create() 
{ 
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM ); set("no_clean_up",1);
                        
        //Ψһ����
        //set_unique_room( unique_rooms ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                __DIR__"npc/0000/toad": random(2),
                __DIR__"npc/0000/rabbit": random(2),  
                __DIR__"npc/0000/wolf_baby": random(2), 
                __DIR__"npc/0000/wolf_big": random(2), 
                __DIR__"npc/0000/wolf_king": random(2), 
                __DIR__"npc/0000/tiger_baby": random(2), 
                __DIR__"npc/0000/tiger_big": random(2), 
                __DIR__"npc/0000/tiger_king": !random(2), 
                __DIR__"npc/0000/bear_baby": random(2), 
                __DIR__"npc/0000/bear_big": random(2), 
                __DIR__"npc/0000/bear_king": random(2), 
                __DIR__"npc/0000/snake_baby": random(2), 
                __DIR__"npc/0000/snake_big": random(2), 
                __DIR__"npc/0000/snake_king": random(2), 
                __DIR__"npc/0000/dragon_baby": random(2), 
                __DIR__"npc/0000/dragon": !random(8), 	
        ]) );                   
        
        //��������
        //set_true_death_room(1);

        //�Թ��ĵ��߳� 
        set_maze_long(8); 

        set_npcs_rate(66);
        
        set_lonely_create(1);
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("east"); 
                        
        //�������������ӷ��� 
        set_link_entry_dir("east"); 
                        
        //�������������ӵ����� 
        set_link_entry_room("/d/city/wumiao"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("south"); 
                        
        //��������������ӵ����� 
        set_link_exit_room(__DIR__"vrm00out1"); 

        //�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/0000/boss");
        
        
        // �Թ���ڵĹ��
//        set_entry_npcs( "/d/city/npc/liumang" );

        set_maze_boxs(2);
        set_maze_traps(6); 
                        
        //�������������
        //set_link_entry_room_x(ENTER_ROOM_X);
        //set_link_entry_room_y(ENTER_ROOM_Y);
        //set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //��ͨ��������
        set_maze_room_short("ԭʼɭ��");
                        
        set_maze_room_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG); 

        //��ڷ�������� 
        set_entry_short("ԭʼɭ��"); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);
                        
        //���ڷ�������� 
        set_exit_short("ԭʼɭ��"); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(1);                                                

       // �Թ�ˢ��ʱ��
        //set_maze_refresh(680); 
        
        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 
} 



