inherit ROOM; 
void create() 
{ 
        set("short", "ɭ�����"); 
        set("long", @LONG 
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG
); 
                        
        set("outdoors", "forest"); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "west" : __DIR__"maze/entry", 
                //"north" : "/d/yanping/gudao1", 	
        ])); 
        set("objects",([
                __DIR__"npc/forest_master": 1,  
        ])); 
        setup();
        replace_program(ROOM); 
} 
