// /d/heifeng/corr06.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
���۵�С·��ɽ���ϣ���Χ����������֮�������һЩ����
ʱ�����ʯͷ��
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr05",
            "north"  : __DIR__"corr07",
//            "east"   : __DIR__"corr04",
            "west"   : __DIR__"restrm",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

