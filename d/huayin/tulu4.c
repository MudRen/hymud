// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
����ͭɽ���һ��С��·��ԭ����������û��·��ֻ��ũ
���ߵĶ��ˣ���̤��һ������С·��������һ��СС��������
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"west":__DIR__"xiaolu1",
               "southdown" : __DIR__"xiaolu7",
               "east":__DIR__"xiaomiao",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
