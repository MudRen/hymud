 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ع�ַ");
        set("long", @LONG
���ع�ַλ�����Ź����ϣ�������Ϊ�����ʳơ����ء�������ԭ������½·��
ͨ�ʺ�֮�أ�Ҳ�ǡ�˿��֮·����·�ؾ��Ĺذ����ųǹض���Ϊũ�Զ�����ٲ�
�Ƿ�ַ������ɳ��ɳ����������ɳãã��һ���޼ʡ�����ն�ɽ����һ�������ݣ�
�����ϱ�������������Ȫˮ�丣���Ϊ������
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"yangguan1",
        "east" : "/d/loulan/yangguan",
        "north" : __DIR__"oasis",
        ]));
        set("objects", ([
                __DIR__"obj/y-bei": 1,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-960);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
