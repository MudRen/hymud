 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "С��");
        set("long", @LONG
�߳���������ת�����Ӿ͸���ª���ã�������ס�Ĳ��������ˣ����Ǹϳ�ϴ��
�ģ��Ǽ������ϰ����Ļ�ƣ�Ҳס�����һ������ӵĸ��ˣ��������������
���ı��ϱ��Ÿ����ӣ��Ա߻�վ��������һ�����������в�ɫ�����Լ�����ȴ���
㲲��ϵ�������̫�š�
LONG
        );
        set("exits", ([ 
        "northeast" : __DIR__"road5",
        "south" : __DIR__"smallroad2",
        "west": __DIR__"cabin1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",170);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
