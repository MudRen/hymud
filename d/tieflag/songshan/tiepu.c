 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
һ�������ںڵ�С�꣬һ�߶�ߵ��ż��ƺ��Ѿ�������
��̣ƽ�ˡ��ſ�����һ�����ƣ�����д�ţ�
                �� ��
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"dengfeng",
]));
        set("objects", ([
                __DIR__"npc/tie_waiter" : 1,
       ]) );
        set("coor/x",-210);
        set("coor/y",90);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
