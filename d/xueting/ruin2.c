// Room: /d/snow/ruin2.c
inherit ROOM;
void create()
{
        set("short", "�ƾɴ�լ����");
        set("long", @LONG
������һ���ƾɴ�լ�������������ǽ�ڸ��ݶ��Ѿ�����̮��
�ˣ����쬵����ӱ��ߵ�ȱ��ֱ��������������������ǣ���
����ɨ���൱���࣬������Ǭ���������������һ�����̣�˵����
�˺�����������ȴҲ��������������ᰮ��������˺���������
����������ס�������ĳ��ڡ�
LONG
        );
       set("item_desc", ([ /* sizeof() == 3 */
                "����": "һ���ִ�������������������õ�ס�������ĳ��ڡ�
",
                "����": "һ����Ǭ���̳ɵĴ��̣���Ȼ��ª������ȴǬǬ���������㿿����
ʱ�򾹻��ŵ�һ�ɵ�����֬��������
",
                "ȱ��": "��ȱ��������ȥ��ֻ����լ���������ݶ��Ѿ���Ϊ�������ˣ����
�����ȥ����ǿ���Դ�ȱ������ȥ��
",
]));
        set("exits", ([
                "north": __DIR__"riverbank",
                "east" : __DIR__"ruin3",
        ]));
        set("objects", ([
               // __DIR__"master/master-yang" : 1
        ]) );
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        if( arg == "����" )
        message_vision("$N��������������������լ��ǰԺ��ȥ��\n", this_player());
        this_player()->move(__DIR__"ruin1");
        message("vision", this_player()->name() + "�ӵ�����������һͷ���˳�����\n",
                environment(this_player()), this_player());
        return 1;
}
