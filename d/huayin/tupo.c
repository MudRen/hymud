// tupo.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG                                   
����ͭɽ�嶫�ߵ�һ��С���£����С������ͭɽ�������
�ߵĵط���վ����������Կ���ȫ�塣������һƬ����ڡ�����
�����Ǿ���Ը��̤��ġ���վ��������Ըо��ĵ��������紵
�������ֱ��Ƥ���
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "northdown":__DIR__"luanzang",
               "southdown":__DIR__"xiaolu2",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
