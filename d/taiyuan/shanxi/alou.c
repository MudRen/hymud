 inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @long
��֪�������·�Ѿ����˹�����������սս�������ĵ�������������
���ɣ��Ͼ������߹��ˡ�·����ͬ����·��ֻ��������ȥ�߶��ѡ�������
·Ҳ�������ӵġ����ɫ�����Ǳ��ŵģ�����ȴ�и����֡��ơ���
long
        );
        set("exits", ([ 
  //"east" :__DIR__"alou",
  //"east" : __DIR__"yuan1",
  //"west" : __DIR__"shulin1",
  "west" : __DIR__"tolou5",
  
]));
        set("item_desc", ([
                "door": "����ʲ�������ţ������Ƶÿ��ģ�Ҳֻ����ϲ���ȥ�ƣ��Ҳ���ȥ�ƶ���(push)��\n",
                "��" : "����ʲ�������ţ������Ƶÿ��ģ�Ҳֻ����ϲ���ȥ�ƣ��Ҳ���ȥ�ƶ���(push)��\n",
                "���ɫ����" :"����ʲ�������ţ������Ƶÿ��ģ�Ҳֻ����ϲ���ȥ�ƣ��Ҳ���ȥ�ƶ���(push)��\n"
        ]) );

        set("outdoors", "shanxi");
        set("coor/x",-480);
        set("coor/y",-260);
        set("coor/z",100);
        setup();
}
void init()
{
        add_action("do_push", "push");
}
void close_path()
{
        if( !query("exits/enter") ) return;
        message("vision",
        "�ź�Ȼ���˹��ϡ�\n",
                this_object() );
                delete("exits/enter");
}  
int do_push(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="door" || arg =="���ɫ����" || arg=="��") {
                write("����������˿�����������ȥ���š�\n");
        if( random(100) >= 10 )
                {
                write("��һ�¾ͱ��ƿ��ˡ�\n");
                if( !query("exits/enter") ) {
                set("exits/enter", __DIR__"alou2");
                call_out("close_path", 10);
                                                }
                return 1;       
                }
                else
                write("��ͻȻ�򿪣�һ��ţâ�Ƶĺ���ӭ�����������֮�䣬��Ȼ���������ڡ�\n");
                me->receive_damage("qi",500);
                me->start_busy(3);
                return 1;
        }
                write("��Ҫ�ƿ�ʲô��\n");
                return 1;
} 
   