 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ش���");
        set("long", @LONG
���Ǽ伫��ķ��ӣ����������ʽ������ҩ�ݣ�ռ��������ʮ֮��
������ط�������ʮ���߻�¯��¯��㶼�յ�������¯��������
���е���ͭ�����е����ù������е������ι�״��˵�������Ե���
ͭ����ÿһ��ͭ���У�����һ����Ũ�ҵ�ҩ�㴫���� 
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"groad4",
        "north" : __DIR__"chuliuju2",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
