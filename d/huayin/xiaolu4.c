// xiaolu4.c

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
�����ͭɽ���Ժ����Ǹо������ܺ�����һ�����أ��ϱ���
������һ����һ���Ĵ�������·����һ��ССС��Ժ�䡣
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu3",
               "east" : __DIR__"daguchang",
               "south":__DIR__"datiepu",
               "north":__DIR__"minju",
               
        ]) );
	set("objects",([
	"/clone/npc/npc" : 3,
]));

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
