//writen by lnwm
//chaimen.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������һ��ũ��СԺ���ſ�,СС�Ĳ��Ž�����,����Ժ���ﾲ����
��.����������֦��ɵ��ſ��ϻ�����һ��������ҵĶ���,ֻ�Ƿ紵��ɹ
ʹ��ֽ�˾�����ɫ,ī��Ҳģ����.�㺰������,û�˴�Ӧ,�������˶�����
��.
LONG
        );
        set("exits", ([ 
            "southeast"     :       __DIR__ "lroad3",
        ]));
        set("item_desc", ([
                "north" : "������֦�����С��,��һ�����ͷ���ѽѽ������\n",
                "��": "������֦�����С��,��һ�����ͷ���ѽѽ������\n",
                "door": "������֦�����С��,��һ�����ͷ���ѽѽ������\n",

        ]) );
        set("outdoors","lnwm");
        setup();
}
void init()
{
        add_action("do_open",({"open", "pull"}) );
}
int valid_leave(object me,string dir)
{
    if( dir == "north" && !this_object()->query("exits/north") )
        write("����һ��С��������.\n");
    return ::valid_leave(me,dir);
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "men" || arg == "door" || arg == "��")
        {
                me = this_player();
                message_vision("$N���������һ��,�ž�֨ѽһ������\n", me);
                if( !query("exits/north") )
                {
                set("exits/north", __DIR__ "yuanluo");
                call_out("close_path", 3);
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
        if( !query("exits/north") ) return;
        message("vision","һ������ᴵ��,С��ѽ��һ���ͺ�����\n",this_object() );
        delete("exits/north");
}


