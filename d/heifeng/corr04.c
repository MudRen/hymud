// /d/heifeng/corr04.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ����̤������С·�����Գ��ż�������������һЩ����ֲ
�������Χ��
LONG
        );
        set("exits", ([ 
//            "south"  : __DIR__"corr",
//            "north"  : __DIR__"corr03",
            "east"   : __DIR__"corr03",
            "west"   : __DIR__"corr05",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

