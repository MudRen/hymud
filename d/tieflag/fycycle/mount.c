 inherit ROOM;
#include <ansi.h> 
void create() 
{ 
        set("short", "��ɽС��"); 
        set("long", @LONG 
һ����ɽС��������������ͨ��ɽ�С��������ï�ܵ������֡�С·�ĵ����ϳ� 
�ź�����̦������ܾ�û�����������ˡ� 
LONG 
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
        "south" : __DIR__"road4", 
 //       "northup" : "/d/wangyou/up_path" , 
])); 
        set("outdoors", "fengyun"); 
        set("coor/x",30); 
        set("coor/y",1000); 
        set("coor/z",100); 
 
        set("coor/x",30); 
        set("coor/y",1000); 
        set("coor/z",100); 
        setup(); 
//        replace_program(ROOM); 
} 
int valid_leave(object me, string dir) 
{ 
        me=this_player(); 
        if( dir == "northup" && 100/((int)me->query_skill("move")+1)>random(250)) 
        { 
        message_vision(HIR"$Nһ��С�ģ�ˤ��������\n "NOR,me); 
                me->receive_wound("qi",1); 
                return notify_fail(HIW"����ɽ��������ѽ������Ӵ��������^_^ ^_^\n"NOR); 
                } 
        return 1; 
} 
         
