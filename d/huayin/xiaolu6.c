// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
��·�������ֿ�ʼ����е������ˣ�·���ϱ���һ��С�ӻ�
�̡�����������ߣ�����С��Ķ����ˡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"shuijing",
               "east" : __DIR__"xiaolu7",
               "south":__DIR__"zahuopo",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
