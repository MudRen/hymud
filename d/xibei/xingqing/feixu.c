//feixu.c.����
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","����");
    set("long",@LONG
����ԭ����ƽ��������ҵ������ʮ��ǰһ��������з��ݾ���֮һ�档ֻ
����һƬ���������ڣ��ڽֵĵ����ѿ�����һЩ���̣��𲽻ָ���������
LONG);
   
    set("exits",([
        "out"   : __DIR__"yaopu",
    ]));  
    set("search_things",([
                "����" :  __DIR__"npc/obj/jian4",
                ]) );
    set("outdoors","xingqing");
    setup();
}

