 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ּ�");
        set("long", @LONG
���ֲ���Ũ�ܣ�������������~��ƬƬ���ϣ��׺��]��б���ģ��������f����
�ˡ���Ƥ�⻬�����yɫ�ĕ�Ȧ��΢΢��������ɫ���������Ȼ������С���ӡ���
���ϰ���Щֽ��ֽ������һ��ֽ�����ð�ֽ���ɵĵ���������ȴͿ���˺�ɫ��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"woods",
                "south" : __DIR__"woodcabin",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
