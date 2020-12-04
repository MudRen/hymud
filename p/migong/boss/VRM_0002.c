#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM ); set("no_clean_up",1);



//        set_lonely_create(1);

        //�Թ�������Ĺ��
        set_maze_npcs(__DIR__"npc/0002/beast");

        // �Թ��еĹ�����ֿ�����
        set_npcs_rate(66);

        //�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/0002/dragon");

//�Թ��ĵ��߳�
        set_maze_long(8); 

        set_npcs_rate(66);
        
        set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(6); 

 	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room("/d/city/wumiao");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room("/d/city/wumiao");

        //��ڷ��������
        set_entry_short("��֮��ͷ");

        //��ڷ�������
        set_entry_desc(@LONG
�����������������Ǻ�ȥ������������Ұ������Զ�����ܣ�
�����¾�ɫ�������������Զ������������ƽ����ɽ���ϳ���
������ݣ�Ʈ�ŵ�������������е�̫������߽������£�ˮ��
�����⳯���߻�����ȥ��
LONG
);

        //BOSS���������
        set_exit_short("��֮��");

        //BOSS��������
        set_exit_desc(HIC"

���������֮��ͷ������������
"NOR);

        //�Թ�����Ķ�����
        set_maze_room_short("��֮��ͷ");

        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
�����������������Ǻ�ȥ������������Ұ������Զ�����ܣ�
�����¾�ɫ�������������Զ������������ƽ����ɽ���ϳ���
������ݣ�Ʈ�ŵ�������������е�̫������߽������£�ˮ��
�����⳯���߻�����ȥ��
LONG
);

        // �Թ�������ڵ�ʱ�䡣
        set_remove_time(3000); 

        //�������������
        //set_link_entry_room_x(ENTER_ROOM_X);
        //set_link_entry_room_y(ENTER_ROOM_Y);
        //set_link_entry_room_z(ENTER_ROOM_Z);
        
        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        //set_outdoors(1);
}

