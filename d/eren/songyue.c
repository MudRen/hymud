 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������");
        set("long", @LONG
�����½�������ڱ�κ��ƽԪ��������Ԫ�꣬ԭ���о��£������Ǳ�κ����
��һ���빬����Ľ�Ϊ���¡�����������������������Ϊ��������ʽש�����ɻ�
̨���������ܺ���ɲ�����ֹ��ɣ�ȫ������ʮ����ʨ�ӣ��������ԣ�������죬
�����۽�������������ǽ��Ρ��׳����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"shike",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}         
