//Writen by lnwm
//lroad2.c

inherit ROOM;

void create()
{
    set("short", "С��·");
    set("long", @LONG
�㴩�����֣�������һ��С���ӣ������Ĵ�ɽ�������С���ӣ���
�������ɽ�ĺ�ɽ��ƫƧ���ľ���������һƬ���֣����������ɽ�ĺ�ɽ
������һ��С·��ͨ��һ��ũ�ҡ�
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"         :       __DIR__ "lroad1",
        "northwest"     :       __DIR__ "lroad3",
        "north"         :       __DIR__ "lroad4",    
        "northeast"     :       __DIR__ "zhulin",              
                ]));
    set("objects",([
                __DIR__ "npc/girl" : 1,
                  ])                  
    );
    setup();
    replace_program(ROOM);
}


