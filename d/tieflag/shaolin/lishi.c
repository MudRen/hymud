 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
��֪������������࣬�����¾�������Щʯ��ʹ�˲�֪����˳ɽ��
����࣬ʯ���ϲ��������Ϸ�顣�м�����������²���ɽˮ��������
ֻ�ɺף���ΪȺ���������������ǧ��
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"qianfe",
  "southdown" : __DIR__"lixue",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",270);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}
