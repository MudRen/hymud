#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", HIY"��"+HIR"��"+HIM"��"+HIG"��"+HIC"��"NOR); 
        set("long", @long
���۰���ˮ���У��������һ����ϴ���Ż�����ȴ���ʺ�ġ�����
�������䣬��ָ�ˬ������ȡ���䣺��һˮ�����̣�ǧ���Ա�족֮ʫ�⡣
��ǰ����ƽ̨���ٺɳأ�Ϊ�����ͺ�����ʤ�����ʳơ��ɻ���󡱡����
�л�̨ͥԺ����ʯ�������Գ�һ����
long); 
       // set("type","waterbody");
        set("exits",([
                
                "north":__DIR__"qiao",
        ]) );
        set("objects",([
                __DIR__"npc/sushaoying":1,
                __DIR__"npc/maxingkong":1,
        ]) ); 

       set("indoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-360);
        set("coor/z",100);
        setup();
} 