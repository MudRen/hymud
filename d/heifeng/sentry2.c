// /d/heifeng/sentry2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ����Լ���˸ߵ����������������ǰ�����ϵ��ڱ����ص�
Ѳ���š��������������֣�ȴ�ò����κ���Ӧ��
LONG
        );
        set("exits", ([ 
            "east"   : __DIR__"corr",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

