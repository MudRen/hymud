// xiaolu3.c

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
ͭɽ���䲻�ܴ󣬵�����������ɽ���山����һ��С��������
����һ����ׯ�ڵĺõط�����˵ʮ�굹�������Ƿ����꾰������
�������뵹Ҳ����á�·����һ��СС�ľƹݡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu2",
               "east" : __DIR__"xiaolu4",
               "south":__DIR__"jiuguan",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
