 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ת��һ���ʯ����ǰ��Ȼһ����ˮ����������������ͷ�����ش�������
����Ҷ��ھ�Ȼ����һ�����ٲ��С�������ȥ��������Ȫ������ʮ���ɸߣ���
��֮�⣬���޳�·��
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"exit3",
                        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_dive", "dive");
        add_action("do_climb", "climb");
} 
int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object("/d/eren/waterfall.c");
        message_vision("$N�������˿�����һ���ۣ����ٲ�����ȥ��\n",me);
        tell_object(me,"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n");
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
        if( arg == "ɽ" || arg == "mountain" || arg == "down")
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
