 inherit ROOM;
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵĻ�Ұ�أ�ƽ̹�ĵ�������һ���������߼ʣ������ϲ�����ɳʯ
���飬һ������·��ֱ������������·�Եĵ�������һ�ԴԵĹ�ľ�Ӳݣ�����ð��
���øߴ����ľ��׺��·�ߵľ�ɫ��
LONG
        );
    set("exits", ([ 
                "west" : __DIR__"road3",
                "east" : __DIR__"road1",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-555);
    set("coor/y",-10);
    set("coor/z",0);
         set("objects", ([
        __DIR__"npc/sadgirl" : 1,
                        ]) );
    
        setup();
        replace_program(ROOM);
}   
