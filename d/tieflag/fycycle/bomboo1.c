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
        set("coor/x",-20);
        set("coor/y",220);
        set("coor/z",0); 
        setup();
}
void init()
{
        add_action("do_push","push");
  } 
int do_push(string arg)
{
    object me;
    if(!arg || arg==""){
        write("��Ҫ��ʲô��\n");
        return 1;
    }
    if( arg == "bamboo" || arg == "����"){
            me = this_player();
             
            me->start_busy(1);
       if(me->query("marks/÷ɽ��") && !query("exits/northeast")) {
                message_vision("$N�������������ܲ쿴��һ�����������ƿ����ӡ�\n", me);
                set("exits/northeast", __DIR__"meilin");
                call_out("close_path", 5);
            } else if( !query("exits/southwest") ) {
                    message_vision("$N���淽������������ƿ����ӡ�\n", me);
                    set("exits/southwest", __DIR__"bomboo");
                    call_out("close_path", 10);
        }
        return 1;
    } else {
        write("�㲻������"+arg+"\n");
        return 1;
    }
}
void close_path()
{
    if( query("exits/southwest") ) {
            message("vision", "���ӵ��˻�������ס��ȥ·\n", this_object() );
        delete("exits/southwest");
        } else if( query("exits/northeast") ) {
                message("vision", "���ӵ��˻�������ס��ȥ·\n", this_object() );
                delete("exits/northeast");
        }
}      
