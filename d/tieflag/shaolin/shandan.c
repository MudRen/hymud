 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ�ŵ��");
        set("long", @LONG
�½�ɽ����������Ƕ������ţ���ϸ��ʯʨһ�ԣ����ڸߴ������
�����ϡ���ɽ��������һ˿������ʯʨ����ԭ�����иߴ����ˣ���
����ǧ����꣬���ֻʣ��������ڵļи�ʯ�ˡ����ϱ��Ƕ������š�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"ent3",
  "west" : __DIR__"shaoyang",
  "up"   : __DIR__"shanmen",
  "eastup" : __DIR__"ye1",
  "westup" : __DIR__"ye2",
]));
        set("objects", ([
                __DIR__"obj/stone" : 1,
                __DIR__"obj/lion" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",160);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}     