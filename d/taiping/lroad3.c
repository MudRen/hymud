 inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
������ɽ��������ʯ���ɵ�·��С���ݺᣬ����ҹɫ�У���ֱ����ͼҲ�ƣ�
��������ׯ԰���˱ط�Ѱ��֮��������������ʯ�׾�����һ�����á������еƻ�
ͨ����������硣
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"village2",
                "south" : __DIR__"lroad2",
        ]));
        set("outdoors", "taiping");
        set("no_fly",1);
        set("item_desc", ([
                    
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
