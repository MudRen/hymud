 inherit ROOM;
void create()
{
        set("short", "ׯ�ڵ�");
        set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭����
���㣬��������֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,
������Ȼ���¡� 
LONG
        );
        set("exits", ([
                "north" : __DIR__"farm1",
                "south" : __DIR__"farm5",
                "east" : __DIR__"farm7",
                "west" : __DIR__"farm5",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",70);
        set("coor/y",-80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
