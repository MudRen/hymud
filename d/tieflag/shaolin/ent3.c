 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���˶�����ǰ����������ʯ�����ߴ���ΰ���ƺ������Ŷ���������
��ȥ��������һ��ʯ�ţ�ǰ������ɽ�ŵ�ĵ�ǣ�̧ͷ�Ѿ����Կ�����
��������������������ԾȻ���ӡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"shandan",
  "northeast" : __DIR__"dongshi",
  "northwest" : __DIR__"xishi",
  "southdown" : __DIR__"ent2",
]));
/*        set("objects", ([
                __DIR__"npc/monk3" : 1,
       ]) );*/
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",150);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}     
