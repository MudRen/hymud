// /d/heifeng/corr03.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��·��ÿ�Щ�ˡ�һ������ͨ����һ������ӡ���������
�߲�ʱ����һ�����������������������������ǲ���С·��
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr02",
            "north"  : __DIR__"heifengrm",
            "east"   : __DIR__"wuchang",
            "west"   : __DIR__"corr04",
]));
        set("outdoors", "heifeng");

	set("objects",([
	__DIR__"npc/xunzhai" : 2,
        __DIR__"npc/cleaner" : 1,
]));

        setup();
        replace_program(ROOM);
}

