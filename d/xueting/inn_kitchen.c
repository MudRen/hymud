// Room: /d/snow/inn_kitchen.c
inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
������һ����ĳ�����һ������ռ���˶��߰��ǽ�ڣ��ϱ�
�Ĺ�����������ط���������ư�裬����ƽ�����൱æµ�ģ���
����Ҫ�����ﶫ�������Ļ������С�ı𱻵�С����������������
���ˣ��������Իص���ջ�
LONG
        );
 set("item_desc", ([
                "����": "��Щ������ŵ��Ǹ������õ����̵��꣬���ű���װ�ڼ��������\n"
                                 "����ӵ��Ŷ����ˣ����Ƿ���ȡ�á�\n",
                "����": "һ��ȼ��������̿��Ĵ����ڿ�������һ����������ȥ������\n"
                                 "����̿���յ����ȣ���Ȼ�������˸�����ɵ�¡�\n"
        ]));
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"inn",
        ]));
        setup();
}
void init()
{
        add_action("do_enter", ({"enter", "climb"}));
}
        
int do_enter(string arg)
{
        if( arg != "����" ) return 0;
        message_vision("$Nһ����, �Ӵ����������˽�ȥ.\n", this_player());
        if( this_player()->move(__DIR__"fireplace") )
                message("vision", this_player()->name() + "���������˽���, ���㼷��һ��.\n",
                        environment(this_player()), this_player());
        return 1;
}       
