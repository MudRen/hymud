//yuanhaogong.c.Ԫ껹�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"Ԫ껹�"NOR);
    set("long",@LONG
��ǰ��һ�����Է����Ϊ��Ԫ껹������˵�ԭ��һ����أ�Ԫ�����ģ��
�Ƴ����ص����칬�������أ�����������ˮ��Ϊ����Ԫ껹������������ͤ�
̨�أ�������ʤ�������������ξ����أ��䱸ɭ��.
LONG);
    set("exits",([
         "south"  : __DIR__"road22",
    ]));
    set("outdoors","xingqing");
    setup();
}

