 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����ơ�������Ĺȣ���Ϫ�����֡�����Ϫָ�ı�������Ϫ������
����Կ�ױ����������ţ�Ҳ����Ϫ�ţ�ʯ�����͵��ţ�����ʯ��������
��һ���ף������������ഫ�˴����������ڣ����ֺ���֮��������ǧ��
�����ɲ�ֹ��������ȥ����һ���ޱߵ����֡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"shandan",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-220);
        set("coor/y",160);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
} 
