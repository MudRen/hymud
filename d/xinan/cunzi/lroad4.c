//Writen by lnwm
//lroad4.c

inherit ROOM;

void create()
{
    set("short", "С��·");
    set("long", @LONG
���ߵ��˴��ӵ����ģ��������������������ֵĵط���������һ��С
���������һ��ũ�ᡣ���˰����չ��Ժ󣬴����ǻ����������ۼ�����
��ڰ���������Ҳ������һ������ֵ�ʱ�⡣
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"         :       __DIR__ "lroad2",
        "north"         :       __DIR__ "lroad5",
        "east"          :       __DIR__ "caopeng",
        "west"          :       __DIR__ "nongjia2",              
                ]));
    set("objects",([
                __DIR__ "npc/yunyou" : 1,
                  ])
    );  
    setup();
    replace_program(ROOM);
}


