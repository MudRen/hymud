 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�²��");
        set("long", @LONG
����ר������ɮ�����ڣ���������ڶ࣬�Ϲ��߲ˣ���ʳ��ӵĴ�
����Ʒ����Ϊ�Բ�������ɮ�¶�Ϊʩ������������С���Ժ��⣬���ڴ�
���¸��ƣ�������Ȥ������Ҳ������һ����������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"guagua",
]));
        set("objects", ([
                __DIR__"npc/clothmonk" : 2,
       ]) );
        set("coor/x",-190);
        set("coor/y",300);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}      
