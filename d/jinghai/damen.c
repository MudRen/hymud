// yuanmen ׯԺ����

inherit ROOM;
void create()
{
        set("short", "ׯԺ����");
        set("long", @LONG
һ����ǽ��Ժ,��������. �����ϸ����ŵ������,����
��������[�һ�ׯ]��Ժǽ���������������������ǰ��ɨ�ĸ�
�ɾ�����������������һ������С·��֪��ͬ��ʲô�ط�����
����Ҫ�Լ�ȥ������·�ˣ�
LONG
        );

        set("exits", ([
                "south"           : __DIR__"dating",
                "west"            : __DIR__"qianyuan",
                "northeast"            : __DIR__"xiaoxi",
]));
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["northeast" : __DIR__"xiaoxi"]) );
        set( "close_look",@LONG
�������һ�ׯ���š���������ɫ����ׯ���Ѿ������ˡ�
�����ĵ�ֻ�������ļҶ��ǻ������վ�����
LONG
);
        set( "gate_name","ɽׯ����" );


        set("objects",([
        __DIR__"npc/jiading" : 2,
]));

        set("outdoors","jinghai");
        setup();
}

