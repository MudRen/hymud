// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
����ͭɽ���һ��С��·��ԭ����������û��·��ֻ��ũ
���ߵĶ��ˣ���̤��һ������С·�����Ǵ�ȳ����ϱ߿���Զ
Զ����һƬũ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"west":__DIR__"xiaolu1",
               "south" : __DIR__"shulin",
               "north":__DIR__"daguchang",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
