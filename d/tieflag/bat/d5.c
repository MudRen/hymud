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
        "west" : __DIR__"d6",
          "east" : __FILE__,
        "south" : __DIR__"dating",
          "north" : __FILE__,
        ]));
        set("coor/x",3270);
        set("coor/y",40);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
} 
