 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��ʯ·��ͷ");
        set("long", @LONG
��ʯ·����ͻȻ���ж��ˣ�ǰ����һ������׵Ĵ�ӣ�������ģ�
��һ��ʯ��Ҫ���β��л�Ӧ������п������Ƶ���ʯ������������������
�����߸ߣ����߼�����Ͳ��(elevator)���պÿ����ݵ�һ�ˡ� 
LONG
        );
        set("exits", ([ 
       "westup" : __DIR__"court2",
        ]));
        set("objects", ([
                __DIR__"npc/guarda" : 2,
                __DIR__"npc/guarda1" : 1,
        ]) );
        set("item_desc", ([
                "elevator": "���Ͳ���������������õģ�Ҳ���������ȥ��(dash)\n",
                "Ͳ��": "���Ͳ���������������õģ�Ҳ���������ȥ��(dash)\n",
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
        object room, op_room,togo_room;
        object me,guard;
        me = this_player();
        if (guard=present("lieutenant",this_object()))
                return notify_fail("СͷĿ���һ��������ط�Ҳ����ȥ�õ�?��\n");
        if (guard=present("guardian",this_object()))
                return notify_fail(guard->query("name")+"˵��:��ͷ�����ڣ����Ӳ��������ȥ�ġ���\n");
        message_vision("$Nһ���Ӿ�������Ͳ���\n",me);
        op_room = find_object(__DIR__"controlroom");
        if(!objectp(op_room)) 
                op_room = load_object(__DIR__"controlroom");       
        if (op_room->query("elevator")) {
                message_vision("Ͳ�ӻζ��˼�����ͣ��������������ʲô����û��������\n", me);
                return 1;
                }
        togo_room = find_object(__DIR__"palace1");
        if(!objectp(togo_room)) 
                togo_room = load_object(__DIR__"palace1");    
        message_vision(YEL"Ͳ��һ������Ҳ�Ƶ����½�ȥ��\n"NOR,me);
        tell_object(me,YEL"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n"NOR);
        me->move(togo_room);
        return 1;
}       
