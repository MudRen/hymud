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
                "west" : __FILE__,
        "east" : __DIR__"d7",
        "south" : __FILE__,
                "north" : __FILE__,
        ]));
        set("coor/x",3260);
        set("coor/y",40);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
}  
