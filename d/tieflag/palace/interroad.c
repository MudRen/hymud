 inherit ROOM;
void create()
{
        set("short", "��·��");
        set("long", @LONG
������ߣ�ǰ����������ɽ�ߡ�һ����ǰ��һ�����ҡ�һ�߾��ӹ�ĸ
��ʯ����������·�䡣�Ÿ�ʯ�ܵ�Ӥ�����������������ϣ��е��ֳ���
�̣��е��ֳ�������ʯ�����֮���棬�����ǹ��񹤡�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"firehole",
  "west" : __DIR__"windhole",
]));
        set("objects", ([
        __DIR__"obj/stonejudge" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",180);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",180);
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
        room = load_object(__DIR__"realhole");
        if(room) me->move(room);
        
   return 1;
}   
