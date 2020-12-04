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
                  
        
        //��������
        //set_true_death_room(1);

        //�Թ��ĵ��߳� 
        set_maze_long(5); 

        //set_npcs_rate(66);
        
        set_lonely_create(1);
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("east"); 
                        
        //�������������ӷ��� 
        set_link_entry_dir("east"); 
                        
        //�������������ӵ����� 
        set_link_entry_room("/d/city/wumiao"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("west"); 
                        
        //��������������ӵ����� 
        set_link_exit_room("/d/city/wumiao"); 

        //�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/eboss/eboss4");
        
        
        // �Թ���ڵĹ��
//        set_entry_npcs( "/d/city/npc/liumang" );

        //set_maze_boxs(1);
        set_maze_traps(2); 
                        
        //�������������
        //set_link_entry_room_x(ENTER_ROOM_X);
        //set_link_entry_room_y(ENTER_ROOM_Y);
        //set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //��ͨ��������
        set_maze_room_short(HIR"�����Ƕ���"NOR);
                        
        set_maze_room_desc(@LONG
���½Ƕ����У��Ƕ�ʿ�Ǵ��Żƽ���ߣ����ŷ��Ź���Ŀ��ף�
�������Ͷ��ƽ��нǶ����ޣ�����Щɳ���Ͻ������Ľ�ʿ��ͬ
������û�г��ĺ��飬����һ������Ļ�����ڡ�
LONG); 

        //��ڷ�������� 
        set_entry_short(HIR"�����Ƕ���"NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
���½Ƕ����У��Ƕ�ʿ�Ǵ��Żƽ���ߣ����ŷ��Ź���Ŀ��ף�
�������Ͷ��ƽ��нǶ����ޣ�����Щɳ���Ͻ������Ľ�ʿ��ͬ
������û�г��ĺ��飬����һ������Ļ�����ڡ�
LONG);
                        
        //���ڷ�������� 
        set_exit_short(HIR"�����Ƕ���"NOR); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
���½Ƕ����У��Ƕ�ʿ�Ǵ��Żƽ���ߣ����ŷ��Ź���Ŀ��ף�
�������Ͷ��ƽ��нǶ����ޣ�����Щɳ���Ͻ������Ľ�ʿ��ͬ
������û�г��ĺ��飬����һ������Ļ�����ڡ�
LONG);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(0);                                                

       // �Թ�ˢ��ʱ��
        //set_maze_refresh(680); 
        
        // �Թ��ݻ�ʱ��
        set_remove_time(1080); 
} 



