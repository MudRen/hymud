// Room: /d/jinghai/moon4.c

inherit ROOM;

void create()
{
	set("short", "ɽկ��ǰ�Ŀյ�");
	set("long", @LONG
������һ�����Ϊ�����յء��տտ���ʲô��û�С�������
һ��ɽկ����, ԲľΧǽһֱ������ɽ�Դ������ų��������Է�
����һ��ͷ����ͷ���ֳֵָ��ı��£��������ޱ���ı�ֱ��վ
�����������һ����·������ɽ�Ծ�ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"moon3",
  "south" : __DIR__"moon5",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["south" : __DIR__"moon5"]) );

        set( "close_look",@LONG
����������ˮկ���⡣��������һ������С·�����ĵ���Զ
�����죬�����ϱ߲�Զ����������ˮկկ�š���ʱ����ɫ����
ׯ���Ѿ������ˡ�
LONG
);

        set( "gate_name","����ˮկկ��" );
*/
        set("outdoors","jinghai");


	setup();
	replace_program(ROOM);
}
