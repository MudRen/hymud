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
        set_maze_npcs( ([
                __DIR__"npc/boss21": !random(5), 
                __DIR__"npc/boss22": !random(5), 
                __DIR__"npc/boss11": !random(5), 
                __DIR__"npc/boss12": !random(5), 
                __DIR__"npc/boss13": !random(5), 
                __DIR__"npc/boss14": !random(5), 
                __DIR__"npc/boss15": !random(5), 
                __DIR__"npc/boss16": !random(5), 
                __DIR__"npc/boss17": !random(5),
                __DIR__"npc/boss23": !random(5), 
                __DIR__"npc/boss24": !random(5), 
                __DIR__"npc/boss25": !random(5), 
                __DIR__"npc/boss26": !random(5), 
                __DIR__"npc/boss27": !random(5),
                __DIR__"npc/player": !random(6), 
        ]) );  

	// �Թ��еĹ�����ֿ�����
        //set_npcs_rate(50);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/bossz3");

	//�Թ��ĵ��߳�
        set_maze_long(6); 

        set_npcs_rate(88);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"out3");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room("/d/city/wumiao"); 

	//��ڷ��������
	set_entry_short(HIY"����֮����"NOR);

	//��ڷ�������
	set_entry_desc(HIY @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG
);

	//BOSS���������
	set_exit_short(HIY"����֮����"NOR);

	//BOSS��������
	set_exit_desc(HIY @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short(HIY"����֮����"NOR);

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(HIY @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG
);


        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(1);
}