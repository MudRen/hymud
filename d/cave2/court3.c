 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "����");
        set("long", @LONG
һ�������Ƶ���ʯ������������������������(huache)�� 
����ͨ��һ���������ɽ���� 
LONG
        );
        set("exits", ([ 
       "west" : __DIR__"court2",
        ]));
        set("item_desc", ([
                "huache": @TEXT
�ƺ�������(dash)��ȥ,������...
TEXT
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_dash", "dash");
} 
int do_dash(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"palace1");
        message_vision("$Nһ���Ӿ������˻�����\n",me);
        tell_object(me,"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n");
        me->move(room);
        return 1;
}        
