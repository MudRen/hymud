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
	set_maze_npcs(__DIR__"npc/0007/beast");



	//�Թ��������BOSS��
	set_exit_npcs(__DIR__"npc/0007/baihuaxianzi");



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
	set_entry_short("�ٻ���");

	//��ڷ�������
	set_entry_desc(HIM"
	һƬƽ̹�ȵأ���������ɽ���ƣ�ɽ����������ƣ�����һƬ���ɸ��ء�
�����ļ���������ɫ�ʻ����������ޣ���Ŀ�����Ŀ������ӭ�ˣ���һƬ����Ǭ
�����������硣
"NOR);

	//BOSS���������
	set_exit_short("�ٻ�����");

	//BOSS��������
	set_exit_desc(HIM"
	һƬƽ̹�ȵأ���������ɽ���ƣ�ɽ����������ƣ�����һƬ���ɸ��ء�
�����ļ���������ɫ�ʻ����������ޣ���Ŀ�����Ŀ������ӭ�ˣ���һƬ����Ǭ
�����������硣
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short("�ٻ�����");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(HIM"
	һƬƽ̹�ȵأ���������ɽ���ƣ�ɽ����������ƣ�����һƬ���ɸ��ء�
�����ļ���������ɫ�ʻ����������ޣ���Ŀ�����Ŀ������ӭ�ˣ���һƬ����Ǭ
�����������硣
"NOR);
        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 
	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	//set_outdoors(1);
}
