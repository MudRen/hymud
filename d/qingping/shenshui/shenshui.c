 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ�ܲش�");
        set("long", @LONG
��ˮ������������ˮ���֮�����ഫ��ˮ��ɫ��ζ���ȿ�Ĩ�ڵ���
Ҳ��������ˮ�У��������У�ͷ�����ѣ��������顣��Ϊ���ﶾ�����£�
�����������Լ����ˮ���ӣ�Ҳ��������˵أ�ֻ�л�ù�������
����ȡ�����Ρ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"guayu",
]));
        set("coor/x",-500);
        set("coor/y",-390);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
} 
