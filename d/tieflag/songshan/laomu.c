 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ĸ��");
        set("long", @LONG
�ӳ縣�����⣬ɽ·���ѣ���������ɽ�Ҽе����������߶���
���˳���ĸ�����ഫ��һ�Ŵ�����Ϊ�ȱ����޶��ߵ�ĸ�ף�����ɽ
ʯ��·���б�����������ôһ���վ����ڣ�����������У����Ǿ�
�����ˡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"junji", 
  "south" : __DIR__"chongfu",
]));
        set("outdoors", "songshanfy");
        set("objects", ([
                __DIR__"npc/zihe" : 1,
       ]) );
        set("coor/x",-185);
        set("coor/y",130);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
