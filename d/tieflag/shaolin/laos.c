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
  "north" : __DIR__"jian",
  "northeast" : __DIR__"laoe",
  "northwest": __DIR__"lao",
]));
        set("objects", ([
                __DIR__"npc/master_17_5" : 1,
       ]) );
        set("coor/x",-190);
        set("coor/y",370);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}      
