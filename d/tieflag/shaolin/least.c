 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ظ���");
        set("long", @LONG
��ľ���ȣ��ϵ�ɷ������������·�����ޱȣ�·���д��һ��
��һǧһ�ٽ����������ÿ���������㹻ȫ��ʳ�ã����������
�˹��в����㣬������ڴˣ����������档
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"changjing",
]));
        set("objects", ([
                __DIR__"obj/daguo" : 1,
       ]) );
        set("coor/x",-200);
        set("coor/y",230);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
} 
