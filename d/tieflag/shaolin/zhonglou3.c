 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�����������������ת����Ϊ����ǽ��֮�϶����˸�СС��������ǰ
�������ͬ��ǽ�ϱڻ��������䣬����ɮ���������»��ƣ���������
�������֡�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou4",
  "down" : __DIR__"zhonglou2",
]));
        set("coor/x",-190);
        set("coor/y",200);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
} 
