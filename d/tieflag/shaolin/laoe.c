 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
���������������������⣬������λ���³��ϣ��书������ߣ��ҷ�
������ĳ���ִ��ɮ�࣬ά�����ְ�ȫ�����������ֲ��ڷ���֮�£���
����������λ�����Ƕ���ǧ�������ɫ����λ������ʮ�������������ӳ�
����ɮ�ࡣ
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"laon",
  "southwest" : __DIR__"laos",
  "west": __DIR__"jian",
]));
        set("objects", ([
                __DIR__"npc/master_17_2" : 1,
       ]) );
        set("coor/x",-180);
        set("coor/y",380);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}      
