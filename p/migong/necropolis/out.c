inherit ROOM; 

void create() 
{ 
        set("short", "Ĺ԰����"); 
        set("long", @LONG 
Ĺ԰��û��һ�����������ϵ����ǿ�֦��Ҷ��ż������һЩ
�ɿݵĶ���ʬ�������˲�������������ɢ����һ��ʬ�׸��õ�
ζ����������һ˿������ڡ�
LONG
); 
			
        set("outdoors", "necropolis"); 
        set("virtual_room", 1);
        set("no_magic", 1);
        set("exits", ([ /* sizeof() == 3 */ 
	        "north":__DIR__"maze/exit",
                "out"  : "/d/shaolin/xiaojing1",
        ])); 
			
        setup();

} 
int valid_leave(object me, string dir)
{
	object *inv, obj;
        if (dir == "out")
        {
    	        tell_object(me, "check!\n");
    	        inv = all_inventory(me);
    	        if (inv && sizeof(inv)>0)
		    	foreach(obj in inv) {
		    		if (obj && obj->query("maze_item"))
		    		        destruct(obj);
		    	}
        }
        return 1;
}
