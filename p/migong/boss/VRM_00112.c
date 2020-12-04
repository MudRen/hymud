#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// �Թ�����Ҫ����͵ȼ���

        set_lonely_create(1);


	//�Թ�������Ĺ��
        set_maze_npcs(__DIR__"npc/0011/man3");

	// �Թ��еĹ�����ֿ�����
        //set_npcs_rate(50);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/0011/zhuangzhu3");

	//�Թ��ĵ��߳�
        set_maze_long(6); 

        set_npcs_rate(66);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"vrm11out1");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"vrm11out2");

	//��ڷ��������
	set_entry_short("�����Ӱ");

	//��ڷ�������
	set_entry_desc(@LONG
һ��ƽ�����ơ���Ө����ľ���ʯ���������ɵ���������ʯ��ӳ
Ҳ�轣��Ӱ���������棬�仯���죬��ʮ����ѧ�����ã���Ϊ������
������Ϊ�������Ӱ��֮�ա�
LONG
);

	//BOSS���������
	set_exit_short("�����Ӱ");

	//BOSS��������
	set_exit_desc(HIB"
һ��ƽ�����ơ���Ө����ľ���ʯ���������ɵ���������ʯ��ӳ
Ҳ�轣��Ӱ���������棬�仯���죬��ʮ����ѧ�����ã���Ϊ������
������Ϊ�������Ӱ��֮�ա�
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short("�����Ӱ");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
һ��ƽ�����ơ���Ө����ľ���ʯ���������ɵ���������ʯ��ӳ
Ҳ�轣��Ӱ���������棬�仯���죬��ʮ����ѧ�����ã���Ϊ������
������Ϊ�������Ӱ��֮�ա�
LONG
);


        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
