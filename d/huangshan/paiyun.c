 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM; 
void create() 
{ 
        set("short", "����ͤ"); 
        set("long", @LONG 
����Сͤ���¶�����ͤ��֮���ǰ��˸ߵ����ˣ�����������Ϣ���ƣ�Ҳ���Է� 
ֹ����׹�����¡���ɽ���괦������֮�У�������ȥ�����Ī�⣬ʱ���Ƿ�ƽ�˾� 
��һƬ����ʱ�沨����ӿ�������ſա� 
LONG 
        ); 
    set("exits", ([  
                "northeast" : __DIR__"guangming", 
        ])); 
    set("objects", ([ 
        __DIR__"npc/monk" : 1, 
    ]) ); 
        set("indoors", "huangshan"); 
        set("coor/x",-610); 
        set("coor/y",-530); 
        set("coor/z",30); 
        setup(); 
        replace_program(ROOM); 
}       
