// /d/heifeng/wuchang.c

inherit ROOM;

void create()
{
        set("short", "ɽ��յ�");
        set("long", @LONG
������һ��յء�������ż���ľ׮���յر��Ϸ��м���ʯ
��ʲô�ġ����������Ǹ���ɽ�Ļ���������Ĳ����š���������
��ר�������õ��䳡��
LONG
        );
        set("exits", ([ 
            "west"   : __DIR__"corr03",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

