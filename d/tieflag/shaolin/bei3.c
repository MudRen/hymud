 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ�б���Ϊ�����鷨�������飬���ض���ǧ���ɣ��������������
����һɽ��Ϊ�����ϡ��֮�������ࡰ��ʮ���帳����Ҳ�ڱ�������
�Ƕ������б�����߹��ͼ�ֵ��һ�С����������Ǳ��ֵ����һ�С�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bei4",
  "southwest" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"obj/diyishan" : 1,
                __DIR__"obj/fengfu" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-200);
        set("coor/y",180);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}     
