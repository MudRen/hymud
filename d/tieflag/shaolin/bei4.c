 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�˱�����������Ŷ�����ѧ�����г����⡰���ֹ��䡱ʫ�����塰
������־�Ʊ����������˶�����ѧ���������ڣ�ϰ��֮�˵����޲�עĿ
������ϸ�о��������������ɡ����˶����֣����Ǵ����á�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bei3",
  "east" : __DIR__"ciyun",
]));
        set("objects", ([
                __DIR__"obj/dabei" : 1,
                __DIR__"obj/unarmed" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-190);
        set("coor/y",180);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}   
