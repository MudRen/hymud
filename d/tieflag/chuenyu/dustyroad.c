 // Room: /d/chuenyu/dustyroad.c
inherit ROOM; 
void create()
{
        set("short", "���С·");
        set("long", @LONG
����һ����С��ͨ�����Ļ���С·������С�򼸺��������ˡ�
������һ���޼ʵ�ƽԭ��һ����������ɽ��������������֡�
���߼���������һ������ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dustyroad0",
  "north" : __DIR__"dustyroad2",
]));
        set("outdoors", "chuenyu");
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) ); 
        set("coor/x",100);
        set("coor/y",110);
        set("coor/z",0);
        set("coor/x",100);
        set("coor/y",110);
        set("coor/z",0);
        setup();
}     
