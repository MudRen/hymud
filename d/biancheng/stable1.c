 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
��ǰ��һ������ں����в�ͣ�ķ���������������ҶһƬƬ��������������
�ŵ���ǧ��ѡһ���������������ϼ������ס��С�ݣ����ɼ�����������һ��
������������ޣ�����ȣ��������м���С����
LONG
        );
        set("exits", ([ 
        "east": __DIR__"yard2",
        "north": __DIR__"stable2",
        ]));
        set("objects", ([
                __DIR__"npc/jiaolaoda": 1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",280);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
