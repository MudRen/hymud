//yaopu.c.ҩ��
//date:1997.8.28
//by dan

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
    set("short",MAG"̩��������ֺ�"NOR);
    set("long",@LONG
ҩ���¿��Ų��ã�������̩���ÿ��ķֺţ����ܴ�һ�ӭ��������ⲻ��
ҩ�̲���ȴ�쳣�����ࣻ�����ǹ�̨����̨�����Ǹ������, ���ٸ�С������
һһ�ú�ֽ����ҩ�ĵ�����. ���¼���������ڷּ�ո��չ����Ĳ�ҩ��һ����
�����д����ˡ���������ʱҲ��Сϼ�����ݹ���������
LONG);
    set("exits",([
        "west"   : __DIR__"road6",
    ]));
    set("objects",([
        __DIR__"npc/huoji" : 1,
    ]));
    setup();
}


