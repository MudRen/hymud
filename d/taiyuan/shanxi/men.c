#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "ׯ��"); 
        set("long", @long
ׯ�ž�ׯ�ţ��͵�춺ɻ����Ǻɻ����������һ�����������Խ�Ǻ�ΰ
��ׯ԰��ׯ�ž�Խ�Ǽ򵥡���ľͭ��������ʨ�ӣ��������ҡ�Ψһ��ͬ��
�ǣ�������������ģ��ȷǻ��ۣ�������ͣ����Ǵ������۵����顣����
��������ط����������ש�ߡ�

long); 
       // set("type","waterbody");
        set("exits",([
                
                "south":__DIR__"shulin",
                "north":__DIR__"yuan1",
        ]) );
        set("objects",([
                __DIR__"npc/xiaofan":1,
        ]) ); 

       set("indoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-380);
        set("coor/z",100);
        setup();
} 