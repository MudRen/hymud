inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "����"); 
    set("long", @long
�ź����������������ľ�ͷ�Ǹ��տ���ɽ�ߡ�����������˷�
������ľ��㣬�м�һ������С��¯���𲢲���ȴǡ����ʹ������ɭ
�����ɽ�ߣ������ů������
long 
    ); 
    set("exits", ([ 
    	"up" : __DIR__"lou1a", 
    	//"south" : __DIR__"midao",
    	//"west" : __DIR__"midao",
    	"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                //__DIR__"npc/huoxiu": 1,
                
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC",1);
        set("indoors","shanxi"); 
        set("coor/x",-400);
        set("coor/y",-220);
        set("coor/z",99);
        setup(); 
                create_door("out", "ʯ��", "enter", DOOR_CLOSED); 

} 