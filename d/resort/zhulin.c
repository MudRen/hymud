 // Room: /d/shaolin/zhulin.c
//inherit VRM_SERVER;
inherit "/adm/daemons/vrm_server"; 
void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM ); 
        //�Թ�������Ĺ��
        //set_maze_npcs(__DIR__"npc/maque"); 
        //�Թ��ĵ��߳�
        set_maze_long(6); 
        //��ڷ���(�����ڶ���)
        set_entry_dir("east"); 
        //�������������ӷ���
        set_link_entry_dir("east"); 
        //�������������ӵ�����
        set_link_entry_room(__DIR__"shandao3"); 
        //��������������ӷ���
        set_link_exit_dir("west"); 
        //��������������ӵ�����
        set_link_exit_room(__DIR__"muwu"); 
        //��ڷ��������
        set_entry_short("ɽ����"); 
        //��ڷ�������
        set_entry_desc(@LONG
����������ɽ�İ�ɽ����������һ����ֱ��ɽ������������
ȥ��һƬ���̵����֣���ʱ��������������
LONG
); 
        //���ڷ��������
        set_exit_short("��ʯ·"); 
        //���ڷ�������
        set_exit_desc(@LONG
������һ����ʯС·��������һƬ���̵����֣���ʱ������
��������������ȥ��Լһ��Сľ�ݣ���ɽ���֣�����һ��������
Դ�������ڡ�
LONG
); 
        //�Թ�����Ķ�����
        set_maze_room_short("����"); 
   //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
����һƬŨ�ܵĴ����֣�С����������ͷ紵�����ֵ�ɳɳ
����֯�������Ĵ���Ȼ�����ɡ������Ӳݴ���˵�������������
������׳�Ĵ����ֱ���ϣ�����������������ϴ���
LONG
); 
        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
}  
