 inherit ROOM;
void create()
{
        set("short", "ԭʼ����");
        set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�����������
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest5",
                "east" : __DIR__"forest6",
                "west" : __DIR__"forest5",
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1170);
        set("coor/y",-60);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        ::reset();
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest5",
                "east" : __DIR__"forest6",
                "west" : __DIR__"forest5",
        ]));
}    
