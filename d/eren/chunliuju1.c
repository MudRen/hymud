 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ش���");
        set("long", @LONG
���Ǽ伫��ķ��ӣ����������ʽ������ҩ�ݣ�ռ��������ʮ֮��������
��������ʮ���߻�¯��¯��㶼�յ�������¯�������ŵ��е���ͭ�����е���������
���е������ι�״��˵�������Ե���ͭ����ÿһ��ͭ���У�����һ����Ũ�ҵ�ҩ��
������
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"groad4",
        "north" : __DIR__"chunliuju2",
        ]));
        set("objects", ([
                __DIR__"npc/chunliu":1,
        ]) );
        set("valid_startroom", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
