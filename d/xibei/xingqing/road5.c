//road5.c.��ƽ��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��ƽ��"NOR);
    set("long",@LONG
��������ƽ������Χ���ǵ��̣��������������ַǳ���Զ���ɼ���ڻԻ�
�Ĺ���͸��ʵĳ���������������Ҫ���̣�����ϸ����ΰ������ξ��ӽ�������
���̵��̲飬�Է���ϸ�����룬ǧ����������ǡ����������츮�������ҵ��, 
�ڽ����ʹ��������Ĺٷ�������·������ȫ�����Ŀ�ջ��������һ�����ֺŵ�
����.
LONG);
   
    set("exits",([
        "south"   : __DIR__"road6",
        "north"   : __DIR__"road4",
        "east"    : __DIR__"kezhan",
        "west"    : __DIR__"dangpu",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}

