// /d/heifeng/corr02.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������С·�ϣ���߲�ʱ��ǿ�������������ֵط�������С
��һ��ĺá��������ұ���һ������������Ǳ�������
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr",
            "north"  : __DIR__"corr03",
            "east"   : __DIR__"cookrm",
            "west"   : __DIR__"weaponrm",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

