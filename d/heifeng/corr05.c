// /d/heifeng/corr05.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������·�Ĺսǣ�·�߳�������ɫ�Ĺ���ֲ���·ʱ��Ҫ
С�ģ���Ҫ���������ֽš�����������վ�ڵ����ˣ���֪��ʲô
��Ҫ�ط���
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"hell",
            "north"  : __DIR__"corr06",
            "east"   : __DIR__"corr04",
//            "west"   : __DIR__"corr05",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

