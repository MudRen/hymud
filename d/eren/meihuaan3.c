 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "÷����");
        set("long", @LONG
�����һƬ��ɭ��ڣ����������Ҳ�������о����ˡ���������ѳ�����ͭ
�̣��ʹ�����᣺�����ü��Ŀ�ķ��񣬿���Ҳ�����˳��֮�⡣����Ϊ������
�������������������Ϊ������Ĳп�������
LONG
        );
        set("exits", ([ 
                "south": __DIR__"meihuaan2",
        ]));
        set("objects", ([
                __DIR__"npc/liaoyin" : 1,
        ]) );
        set("coor/x",-1300);
        set("coor/y",2050);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}
