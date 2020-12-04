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
        set_maze_npcs(__DIR__"npc/0015/man4");

	// �Թ��еĹ�����ֿ�����
        //set_npcs_rate(50);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/0015/zhuangzhu4");

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
	set_link_entry_room(__DIR__"vrm15out3");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room("/d/city/wumiao");

	//��ڷ��������
	set_entry_short("�����");

	//��ڷ�������
	set_entry_desc(@LONG
ħ��֮һ��ħ���޿����һ��Ϊ�����������һ�ֶϱ�֮��
�����²����������Ǳ��ű�ѧ�ա��ճɺ�����ϴ�������̣�ð
�������ɱ��ͬ�ţ������ڵ��������Ϊ�����ڲ�ƽ����ޡ�
LONG
);

	//BOSS���������
	set_exit_short("�����");

	//BOSS��������
	set_exit_desc(HIB"
ħ��֮һ��ħ���޿����һ��Ϊ�����������һ�ֶϱ�֮��
�����²����������Ǳ��ű�ѧ�ա��ճɺ�����ϴ�������̣�ð
�������ɱ��ͬ�ţ������ڵ��������Ϊ�����ڲ�ƽ����ޡ�
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short("�����");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
ħ��֮һ��ħ���޿����һ��Ϊ�����������һ�ֶϱ�֮��
�����²����������Ǳ��ű�ѧ�ա��ճɺ�����ϴ�������̣�ð
�������ɱ��ͬ�ţ������ڵ��������Ϊ�����ڲ�ƽ����ޡ�
LONG
);


        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
