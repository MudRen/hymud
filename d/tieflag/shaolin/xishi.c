 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
ʼ�����ξ���䣬����˷�ء�������Ϊ���Ĵ��Ŷ����϶�ѩ
ӵ���ϥ����ڸ߷壬��ҹ�����ӽ��ϡ����������������֡���һ
���������ǡ�˫˫�񾮣��̳����ǧ���£��������壬���ʹ��������ơ�
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"ent3",
]));
        set("objects", ([
                __DIR__"obj/west_shi" : 1,
                __DIR__"npc/monk3" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-220);
        set("coor/y",160);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}    
