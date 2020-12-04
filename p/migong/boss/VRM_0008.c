#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( ROOM ); set("no_clean_up",1);

        set_lonely_create(1);

	//�Թ��ĵ��߳�
        set_maze_long(8); 

        set_npcs_rate(66);
        



        set_maze_boxs(2);
        set_maze_traps(6); 


	//�Թ�������Ĺ��
	set_maze_npcs(__DIR__"npc/0008/beast");


	//�Թ��������BOSS��
	set_exit_npcs(__DIR__"npc/0008/leijiu");



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
	set_entry_short("����ɽ��");

	//��ڷ�������
	set_entry_desc(HIY"
	��һ�������߰ٶ�ʮ�׵Ķ��Ҿ��ڡ����������µ�Сɽ�ȣ���ΧһƬ�ž���
ż��һ����ʯ���£���������������ֻ��������������������
"NOR);

	//BOSS���������
	set_exit_short("����ɽ��");

	//BOSS��������
	set_exit_desc(HIY"
	��һ�������߰ٶ�ʮ�׵Ķ��Ҿ��ڡ����������µ�Сɽ�ȣ���ΧһƬ�ž���
ż��һ����ʯ���£���������������ֻ��������������������
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short("����ɽ��");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(HIY"
	��һ�������߰ٶ�ʮ�׵Ķ��Ҿ��ڡ����������µ�Сɽ�ȣ���ΧһƬ�ž���
ż��һ����ʯ���£���������������ֻ��������������������
"NOR);
        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 
	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	//set_outdoors(1);
}
