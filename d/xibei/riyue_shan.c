#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","����ɽ");
    set("long",@LONG
����ɽ������У����Ӵ�ɽ���������������н���ެ�ıؾ�֮·�����Ｐ��
ԭ��լ�޸����õ����㣬��ҩ���б���Ϊ����ʥҩ��ѩ��������������·������
ԭ�ġ���������ɽ�����澹��һ��������ޱߴ󺣣���ֻ�е��㿴��ԶԶ��ƽ��
��ǳǳ��ɽӰʱ����֪���ǲ����Ǹ������
LONG);
    set("exits",([
        "eastdown"   : __DIR__"huangshui2",
        "westdown"    : __DIR__"wanniao_lake",
    ]));
    set("outdoors","xibei");
    setup();
}

