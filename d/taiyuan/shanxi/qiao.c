#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "������"); 
        set("long", @long
����������ͨ������Ψһ������Ҳ�ǹ��ͺɻ����֮�����峿�ɹ�
�ߺ��ճ����������Զ��ɽ��¥�����ʺ磬��������ɹۡ�������Ҷ
����̣�ӳ�պɻ������족�ľ�ɫ��
long); 
       // set("type","waterbody");
        set("exits",([
                //"west":__DIR__"shulin4",
                "north":__DIR__"yuan4",
                "south":__DIR__"zhubaoge",
        ]) );
       set("outdoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-350);
        set("coor/z",100);
        setup();
} 
