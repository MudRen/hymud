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
                "south" : __DIR__"bwuroad2",
//                "north" : "/d/fycycle/fyeast",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-15);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
