 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ĦԺ�ĵĳ����Ǵ����书�����ڣ���ĦԺ����ʦ����ڴ˴���ϰ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"damo",
]));
        set("coor/x",-220);
        set("coor/y",350);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}   
