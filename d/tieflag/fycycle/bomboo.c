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
        "south" : __DIR__"bomboo1",
        "east"  : __DIR__"bomboo1",
        "north" : __DIR__"bomboo1",
        "west"  : __DIR__"bomboo1",
]));
       set("item_desc", ([
                "����": "һƬ�����ƺ������ƿ���push����\n",
                "bamboo": "������������ҡ�ڣ����ƺ������ۣ�pick������������\n",
                "����": "������������ҡ�ڣ����ƺ������ۣ�pick������������\n",
       ]));
        set("outdoors", "fengyun");
        set("coor/x",-30);
        set("coor/y",200);
        set("coor/z",0); 
        setup();
//        replace_program(ROOM);
}
void init()
{
add_action("do_push","push");
add_action("do_pick","pick");
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
        set("exits/southwest", __DIR__"road3");
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
do_pick(string arg)
{
        object bamboo;
        if ( !arg && arg != "bamboo" && arg != "����" )
                return notify_fail("��Ҫ��ʲô��\n");
        if((int) query("picked") <= 3)
        {
                write("������һ����������ӣ�С�ĵķ��ڻ��\n");
                bamboo = new("/d/taoyuan/obj/bamboo");
                bamboo->move(this_player());
                add("picked",1);
                return 1;
        }
        else
        write("�����Ѿ������۹��ˣ���\n");
        return 1;
} 
void reset()
{
        :: reset();
        delete("picked");
}  