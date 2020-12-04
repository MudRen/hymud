 inherit ROOM;
void create()
{
        set("short", "��С��");
        set("long", @LONG
һ������ǡ�˲���ɽ�п�����Է�̤����С�����������������
ɽ����չ�����Ե�é�ݸߴ���ߣ���ס����⡣ɽ���е�һ�ж��Ե���
ɭ�İ��������é��(grass)�ƺ����ܸ����ˡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad3",
  "north" : __DIR__"smallroad2",
]));
        set("objects", ([
                __DIR__"npc/woodcutter" :2,
        ]) ); 
        set("item_desc", ([
                "grass": "�����é��(grass)���ܣ������ƺ����Բ���(pushaside)���ǡ�\n",
                "é��": "�����é��(grass)���ܣ������ƺ����Բ���(pushaside)���ǡ�\n" 
        ]) ); 
        set("outdoors", "resort");
        set("coor/x",-1190);
        set("coor/y",30);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_push", "pushaside");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "grass" || arg == "é��" || arg == "��")
        {
        me = this_player();
        message_vision("$N����·�ߵ�é�ݣ�������һ��������·��\n", me);
        if(!me->query("m_success/��ѩ"))
        {
                me->set("m_success/��ѩ",1);
                me->add("score",70); 
        }
        if( !query("exits/west") ) {
        set("exits/west", __DIR__"secret_road");
        call_out("close_path", 5);
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
        if( !query("exits/west") ) return;
        message("vision",
"һ��紵����é�ݻ��˻Σ�����û��������·��\n",
                this_object() );
                delete("exits/west");
}    
