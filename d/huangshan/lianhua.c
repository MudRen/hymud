 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ɽ��һ�߷塣����Ȼ������Ⱥ���ӵ����һ���������������ŭ�ţ�����ΰ 
������һ�壬�ǵ�֮�����ġ����̽�ܽ�ء������Ͼ�ɫ��������Ϊ���������������� 
�����ȡ�ÿ���������ʣ�������Ŀ����հ��®�������Ż���������壬��Ұ��Ϊ�� 
������ȥ���Ǻ�ɽ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"yuping",
  "westdown" : __DIR__"guangming",
]));
        set("outdoors", "huangshan");
        set("coor/x",-590);
        set("coor/y",-520);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}       
