 // mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�ɹ���");
        set("long", @LONG
��ǽ���ߵ�СԺ������������֮�У�һ��СϪ�����ִ�������СԺ�����ƹ���
����΢�����������֡��ɹ��֡���������㣬��Ȼ����Ů��֮�֣�������ľ������ʱ
�����ڴ�����͸���ŷ���Կ���Ժ����ֲ�Ļ��ݡ�
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"yard",  
                "north" : __DIR__"sroad",
        ]));
	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,
	]));	
    set("outdoors", "huangshan");
        set("coor/x",-650);
    set("coor/y",-545);
        set("coor/z",30);
        setup();
}    
