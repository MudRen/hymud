 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���·ת��һƬ����������ǰ��������ľï�ܣ�һƬ���̡����²��ߣ��±�֮
�����ٽ����ܲ�͸�磬һ��ˮ����������˿������Ʈ�䣬ˮ���ɽ��ڹ�����Ҷ֮
�ϣ����������ҫ���������⣬����ҹ���µ��ǳ���
LONG
        );
    set("exits", ([ 
                "eastup" : __DIR__"yanluo",
        "northwest" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                __DIR__"obj/vine1" : 1, 
                __DIR__"npc/xian": 1,
        ]));   
    set("outdoors", "huashanfy"); 
    set("coor/x",-620);
    set("coor/y",-100);
    set("coor/z",76);
        setup();
    replace_program(ROOM);
}   
