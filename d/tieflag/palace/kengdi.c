 inherit ROOM;
void create()
{
        set("short", "�ӵ�");
        set("long", @LONG
����һ����ӵĵײ�����������������������Ũ��̧ͷ������������
�ա����¹�Ӱ���أ�Ҳ��֪�����Ǽ١�תĿ�����������������Ǳ�ʯ�߲�ס
��ʯ�ˡ����л��˵���Ӱ������������Լ���˴�Ϣ���������㲻��ë���Ȼ��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"obj/eren" : 1,
                        ]) );  
        set("coor/x",220);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
} 
void init()
{
        add_action("do_open", "touch");
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
        if( arg == "statue" || arg == "������" || arg == "��ʯ�߲�ס�Ķ�����")
        {
        me = this_player();
        message_vision("$N�����������������ְ��˰���ϵ�ʯ��
��ѽ����һ������ӱߵ�ʯ���ϣ����ѿ���һ���Ż���\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"secretpath0");
        if(!me->query("m_success/������"))
        {
                me->set("m_success/������",1);
                me->add("score",300); 
        }
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�����ְ��˰�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"ʯ���ϵ��Ż���������Ϣ�ĺ���������\n",
                this_object() );
                delete("exits/east");
}    
