 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
ת��������ǰ��Ȼ���ʣ���֪���������Ѿ����˺ܸߣ�������֮�У���
��Ⱥ�廷�ƣ�Ȼ������Ⱥ�廷��֮����һ������ԶԶ��ȥˮ�ʰ�ɫ������ãã
��֮�к��ѿ���������ˮ����ô�����ǰ�ɫ���أ�������������ɻ�
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
   "west" : __DIR__"tianti2",
   "east" : __DIR__"baishui", 
]));
   set("item_desc", ([
      "lake": "������Զ���и��ܴ�ĺ��������������ƣ�����������\n",
      "��": "������Զ���и��ܴ�ĺ��������������ƣ�����������\n",
   ]) );
        set("coor/x",170);
        set("coor/y",12230);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}       
