// ���޷� /d/city/chuzhou/xinluo_fang.c
// by lala, 1997-12-13

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", MAG"���޷�"NOR );
    set("long", @LONG
���޷�������˼���Ǹ�������ס�ĵط���������ʵ���������Ѿ�����������
��������Ӧ�ý����������ġ����Ǵ���Ѿ�ϰ���ˣ����Ǳ㻹��ô�С�����ס��
���������ˣ�Ҳ��Щ������ʹ����������·�����ݣ���Ҳס���������ĸ�
���������кܶ�ܺõĻ����Ҷ�ϲ��������������ͷǳ��������ˡ�    
LONG
    );
    set("exits", ([
        "north"      : __DIR__"xishi",
        ]));
    set("objects", ([
        __DIR__"npc/gaoli_shangren" :   1,
    ]));        
    set( "no_kill",  "yangzhou" );
    setup();
}
