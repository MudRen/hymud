// ���ݵ��� /d/city/chuzhou/dangpu.c
// by lala, 1997-12-05

inherit HOCKSHOP;

#include <ansi.h>

void create()
{
    set("short",YEL"����"NOR);
    set("long",@LONG
�����ǳ��ݵĵ��̡�����˳�ü��չ���߽��������ǵ�����Щ�˱���������
��ĳ��ͣ�ƽ������Ե䵱�Ҳ��������Щ��ǰ���û������ķᣬ�����мҲ�
��ᣬȻ��Ǯ������ˮ����������Щ��Ҳ���ò����������ܻ�Ƶ��������ˡ�
LONG);
    set("exits",([
        "east"   : __DIR__"wuhua_jie",
    ]));
    set("dangpu_location","chuzhou");
    set("no_kill", "yangzhou");
    setup();
}
