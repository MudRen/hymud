inherit ROOM; 

void create() 
{ 
        set("short", "Ĺ԰���"); 
        set("long", @LONG 
Ĺ԰��û��һ�����������ϵ����ǿ�֦��Ҷ��ż������һЩ
�ɿݵĶ���ʬ�������˲�������������ɢ����һ��ʬ�׸��õ�
ζ����������һ˿������ڡ�
LONG
); 
			
        set("outdoors", "necropolis"); 
        set("virtual_room", 1);
        set("no_death_penalty", 1);
        set("no_magic", 1);
        set("exits", ([ /* sizeof() == 3 */ 
	        "south" : __DIR__"maze/entry", 
        ])); 
        set("objects",([
                "/p/migong/necropolis/obj/coffin1": 1,  
        ])); 
        setup();
 
} 
