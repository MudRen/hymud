//road26.c.��ƽ��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��ƽ��"NOR);
    set("long",@LONG
�����Ǿ�ƽ������Χ�����ƽ��סլ����һЩ����. ����ϸ����ΰ�������
���ӽ����������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ�����ľ������
���٣��������س�����˶��Եú����أ�ƽʱһ��İ��ն������������
LONG);
   
    set("exits",([
///            "north"     : "/d/zuzhi/yipin_tang/xiaodao1", 
             "south"   : __DIR__"road25",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}
int valid_leave( object who, string dir )
{
    if ( !userp( who ) && dir == "north" )
        return 0;
    return ::valid_leave( who, dir );
}

