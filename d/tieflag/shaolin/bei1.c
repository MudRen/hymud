 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�Ɱ����������Ϊ�����ĵ����������������ʫ�鱮����������׫
�ģ���֪�����飬���������̶������ͱ��£��������飬�����پ�����
��������ͨ�����˵���ѧ�����ೢ�޲����ڡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bei2",
]));
        set("objects", ([
                __DIR__"obj/bei1" : 1,
                __DIR__"npc/pupil" :2,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-230);
        set("coor/y",180);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}      
