inherit ROOM;
#include <ansi.h>
#include <room.h>
void create() 
{ 
    set("short", "�������"); 
    set("long", @long
�������ⵡ���������ɡ�������֮�ڣ�������֮�ԡ�̫����
̫�������в���ֵУ������������������������δ��������ɱ
�У����Գ������ԡ������ݡ�
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou1b", 
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
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "south" && !obj->query_temp("����¥/lou1a")){
                if (present("liu yuhen", this_object()))
                {
                        another = present("liu yuhen", this_object());
                        return notify_fail(another->name()+"��Ц��������Ӯ�ң������ô�����¥��\n");
                } else {
                        another = new(__DIR__"npc/liuyuhen");
                        another->move(environment(obj));
                        message_vision(HIR"ͻȻ����ǰһ����һ����Ӱ����������ǰ!\n"NOR, obj);   
                   return notify_fail(another->name()+"��Ц����������Ҫ�������Ҿ�Ҫ��������\n");
                }
        }       
        return 1;
}