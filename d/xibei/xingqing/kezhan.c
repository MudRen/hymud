//kezhan.c.��ջ
//date:1997.8.28
//by dan

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"�м��ջ"NOR);
        set("long", @LONG
����ջҲ��֪���˶೤ʱ���ˣ���֮�������ʱ�����������ڵش�������
�ģ���ͨ����������ܺ�𡣵�С������æ�������ת��������һЩ����������
����ţ���С������Ϣ����ͨ��ǽ��д��
        С����ֵȼ��ͷ�������һ�����ӵ��������ȣ�������
        �Ա�ɢ��������С��û����Ǯ���ҡ�
                                      ------�м��ջ
LONG
        );
    set("exits", ([ 
                "west"  : __DIR__"road5",
        ]));

        set("objects", ([
                 __DIR__"npc/waiter" : 1,
                ]) );
        setup();
}                       


