// /d/heifeng/hell.c

inherit ROOM;

void create()
{
        set("short", "�η�");
        set("long", @LONG
������ɽկ���η���ͨ��������ѺһЩ���ʡ�һ����ͷ����
���������ţ����ﲻͣ���ֹ���ʲô��������һ���ţ����Ϲ���
һ�Ѵ�������
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"corr05",
//            "east"   : __DIR__"corr04",
//            "west"   : __DIR__"hell1",
]));

	set("objects", ([
		"/clone/npc/man" : 3,
	]));
        setup();
        replace_program(ROOM);
}

