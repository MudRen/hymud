 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����ʯ��Խ��Խ������������ӯ�����ɴ����ϱ���������ѧ��Դ��
������ͥ--��ɽ�����£����ŵ�·���ߵ��������Ų����ɿ���������̨
���Ѿ�û�ж��ټ��ˡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"ent2",
  "southeast" : "/d/tieflag/songshan/shaoshi",
]));
        set("objects", ([
                __DIR__"npc/xiangke" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",130);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
