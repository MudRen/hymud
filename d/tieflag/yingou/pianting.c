 inherit ROOM;
void create()
{
        set("short", "�����ķ�ƫ��");
        set("long", @LONG
�����ǽ�ڷ�ˢ����ѩ��һ������������˹Ž����ҵ��ֻ������ķ�ɽˮ����
�����У�ȴ�Ǹ�����С�仭�ģ����������Ե�Զɽ�����þ������īˮ��һ������
��Щ���ҵĽ���һ�ȣ�ʵ���ǲ�����Ŀ�����˲�����̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dating",
]));
        set("item_desc", ([
                "picture": "����ֻ��ƺ������ƿ�(open)��\n",
                "�ֻ�": "����ֻ��ƺ������ƿ�(open)��\n",
                "ɽˮ": "����ֻ��ƺ������ƿ�(open)��\n",
                "hua": "����ֻ��ƺ������ƿ�(open)��\n", 
        ]) ); 
        set("objects", ([
        __DIR__"npc/leng" : 1,
        __DIR__"npc/fangyufei" : 1,
                        ]) ); 
        set("coor/x",-25);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
}
 
void init()
{
        add_action("do_open", "open");
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
        if( arg == "picture" || arg == "�ֻ�" || arg == "hua")
        {
        me = this_player();
        message_vision("$N����ǽ�ϵ��ֻ���������һ�����š�\n", me);
        if( !query("exits/west") ) {
        set("exits/west", __DIR__"zhoulang");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/west") ) return;
        message("vision",
"ɽˮ�����˻���������ס�˰��š�\n",
                this_object() );
                delete("exits/west");
}       
