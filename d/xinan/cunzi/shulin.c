//Writen by lnwm
//shulin.c

inherit ROOM;

void create()
{
    set("short", "С����");
    set("long", @LONG
���ӵľ�ͷ��һ��С���֣�����ʮ��ï�ܣ���ɴ����۾����￴ȥ��
��û�е�·�����ֵĺ�����ǲԴ�ͦ�ε����ɽ���¡������������һ
��ɽ��������С���䡣
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"     :       __DIR__ "lroad5",
    ]));
    
    setup();
    replace_program(ROOM);
}


