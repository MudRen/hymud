 inherit ROOM;
void create()
{
        set("short", "�ֵ�");
        set("long", @LONG
����ʯ���̳ɵĵ�·����ɨ�ø�Ǭ����������Сͯ�ڽֵ��ϻ���
׷����ˣ���ֵ������Ǻ�ש���ɵķ��ݣ���Զ������ңң����һ����
��ܸߵ���ɫɽ��...
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"xzroad3",
//        "southeast" : "/d/bawang/shanlu",
//        "east" : "/d/bawang/mantoudian",
        ]));
        set("outdoors", "wudangfy");
    set("coor/x",160);
    set("coor/y",-100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
