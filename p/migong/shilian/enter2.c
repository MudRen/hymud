inherit ROOM; 
void create() 
{ 
        set("short", "����������С��"); 
        set("long", @LONG 
����֮ɭ������������Ʈ����ֻ��ͷ��Ŀѣ��������
�����һ����һ�߽�������·���ʧ�˷��򡣲�ʱ���ȷ紵����
������������������һ������������С�ݡ�
LONG); 
                        
        set("outdoors", "forest"); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_npc",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "west" : __DIR__"maze2/entry", 
                "east" : __DIR__"out", 	
        ])); 
      set("objects",([
                __DIR__"npc/forest_master": 1,  
                "/d/city/npc/obj/jitui": 2,  	
                "/d/city/npc/obj/jiudai": 2,  		
        ])); 
        
/*        set("objects",([
                __DIR__"npc/forest_master": 1,  
        ])); */
        setup();
        replace_program(ROOM); 
} 
