 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
����������������̨��ַ��λ�ڵǷ�����ʮ���ﴦ���ܹ��⾰
�㷢Դ�ڴˣ��������������У����������Ӱ���Զ���ʱ����
����ȷ�����ܴ�����������̨�ڹ磬����ߣ�һӦ��ȫ��
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"shizong",
]));
        set("objects", ([
                __DIR__"npc/zha" : 1,
       ]) );
        set("outdoors", "songshanfy");
        set("coor/x",-170);
        set("coor/y",90);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}
