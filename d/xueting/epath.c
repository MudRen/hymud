// Room: /d/snow/epath.c
inherit ROOM;
void create()
{
        set("short", "Ƨ��С��");
        set("long", @LONG
��������Ƨ����С���ӣ�������Զ��ͨ��ѩͤ��Ĺ㳡��С��
�ı�����һЩ���ݣ�Χ�����߸ߵ�Χǽ����������Ǯ�˵����ӣ���
���м�Сҩ�̣��ſڹ��˺�ЩɹǬ��ҩ�ݣ�С�������Ǹ�ת�ǡ�
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
              "Χǽ": "������ӵ�Χǽ�������൱�ߣ�����������������Ļ���ǿ���Թ�������\n"]));
        set("outdoors","xueting");
        set("exits", ([ /* sizeof() == 3 */
                "east" : __DIR__"lane1",
                "west" : __DIR__"guangchang_e",
                "south" : __DIR__"herbshop",
        ]));
        set("objects", ([
        // __DIR__"master/master-mei" : 1,
        ]) );
        set("outdoors","xueting");
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        if( arg!="Χǽ" ) return 0;
        message_vision("$N��������Χǽ�����˼��·��˹�ȥ��\n", this_player());
        this_player()->move(__DIR__"kitchen");
        message("vision", this_player()->name() + "��Χǽ����һͷ���˹�����\n",
                environment(this_player()), this_player());
        return 1;
}
