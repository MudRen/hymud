// �������͵� /d/city/chuzhou/kedian.c
// by lala, 1997-12-04

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", MAG"���͵�"NOR);
    set("long", @LONG
��������վ�ڳ��ݳǶ��ߵ�һ��С��ջ���ҿ�ջ��������ÿ���������
���������ӷ�����������������λ���ĳ������ˣ��������û��ȥ�ٻ��������
����������ĳ�������˵���Ӻ���һ�������Լ��ļ�԰�����ÿ�궼��ɻ�����
��ҿ�ջ�ܸ��˱������ĸо��������������������˶������кܺõ�ӡ��
    �͵�һ¥��Ӧ��ʳ����¥�ṩס�ޡ�
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "south"      : __DIR__"dongshi",
        "up"         : __DIR__"kedian2",
        ]));
    set("objects", ([
        __DIR__"npc/xiaoer1"    :   1,
        __DIR__"npc/keshang"    :   random(3),
    ]));        
    setup();
}
