// majiu.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
���ǿ�ջ�������ǣ����깩Ӧ���ʲ��ϡ�����ֻҪס�꣬����Ǿ�
�����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ��
�򵽿��������·������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG
        );

	set("outdoors", "houjizhen");

       set("objects", ([
		__DIR__"obj/r_horse" : 2,
		__DIR__"obj/q_horse" : 2,
		__DIR__"npc/mafu" : 1,

        ]));

        set("exits", ([ 
		"north" : __DIR__"shilu1",
        ]));

        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}
