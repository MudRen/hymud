 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ҩ��");
        set("long", @LONG
��ˮ������ҩ������Χ��������Ѳ�ӣ�����ȥ�书�Բ�������Ȼ��ˮ����
�ڷ��֣������ﻹ�ǽ䱸ɭ�ϣ���Ҫ�Կɼ�һ�ߣ���ˮ�������书���أ��ö���
��Ҳ������֪���������ĸ���ľ���ӣ����Է��ű��౸��������ҩ����ҩ����ҩ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gong",
  "north" : __DIR__"wuku",
]));
        set("coor/x",190);
        set("coor/y",12340);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
