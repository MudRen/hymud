 inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
·���������߶���һ���޼ʵ�ׯ�ڵء�˳��·����ǰ�ߣ�������
��ɽ��˳����ȥ������ɽ�����ߣ�Ҳ���Ǻ���ΰ������ɽ����������
�͵Ĳ�ʱ¶��������ɫ���ݶ�������һ�������ĸо���
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"xzroad3",
                "south" : __DIR__"gate",
                "west" : __DIR__"farm1",
                "east" : __DIR__"farm2",
        ]));
        set("NONPC",1);
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-70);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}   
