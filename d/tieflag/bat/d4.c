 // Room: /city/milin.c
inherit ROOM; 
void create()
{
        set("short", "�ڰ�ɽ��");
        set("long", @LONG
����һ����ɭ�ɲ����������޹��ɽ����һ�߽������㵹����һ������������
һ����ѣ����ʲôҲ�벻�����ˡ�
LONG
        );
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
        "north" : __FILE__,
        "south" : __DIR__"d5",
        ]));
        set("coor/x",3270);
        set("coor/y",50);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
}  
