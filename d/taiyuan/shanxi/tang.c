#include <room.h>
inherit ROOM;
void close_path();
void create()
{
        set("short", "����");
        set("long", @long
һƬ�ɰ��쾰ӳ���������򵥵��ţ�û�з������ε���ơ������м���һ
���Ϻõ����ݹ�ľ���᷽���˿�ײ�������ǰ������һ�������������Ҳ��ǳ�
����ɰأ���������ں����м��̲��ε�÷���������֡�ʾ��¶��ʹ������
�������Ķ����ա����������Խ�վ������缫�����硣
long
        );
        set("exits", ([
               // "down" : __DIR__"fyge",
                "south" : __DIR__"hyuan",
        ]));
        set("objects", ([
                __DIR__"npc/tianqing": 1,
        ]) );
        set("item_desc", ([
                "curtain": "����ײ������ƺ��ɴ�(open)��\n",
                "����" : "����ײ������ƺ��ɴ�(open)��\n",
                "�ײ�����" : "����ײ������ƺ��ɴ�(open)��\n"
        ]) );
        //set("NONPC",1);
set("coor/x",-500);
        set("coor/y",-320);
        set("coor/z",100);
        setup();
//        create_door("east", "    ", "west", DOOR_CLOSED); 
} 
void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/north") ) return;

        message("vision",
               "�ײ�����������������������ǰ��\n",
                this_object() );
                delete("exits/north");
}  
int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="curtain" || arg =="�ײ�����" || arg=="����") {
                write("���ƿ��ײ�������");
        if( (int) me->query("neili") >= 1000 )
                {
                write("�����ƿ���ľ�š�\n");
                if( !query("exits/west") ) {
                set("exits/north", __DIR__"tolou1");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("�������ţ�������˿������\n");
                return 1;
        }
                write("��Ҫ��ɶ��\n");
                return 1;
} 
/*int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "north" && ob=present("huo tianqing", this_object()))
        {
        message_vision("$N��$n�ȵ���  ��  ��      �������  ��    ����\n", ob,me);
        ob->kill_ob(me);
        //return notify_fail("��  ��\n");
        }
        else
                return 1;

} */  
