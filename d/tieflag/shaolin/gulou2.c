 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
��¥����������С�������ɸߴ��ޱȣ������йű��������У�����
һ������Ħһέ�ɽ�ͼ���ر𾫲ʣ���Ħ����֮έ����һ����Ҷ������
����һ����������Ϊ���ɡ�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"gulou3",
  "down" : __DIR__"gulou",
]));
        set("objects", ([
                __DIR__"npc/monk3" : 1,
       ]) );
        set("coor/x",-220);
        set("coor/y",200);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}       
