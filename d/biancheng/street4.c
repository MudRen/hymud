 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�Ͻ־�ͷ");
        set("long", @LONG
���ϵ�С�ֺܿ�͵��˾�ͷ������ǰ���ǻ�ԭ���ޱ��޼ʵĻ�ԭ�����������
���ɳ��һ��о��ڷ�ɳ�д��Ź����Ȳ�֪�Ǵ����ﴵ���ģ�Ҳ��֪Ҫ����������
ȥ���������Ҳ���������о�һ��������˭��Ԥ֪�Լ������ˣ�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"zahuopu",
                "north": __DIR__"street3",
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
