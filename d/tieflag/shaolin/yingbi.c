 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Ӱ��");
        set("long", @LONG
ɽ�Ž�����һ��ʯӰ����ס��������ߣ�Ψһ�ɼ���������ʯ����
���������շ��񣬾�˵��������ָ���ȡ������շ��˷����ת��֮����
��Ц�ݿ��䣬�ն������²���������һ������Τ���񣬸ߴ����ͣ�ת
��Ӱ�ڣ����Ƕ����������µ����б��֡�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"shanmen",
  "north" : __DIR__"yonglu",
  "northeast" : __DIR__"bei3",
  "northwest" : __DIR__"bei2",
  "southeast" : __DIR__"ye1",
  "southwest" : __DIR__"ye2",
]));
        set("objects", ([
                __DIR__"obj/budd" : 1,
                __DIR__"obj/budd2" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",170);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
} 
