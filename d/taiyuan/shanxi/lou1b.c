inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "Χκ����"); 
    set("long", @long
�������ⵡ���������ɡ�������֮�ڣ�������֮�ԡ�̫����
̫�������в���ֵУ������������������������δ��������ɱ
�У����Գ������ԡ������ݡ�
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou1c", 
    	"north" : __DIR__"lou1a",
        ])); 
                set("objects", ([
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
	set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 

} 
int valid_leave(object me, string dir)
{       
        if (dir == "south" && me->query_temp("����¥/lou1a"))
        {
        me->delete_temp("����¥/lou1a");      
        }
   return 1;
}   
