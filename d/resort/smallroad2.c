 inherit ROOM;
void create()
{
        set("short", "��С��");
        set("long", @LONG
һ������ǡ�˲���ɽ�п�����Է�̤����С�����������������
ɽ����չ�����Ե�é�ݸߴ���ߣ���ס����⡣ɽ���е�һ�ж��Ե���
ɭ�İ���
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad",
  "north" : __DIR__"smallroad3",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1190);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
