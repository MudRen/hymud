 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����������ɽ�ִ��������е�һ�飬���ϸ�£�����Ʈ�ݣ���
�����ڱ���������ɽ������������ϸ�������������ҵ��������£�
�������ڣ����ֺ�Ϊ�磬����Ϊ����ɽ������Ϊ̫��ɽ���ɴ˿���
�����棬�����������¶����¡�
LONG
        );
        set("exits", ([ 
  "northwest" : "/d/tieflag/shaolin/ent",
  "southwest" : __DIR__"qimu",
  "east" : __DIR__"shuyuan", 
]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
        set("outdoors", "songshanfy");
        set("coor/x",-200);
        set("coor/y",120);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
