 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɮ��");
        set("long", @LONG
һ���������ڣ��粻�����ܵĵ�����������󣩣�Ҳ�벻�����Ǽ�
�������������Ķ��Ƕ��ֵİ�����ߴ����ֵ�аͽ���ܱ��ؽ�����Ķ���
�Ƿ�֮�ˣ���ϧƷ�в��ˣ��ĳ���ÿ������Ҫ���̽�վ����Ե㻯����
�в������ɴ˸Ķ���ƣ�������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"laon",
  "south" : __DIR__"laos",
  "west": __DIR__"lao",
  "east" : __DIR__"laoe",
]));
        set("objects", ([
                __DIR__"obj/mantou" : 2,
                __DIR__"obj/purewater" : 2,
                __DIR__"obj/bars" : 1,
                __DIR__"obj/daodebook" : 1,
       ]) );
        set("coor/x",-190);
        set("coor/y",380);
        set("coor/z",70);
        setup();
}
void init()
{
        if(this_player()->query_skill("luohan-quan",1) < 10)
                this_player()->set("startroom", base_name(this_object())); 
}  
