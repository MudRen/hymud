 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�߹����κ��ţ������º���ɭɭ��Ʈ���������İ������ɵİ����У�
��ʱ�Ļ����һ����ʯ�ܵĹ����е�ţ�ף��е����棬��������������
�п��������������ľ���Խ��ǰ������ԽŨ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"naibridge",
]));
        set("objects", ([
        __DIR__"obj/judge" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",160);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",-40);
        set("coor/z",20);
        setup();
}
void init()
{
        add_action("do_east", "e");
        add_action("do_east", "east");
}
int do_east(string arg)
{
        object me;
        object room;
   me = this_player();
        message_vision("$N�Ӷ����һ��ɽ�����˽�ȥ��\n", me); 
        room = load_object(__DIR__"windhole");
        if(room) me->move(room);
        
        return 1;
} 
