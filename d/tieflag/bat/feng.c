 inherit ROOM;
void create()
{
        set("short", "�з�����");
        set("long", @LONG
����һ�����ң���Ȼ���������ûʣ���������ȴ��ʮ�־��µ��壬������һ�����磬
��������һ�ŷ�β�١�����ǽ�Ϲ���һ��������
                        �Ҹ�֪���⣬
                        ����л���� 
LONG
        );
        set("no_beg",1);
        set("no_preach",1);
        set("valid_startroom", 1);
        set("exits", ([ 
  "west" : __DIR__"huashi",
]));
        set("objects", ([
       __DIR__"npc/yuan": 1,
                        ]) ); 
        set("coor/x",3310);
        set("coor/y",30);
        set("coor/z",-20);
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
        if( arg == "����" || arg == "ping feng" || arg == "pingfeng")
        {
        me = this_player();
        message_vision("$N���ְ��������ϣ�����΢΢һ��������Ƭ�̣�����
��Ȼ�����ƿ�����¶��һ�����š� \n", me);
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"secret");
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
        if( !query("exits/south") ) return;
        message("vision","�����������˻�����\n",this_object() );
        delete("exits/south");
}   
