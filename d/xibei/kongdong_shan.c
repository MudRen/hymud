inherit ROOM;
void create()
{
    set("short","���ɽ��");
    set("long",@LONG
���ɽ������ʱ������ڴ��������ɶ�������ɽ�����������ʤ����������
�����Ǹ������ĺ�ȥ����
LONG);
    set("exits",([
        "south"  : __DIR__"shanlu1",
        "north" : __DIR__"kongdong/fengkou",
    ]));
set("outdoors","xibei");
    setup();
}

