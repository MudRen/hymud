 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ȼ��");
        set("long", @LONG
���ţ�̧ͷһ���Ҷ���о����������������ˣ�һ��ɮ�ھ�����
���룬����һ�����У�Ҳ��Ȩ���룬�����ס�Ķ����������ݻ᷽��
�ľ������ˡ����г���һ��һ����ֻ��һ����С��¯��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"fang",
]));
        set("objects", ([
                __DIR__"npc/baixiaoshen" : 1,
       ]) );
        set("coor/x",-200);
        set("coor/y",250);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}  
