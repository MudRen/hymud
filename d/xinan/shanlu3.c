inherit ROOM;



void create()
{
    set("short","ɽ·");
    set("long",@LONG
�������������ϡ������ǰ˰���ƽ���Ĺ���ƽԭ������һֱ�߾Ϳɽ������
LONG);
    set("exits",([  
       "north"  : __DIR__"shanlu2",
       "southup"       : __DIR__"yangping_guan",
    ]));
    setup();
        //place_program(ROOM);
}
