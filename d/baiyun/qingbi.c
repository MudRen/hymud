 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
Խ���ٲ�����Ȼ���ж��죬����ȥֻ�Ǹ�����խ��ɽ�죬��ͷһ��С�ı���
ʯ����ײ�����������˲�֪���ĵͰ���ľ����һ���������ܵ�ʯ���ϣ��������龡
�����̵����ܡ�
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"tengluoxi2",
       "south" : __DIR__"longqiu",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
