 inherit ROOM;
void create()
{
        set("short", "ԭʼ����");
        set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�������������Ҷ��ʪ�ģ���
��Ҳ��ʪ�ġ�һ���˵�����Ҷʪ���У�ȫ������ʹ���Ť����
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest6",
                "south" : __DIR__"forest2",
                "east" : __DIR__"forest3",
                "west" : __DIR__"forest1",
        ]));
        set("objects", ([
                __DIR__"npc/gudumei" : 1,
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1150);
        set("coor/y",-50);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        object room, gudu; 
        ::reset();
        set("exits", ([
                "north" : __DIR__"forest6",
                "south" : __DIR__"forest2",
                "east" : __DIR__"forest3",
                "west" : __DIR__"forest1",
        ]));    
        room = this_object();
        if(!objectp(present("gu du mei", room))){
                gudu = new(__DIR__"npc/gudumei");
                gudu->move(room);
        }
}  
