 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ԭ");
        set("long", @LONG
�����������ɳ�����ޱ��޼ʵĻ�ԭ�������������ٽ�С�������ĳ����
�ˣ�̤��һ�����߿�ĳ��������ĵ��������ǳ��޻����ĺۼ���ż����ƥ�����
��������ǰ�����������߽�����ɫ�Ҵң��糾���ͣ�����Ĺ����ң��Լ���Я�ű�
�У��ܹİ��������ת˲���š�
LONG
        );
        set("exits", ([ 
        "southeast" : __DIR__"wild2",
        "west" : __DIR__"road2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
