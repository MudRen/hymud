 // Room: /d/chuenyu/dustyroad.c
inherit ROOM; 
void create()
{
        set("short", "���С·");
        set("long", @LONG
����һ����С��ͨ�����Ļ���С·��������С��Ľ��⣬���ƺ���
����������С����������������������һ���޼ʵ�ƽԭ��һ��������
��ɽ��������������֡�
LONG
        );
        set("exits", ([ 
  "southwest" : "/d/tieflag/palace/palace_path1",
  "north" : __DIR__"dustyroad.c",
]));
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) );
        set("outdoors", "chuenyu"); 
        set("coor/x",100);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
