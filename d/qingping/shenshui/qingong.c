 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�޹�");
        set("long", @LONG
�����ǰ�ˮ����ľ��������г���ƽƽ��Ω��ǽ�϶��˼����һ���ʫ��
�����پ����±������ƺ����������ֱʡ���������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"huayuan",
  "southeast" : __DIR__"gong",
]));
        set("coor/x",190);
        set("coor/y",12350);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
} 
