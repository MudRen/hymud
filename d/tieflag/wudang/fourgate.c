 inherit ROOM;
void create()
{
        set("short", "һ���ĵ���");
        set("long", @LONG
����һ����·���ϣ����������ߴ�ɽ�ţ�һ��һ�������¸��죬
��ν����������εڷꡱ����˵��������ʱ�ڴ˶��飬Ԣ����·;��
��ɽ�ţ�Ҫ����������¾��硣
LONG
        );
        set("exits", ([
        "northdown" : __DIR__"sansongting",
                "southup" : __DIR__"jindian",
        ]));
        set("objects", ([
                __DIR__"npc/li1" : 1,
                __DIR__"npc/li2" :1 ,
       ]) );
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-180);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}       
