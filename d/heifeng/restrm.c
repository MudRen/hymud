// /d/heifeng/restrm.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
������ǿ������Ϣ�ĵط�������������ŷ�������ľ������
����ǿ�����Ǻ�����˯�ţ����Ǹ�ֵ��ҹ�ࡣ
LONG
        );
        set("exits", ([ 
//            "north"  : __DIR__"corr05",
            "east"   : __DIR__"corr06",
//            "west"   : __DIR__"hell1",
]));
        setup();
        replace_program(ROOM);
}

