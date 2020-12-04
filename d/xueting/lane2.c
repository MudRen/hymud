// Room: /d/snow/lane2.c
inherit ROOM;
void create()
{
        set("short", "Ϫ��С·");
        set("long", @LONG
����������һ�����ӵ���ڣ�����ͨ��һ��Ϫ�ߵ�С·������
��һ�������ݣ�������������������һ��ĥ����ĥ������һ��ˮ��
���ꤵ�ת��������ͨ���������һ��ת�ǡ�
LONG
        );
        set("item_desc", ([ /* sizeof() == 3 */
                "������": "һ��ߴ�����ݣ���ѩͤ��������ɽ��С����ԣ����������Ӳ���
����������������Ǯ�˼ҡ�
",
                "ˮ��": "���ˮ����ĥ����������Դ��ƽ��Ϫˮ����ļ��ھ�ֱ����ˮ����
һ���ﶬ��ˮ���ڣ��͵ù͹����ýŲȡ�
",
                "ĥ��": "һ����ˮ��շ��۵�ĥ����ĥ�������ǹ����ģ����������洫����
�����жϣ�Ӧ���й����������湤����
",
]));
        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"lane1",
                "north" : __DIR__"npath3",
]));
        set("outdoors", "xueting");
        setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
        if( !arg || arg!="ĥ��") return 0;
        message_vision("$N�ƿ�ĥ�����ţ����˽�ȥ��\n", this_player());
        if( this_player()->move(__DIR__"mill") )
                message("vision", this_player()->name() + "�ƿ��Ŵ��������˽�����\n",
                        environment(this_player()), this_player());
        return 1;
}
