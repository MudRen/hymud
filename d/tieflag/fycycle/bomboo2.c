 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һƬ���֡������ܲ�͸�⡣��������һ����ֵ�������������������
�������ţ����Ѿ���������ʱ�ķ����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"bomboo2",
        "east"  : __DIR__"bomboo2",
        "north" : __DIR__"bomboo2",
        "west"  : __DIR__"bomboo2",
]));
        set("item_desc", ([
                "bamboo": "һƬ�����ƺ������ƿ���push����\n",
                "����": "һƬ�����ƺ������ƿ���push����\n",
   ]));
        set("outdoors", "fengyun");
        set("coor/x",-10);
        set("coor/y",240);
        set("coor/z",0); 
        setup();
//        replace_program(ROOM);
}
void init()
{
add_action("do_push","push");
  } 
int do_push(string arg)
{
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "bamboo" || arg == "����")
        {
        me = this_player();
        message_vision("$N�������ƿ�����\n", me);
        me->start_busy(1);
                     if( !query("exits/southwest") ) {
        set("exits/southwest", __DIR__"bomboo1");
        call_out("close_path", 10);
        }
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/southwest") ) return;
        message("vision",
"���ӵ��˻�������ס��ȥ·\n",
                this_object() );
                delete("exits/southwest");
}    
