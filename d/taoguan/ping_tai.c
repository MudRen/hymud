 inherit ROOM;
void create()
{
        set("short", "ƽ̨");
        set("long", @LONG
��������һ��СС��ƽ̨�����������������Ϣ��
LONG
        );
        set("item_desc", ([
                "up": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
                "mountain": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
                "ɽ": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",70);
        setup();
} 
void init()
{
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        me = this_player();
        if( arg == "up" || arg == "ɽ" || arg == "mountain")
        {
                message_vision("$N��������ɽ����ȥ��\n", me);
                me->move(__DIR__"hole.c");
                return 1;
        }
        else if( arg == "down") {
           message_vision("$N��������ɽ����ȥ��\n", me);
                me->move(__DIR__"road5.c");
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}       
