//wall7.c.��ǽ
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
         "east"   : __DIR__"door1",
         "north"  : __DIR__"wall6",
    ]));
    set("outdoors","xingqing");
    setup();
}

