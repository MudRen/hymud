 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
������һƬ��ڣ�������Ҷ������������Ҳ������ҹ�����ְ�����������⡣
�ߴ���Ѿ�������衣��ή���ӵİ������ֱ�϶����ɪɪ�����������Ұ���ں���
�������Ƶ������ζ�����ç������չ����������˳��ۣ���צ���ˡ�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"forest1",
                "south":        __DIR__"forest3",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1050);
        set("coor/y",30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
