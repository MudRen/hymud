// xiaolu7.c

inherit ROOM;
void create()
{
        set("short","ͭɽ�嶫��");
        set("long",@LONG                                   
�������ͭɽ��Ķ����ˡ�������������һ��������ϡϡ
��������˴����������
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu6",
               "northup":__DIR__"tulu4",
               "east" : __DIR__"tl5",
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
