// xiaoxi.c ׯ��СϪ

inherit ROOM;

void create()
{
        set("short", "��Ϫ��");
        set("long", @LONG
������һ��Ϫ��.
LONG
);

        set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"damen",
        "northeast" : __DIR__"muqiao",
]));

        set( "GATE_ROOM",1 );
        set( "gate_dir",(["southwest" : __DIR__"damen"]) );

        set( "close_look",@LONG
�������һ�ׯ���⡣��������һ������С·�����ĵ���Զ�����죬
�����ϲ�Զ�������������һ�ׯ���ţ���ɫ����ׯ���Ѿ������ˡ�
LONG
);

        set( "gate_name","�һ�ׯ����" );
        set("outdoors","jinghai");
        setup();
        replace_program(ROOM);
}

