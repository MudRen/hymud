//wall2.c.��ǽ
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��ǽ"NOR);
    set("long",@LONG
��ǽ�������Ļʹ�������ʡ������Ժ����˾������������������ڹ����ڡ���
���ʹ���Ԫ껹�����һƬ����ڻԻ͵Ĺ����Ⱥ��ƽ���ס�ĵͰ������γ���
���Աȡ�
    ��ǽ����һ����ʯ·����ֱͨ����.
LONG);
    set("exits",([
         "north"  : __DIR__"wall3",
         "south"  : __DIR__"wall1",
    ]));
    set("outdoors","xingqing");
    setup();
}

