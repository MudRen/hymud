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

//        set_lonely_create(1);

	// �Թ�����Ҫ����ߵȼ���



	//�Թ�������Ĺ��
        set_maze_npcs(__DIR__"npc/0003/beast");

	// �Թ��еĹ�����ֿ�����
        set_npcs_rate(66);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/0003/dragon");

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
	set_entry_short("��֮����");

	//��ڷ�������
	set_entry_desc(@LONG
��վ���ƶˣ���������ȥ��������һ���޼ʵ��ƺ���ͷ���Ǳ�������ա�
������ȥ��ֻ��һƬ������ɫ��ż����һЩϸϸ�İ��߹ᴩ���С�һֻС��
ݺ���ĵش��ƴ���̽��ͷ�����ܾ��ȵؿ����㡣
LONG
);

	//BOSS���������
	set_exit_short("��֮��");

	//BOSS��������
	set_exit_desc(HIW"

���������֮��ͷ������������
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short("��֮����");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
��վ���ƶˣ���������ȥ��������һ���޼ʵ��ƺ���ͷ���Ǳ�������ա�
������ȥ��ֻ��һƬ������ɫ��ż����һЩϸϸ�İ��߹ᴩ���С�һֻС��
ݺ���ĵش��ƴ���̽��ͷ�����ܾ��ȵؿ����㡣
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
	// �Թ�����ʱ��ID��ˢ��ʱ�䡣
        set_remove_time(3000);         
        
}
