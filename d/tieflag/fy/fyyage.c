#include <room.h>
 inherit ROOM;
void close_path();
void create()
{
        set("short", "�����Ÿ�");
        set("long", @LONG
����ר���д���������������������������������ģ�����һ��ǧ��ĺ�
�ͣ����Ƕ��Ž����Ĳ���һ�����������䷿�ӵ�����ֻ��һ���ϵȴ����ĥ�ɵ�
�����������Ϸ�����ֻ���ͽ𱭡������ǽ�Ϲ������ֻ���ʣ�µ�һ����һ��һ��
���صĺ첼������
LONG
        );
        set("exits", ([
                "down" : __DIR__"fyge",
                "east" : __DIR__"fysf",
        ]));
        set("objects", ([
                __DIR__"npc/servent": 1,
        ]) );
        set("item_desc", ([
                "curtain": "����첼�����ƺ������ƿ�(open)��\n",
                "����" : "����첼�����ƺ������ƿ�(open)��\n",
                "�첼����" : "����첼�����ƺ������ƿ�(open)��\n"
        ]) );
        set("NONPC",1);
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",10);
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",10);
        setup();
//        create_door("east", "ľ��", "west", DOOR_CLOSED); 
} 
void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"�첼������������������ס�˰��š�\n",
                this_object() );
                delete("exits/north");
}  
int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="curtain" || arg =="�첼����" || arg=="����") {
                write("���ƿ��첼������");
        if( (int) me->query("jiali") >= 100 )
                {
                write("�ƿ��˺����򱱵�һ�Ȱ��š�\n");
                if( !query("exits/west") ) {
                set("exits/north", __DIR__"fysecret");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("���������ƺ���İ��ţ���û���ƿ���\n");
                return 1;
        }
                write("��Ҫ�ƿ�ʲô��\n");
                return 1;
} 
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "north" && ob=present("royal servant", this_object()))
        {
        message_vision("$N��$n�ȵ������ȥ����������˵����\n", ob,me);
        ob->kill_ob(me);
        return notify_fail("���ӣ�\n");
        }
        else
                return 1;
}   
