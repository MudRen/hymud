// �����ӻ��� /d/city/chuzhou/zahuopu.c
// by lala, 1997-12-10

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short",YEL"�ӻ���"NOR);
    set("long",@LONG
һ������ͨͨ���ӻ��̣����۾����ճ�����ĸ����ӻ���Ʒ���󲻹���ͷ��
�£�С����ͷ���ԡ����ڵش���λ�ò��Ǻܺ���������Ҳ��һ�㣬������ʲô
�˿ͽ������������ӵ��ϰ�Ҳ����������ͨͨ�������������Ǿ����ƺ���Щʲ
ô�����Եúܱ�Ť�������ͷ��
LONG);
    set("exits",([
        "north" : __DIR__"dongshi",
    ]));
    set("objects",([
        __DIR__"npc/shopboss"   :   1,
    ]));        
    set("no_kill", "yangzhou");
    setup();
}
