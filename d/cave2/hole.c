 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ض�");
        set("long", @LONG
����СС�ĵص���Լ���߰˳ߣ�Ȼ��������Ǹ�СС�Ķ���
���Ҳ����ֻ���߰˳߼��������ⶴ�ȴ�����̺������崲
�ޱ�����������ˮ��һ̳�ƣ���һ������⡢�㳦��Ŵ�׸⣬
�˿̾�Ȼ����ʮ�����顣
LONG
        );
        set("exits", ([ 
                                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_dig", "dig");
} 
int do_dig(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"center");
        message_vision("$N����һ����̳�ӣ��ڵ���ƴ��������������\n",me);
        tell_object(me,"ͻȻ�����һ�죬����ľ�����ѵ���������\n");
        me->move(room);
        return 1;
}     
