 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
̫��ɽ�������ԣ����������족��������֮�ƣ���������̫��
ɽ�����壬�������ƣ��������£����������չ�Ҫ����˳����ȥ��
�Ǵ�������Ļ�ɽ�����������ɽԱܹ��ڴˡ�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"laomu",
]));
        set("outdoors", "songshanfy");
        set("objects", ([
                __DIR__"npc/xian2" : 1,
       ]) );
        set("coor/x",-180);
        set("coor/y",140);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}     
