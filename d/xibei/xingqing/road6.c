//road6.c.��ƽ��
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
�ڽ����ʹ��������Ĺٷ�������·������һ��ҩ�̣���˵���������ֺŷֵ꣬·
������ȫ�������̺�.
LONG);
   
    set("exits",([
        "south"   : __DIR__"road20",
        "north"   : __DIR__"road5",  
        "east"    : __DIR__"yaopu",
        "west"    : __DIR__"shanghao",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}

