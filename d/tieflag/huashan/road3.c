 inherit ROOM;
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵĻ�Ұ�أ�����������΢�������·�ߵ��Ӳ�͸�Ż���ɫ����ʱ
������ɴصĸߴ���ľ������·�ߣ�����·����������ת��һ���䣬ת�䴦��·��
��һ�����ҵ�ש�߶ѡ�
LONG
        );
    set("exits", ([ 
                "south" : __DIR__"road4",
                "east" : __DIR__"road2",
        ]));
        set("objects", ([
                __DIR__"obj/brick" : 1,
        ]));   
    set("outdoors", "huashanfy"); 
    set("coor/x",-560);
    set("coor/y",-10);
    set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
