inherit ROOM;
#include <room.h>
#include <ansi.h>
void create() 
{ 
    set("short", WHT"�����ۻ�"NOR); 
    set("long", @long
ڿҲ����ڿҲ��ʵ����ڿҲ��������̫����̫����ʾ֮�Զ���
���侲�����������涯���㡱���������ң����Դ��档������
�����ԱС�˳�Զ�ԥ��ԥ˳�Զ���
long 
    ); 
    set("exits", ([ 
    	"up" : __DIR__"lou2a", 
    	"north" : __DIR__"lou1h",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                __DIR__"npc/duo": 1,
                
        ]));
        
        set("no_magic",1);
        set("indoors","shanxi"); 
        set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 
                //create_door("out", "ʯ��", "enter", DOOR_CLOSED); 

} 