 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
ƫ������һ�����������ȣ�ͨ�����ЪϢ�ķ��䡣�԰������ʮ��ǰ������
���������ڽ����ϵĵ�λ��������������ȡ�����������Ⱥ�����գ��۽��ʣ�
�����쵱���Ľ�ɫ������Ľ�����õģ�������������ﲻ���������õĿͷ���Զ��
�����ġ�
LONG
        );
        set("exits", ([ 
        "east": __DIR__"room1",
        "north": __DIR__"room2",
        "west": __DIR__"corridor",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",-1080);
        set("coor/y",290);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
