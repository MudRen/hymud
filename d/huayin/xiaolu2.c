// xiaolu2.c

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
����ͭɽ�����Ψһ����ͨ����ĵ�·�������������һ��
С�֡�С�ֲ��������򶫿���ԶԶ������ͷ�Ĵ�ڡ�·��������
������ũ��˵��ʲô����һ������ȴ��Ĭ�ˡ�������Կ���һ
��С���¡�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu1",
               "east" : __DIR__"xiaolu3",
               "northup":__DIR__"tupo",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
