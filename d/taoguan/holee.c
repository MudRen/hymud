#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
ɽʯ����û���֮�������������ǲ����ܵġ�ɽ����
��һ�����ڣ�����ڰ���ʪ����������һ�ֲ���ĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hole3",
]));
        set("item_desc", ([
                "up": "ɽʯ����û�����֮����\n",
                "mountain": "ɽʯ����û�����֮����\n",
                "ɽ": "ɽʯ����û�����֮����\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",80);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
        //add_action("do_climbb", "wantfly");
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
                message_vision(RED "���ã�$Nһ����С�ĵ�����ȥ��\n"NOR , 

me);
                me->move(__DIR__"road5.c");
                me->receive_wound("qi", 50);
                me->receive_wound("jing", 50);
                me->receive_wound("jing", 50);
                return 1;
        }
        else if( arg == "down") {
                message_vision("$N��������ɽ����ȥ��\n", me);
                me->move(__DIR__"ping_tai.c");
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}   

