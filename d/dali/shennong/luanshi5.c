// ��ʯ�Թ� /d/menpai/shennong/luanshi5.c

inherit ROOM;

string *exit = ({
"north",        "south",        "east",         "west", 
"eastup",       "eastdown",     "westup",       "westdown",
"northup",      "northdown",    "southup",      "southdown",
"northeast",    "northwest",    "southeast",    "southwest", 
});



void create()
{   
    set("short",    "��ʯ��");
    set("long", @LONG
���ﵽ������һ��һ�ѵ���ʯ����ʯ���������ߵĻĲݣ����������˼�������
���������ϸѰ�ҵĻ����ڻĲ���ʯֻ���ƺ�������С���������죬��֪��ͨ
�����
LONG
    );
    set("exits",    ([
        "southwest"                 :   __DIR__"luanshi_hou",
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
    ]) );
    set("outdoors", "wuliang");
    setup();
}

