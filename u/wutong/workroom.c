#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",BLINK+HIR "���쾻��"NOR);
        set("long", HIY @LONG
��Խ��ʱ��Ϳռ䣬�������޾��Ĺ����ͺڰ������ܴﵽ������......
��ʱ������Ϳռ���յ�֮������һ���ޱߵ�ԭҰ......
�������ֻ�б���ѡ�еģ�����ȥ�Ǹ�����......
����û�м�����û��������û��ʹ��ͱ���......
�����Ǵ�����һ��ʹ��ͷ����н�ų��������õľ���......
�������--���쾻��������
������......������ģ�һ���Ը���+ȫ��Ȩ+����֤����������
LONG 
NOR );
        set("exits", ([ 
            "down" : "/d/city/guangchang",
            "biwu" : "/d/wizard/biwu",
]));

        set("valid_startroom",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("chatroom",1);
        set("pingan",1);
        set("no_fight",1);
        set("chatroom",1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}

