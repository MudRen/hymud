// /d/jinghai/moon5.c

inherit ROOM;

void create()
{
        set("short", "����ˮկկ��");
        set("long", @LONG
�ߴ��Բľ��������г����ɶ�ߵ�կǽ�����ȴ�ľ�ų���
�ţ�����վ�������ŵı��䣬�������ࡣΧǽ����������������
�ˣ�����д��[��������կ]�������֡����м������������� [��
��ˮկ��կ]��
LONG
        );

        set("exits", ([
                "south"           : __DIR__"moon6",
                "north"            : __DIR__"moon4",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["north" : __DIR__"moon4"]) );
        set( "close_look",@LONG
����������ˮկկ�š���������ɫ����կ���Ѿ������ˡ�
�����ĵ�ֻ�м���������ˮ���ǻ������վ�����
LONG
);
        set( "gate_name","����ˮկկ��" );
*/

        set("objects",([
        __DIR__"npc/yong1" : 2,
        __DIR__"npc/duizhang" : 1,
]));

        set("outdoors","jinghai");
        setup();
}
