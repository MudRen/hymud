#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","�����");
    set("long",@LONG
ӭ����һƬ�������ߵĺ�ˮ��·�����������ˮ��һƬ�����д����ż���
��ɽ���������ƣ������ɾ�����Զ��һ��С���ϰ�ããһƬ��ϸ��ȥ���Ǵ�Ⱥ��
Ⱥ�ķ������������˷��������ڶ�������Ҳ��������ķ�����ɫ���죬��
С�б𣬽��ǽв������ֵġ�����������ɽ��������һƬƽ����ɽ�زݳ���
LONG);
    set("exits",([
        "eastup"    : __DIR__"riyue_shan",
        "southwest"    : __DIR__"hill_caodi1",
    ]));
    set("outdoors","xibei");
    setup();
}

