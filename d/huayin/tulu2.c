// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
����ͭɽ���һ��С��·��ԭ����������û��·��ֻ��ũ
���ߵĶ��ˣ���̤��һ������С·������ԶԶ����������ȳ���
�򱱱���һ��С�ӡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"west":__DIR__"xiaolu1",
               "south" : __DIR__"tulu1",
               "northdown":__DIR__"xiaohe1",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
