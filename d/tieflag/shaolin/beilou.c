 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
һ��שʯ������С¥�������ﶫ�У�������¥����¥��������ͨ��
һͨΪ�������񱮡���Ϊ����������һͨΪ��Сɽ��ʦ��ʵ�������ϱ�
ɽǽ��Ƕ�а׾��׵�ʫ����Ǭ¡���������������䡰�������������¾�
��ɽ�ۡ��˵���۷塣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yeeast",
  "east" : __DIR__"zhonglou",
  "west" : __DIR__"dianjiao",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-200);
        set("coor/y",200);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
} 
