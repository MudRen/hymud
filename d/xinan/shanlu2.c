inherit ROOM;


void create()
{
    set("short","ɽ·");
    set("long",@LONG
�������������ϡ������ǰ˰���ƽ���Ĺ���ƽԭ������һֱ�߾Ϳɽ������
LONG);
    set("exits",([  
       "northdown"  : __DIR__"shanlu1",
       "south"       : __DIR__"shanlu3",
    ]));
    setup();
        set("outdoors","xinan");
}
