// /d/heifeng/corr.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���߽���կ�ţ�ֻ�����߷ֱ������һ�����������涼վ��
�ڱ���һ��С������ȥ��
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"gate",
            "north"  : __DIR__"corr02",
            "east"   : __DIR__"sentry1",
            "west"   : __DIR__"sentry2",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

