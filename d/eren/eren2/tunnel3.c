 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����խ�Ŀ׵������������ɣ��ռ��𽥿����������ܵ���̦������
Ҳïʢ������ԶԶ���ƺ���������˵�����������ٹ����ɣ����Գ��˰�����
����һ��СС������֮�С����¿�ȥ���������ɶ�ߡ�Ҳ�������˾��ţ�
���������ʼ������ɧ��������
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"tunnel2",
        ]));
        set("objects", ([
                __DIR__"npc/bat" : 3,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_jump", "jump");
        add_action("do_climb", "climb");
        add_action("do_jump", "jumpto");
        add_action("do_jump", "jumpdown");
} 
int do_jump(string arg)
{
        object room;
        object me;
        me = this_player();
        room = find_object(__DIR__"court1");
        if(!objectp(room)) 
                room = load_object(__DIR__"court1");   
        message_vision("$N�������˿�����һ����������ȥ��\n",me);
        me->move(room);
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "��" || arg == "down")
        {
                write("����ط�̫�գ����������ȥ��\n");
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}   
