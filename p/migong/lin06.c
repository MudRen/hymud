// Room: /d/linzhi/lin06.c

#include <ansi.h>

inherit "/adm/daemons/vrm_server.c";

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	set_inherit_room( ROOM );

//	set_maze_npcs(__DIR__"npc/maque");
        set_center_room("/d/city/guangchang");
        
        set_unique_room( ({
                "/d/city/wumiao",
                "/d/city/kedian",
                "/d/city/yaopu",
                "/d/city/wumiao2",
        }) ); 
        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                "/d/city/npc/liumang": !random(3),  
        ]) );  
//npc����
     set_npcs_rate(50);
//boss
    set_maze_boss("/d/city/npc/liumangtou");
        // �Թ����ڵĹ��
        set_exit_npcs( ([
                "/d/city/npc/liumang" : 1,
        ]) );
        // �Թ���ڵĹ��
        set_entry_npcs( "/d/city/npc/liumang" );



        set_maze_boxs(5);
        set_maze_traps(8);  
           
                //��������              
        //set_maze_nodeath(1);

	set_maze_long(12);

	//��ڷ���(�����ڶ���)
	set_entry_dir("east");

	//�������������ӷ���
	set_link_entry_dir("east");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"lin05");

	//��������������ӷ���
	set_link_exit_dir("west");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"lin07");
set_lonely_create(1);

        //�������������
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);


	//��ڷ��������
	set_entry_short("�һ���");

	set_entry_desc(@LONG
�������һ�����ֻ����������Ұ��������������һƬ��Ȼ��
���֣���֪�Ӻ�ʱ���еġ�ÿ�굽�˰������ӳ���ļ��ڣ�����
���������ժ(pick)���ӡ��ݵ������˽��������������ʹ͸���
��ġ����������ţ���Ȼ������ʧ�˷���
LONG
);

	//���ڷ��������
	set_exit_short("�һ���");

	set_exit_desc(@LONG
�������һ�����ֻ����������Ұ��������������һƬ��Ȼ��
���֣���֪�Ӻ�ʱ���еġ�ÿ�굽�˰������ӳ���ļ��ڣ�����
���������ժ(pick)���ӡ��ݵ������˽��������������ʹ͸���
��ġ����������ţ���Ȼ������ʧ�˷���
LONG
);


	//�Թ�����Ķ�����
	set_maze_room_short("�һ���");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
�������һ�����ֻ����������Ұ��������������һƬ��Ȼ��
���֣���֪�Ӻ�ʱ���еġ�ÿ�굽�˰������ӳ���ļ��ڣ�����
���������ժ(pick)���ӡ��ݵ������˽��������������ʹ͸���
��ġ����������ţ���Ȼ������ʧ�˷���
LONG
);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(1); 
        
        // �Թ�ˢ��ʱ��
        set_maze_refresh(1); 
        
        // �Թ��ݻ�ʱ��
        set_remove_time(2); 

}

string query_my_map(){  return read_file(__DIR__"lin06.map");}