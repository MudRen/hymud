//road14.c.˳�ɷ�
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
���ξ��ӽ����������̵��̲飬�Է���ϸ�����룬ǧ�����������. ���������
�������Ĺ㳡��
LONG);
   
    set("exits",([
        "east"    : __DIR__"road4",
        "west"    : __DIR__"road15",
    ]));
    set("outdoors","xingqing");
    setup();
}

