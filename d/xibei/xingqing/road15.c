//road15.c.˳�ɷ�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"˳�ɷ�"NOR);
    set("long",@LONG
������˳�ɷ�����Χ�����ƽ��סլ����һЩ���̣��������������ַǳ���
Զ���ɼ���ڻԻ͵Ĺ���͸��ʵĳ���������������Ҫ���̣�����ϸ����ΰ���
���ξ��ӽ����������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ�
LONG);
   
    set("exits",([
        "east"    : __DIR__"road14",
        "west"    : __DIR__"road16",
    ]));
    set("outdoors","xingqing");
    setup();
}

