//qiandian1.c.ǰ��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"ǰ��"NOR);
    set("long",@LONG
�������ʮ�ɣ���һ�ٶ�ʮ�ɡ��������ѵ���ܦ��������ɽ���ϵĳǱ�����
ͬ���ϵ���Ժ�����������١�¥���㲻��Ĵ�������������������ͣ��ڱ�
��ɽ�Ƶĳ���֮�£��Եø�������ɺͺ����������������ǰ·�ϣ�����Կ���
һ��һ��������������ڳ��ݡ����㡣�������Ź���ķ�ɮ˫�ֺ�ʲ��Ҳ������
���С�
LONG);
   
    set("exits",([
        "north"   : __DIR__"door5",
        "south"   : __DIR__"dadian1",
    ]));
    set("outdoors","lanzhou");
    setup();
}

