//road22.c.��Ӧ��
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��Ӧ��"NOR);
    set("long",@LONG
��������Ӧ������Χ�����ƽ��סլ����һЩ���̣��������������ַǳ���
Զ���ɼ���ڻԻ͵Ĺ���͸��ʵĳ������������Ϸ�����Ԫ껹�. ������Ҫ���̣�
����ϸ����ΰ������ξ��ӽ����������̵��̲飬�Է���ϸ�����룬ǧ�������
���ǡ����������ξ��Ĵ�Ӫ.

LONG);
   
    set("exits",([
        "south"    : __DIR__"road21",
        "north"    : __DIR__"yuanhaogong", 
        "east"     : __DIR__"bingying3",
        "west"     : __DIR__"bingying4",
    ]));
    set("outdoors","xingqing");
    setup();
}

