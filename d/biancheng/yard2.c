 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "Ժ��");
        set("long", @LONG
һƬ��Ŀճ���������ũ���ķ��ݣ�������ׯ����լ�ӣ�լ�ӵ�����������һ
��߸ߵ�԰ǽ��ǽ����һ��һ�ŵķ�ï�İ�ɼ���м���һ�����ֱ·��˳������·
�߹�ȥ������Խ��������õ���������Զ�����������ޱ��޼ʵĲݳ���
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"hall1",
        "west": __DIR__"stable1",
        "south": __DIR__"yard",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1110);
        set("coor/y",280);
        set("coor/z",0);
        set("end",1);
        setup();
        replace_program(ROOM);
}      
