 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���ɽׯ");
        set("long", @LONG
�߹����۵�ʯ�ݣ����ڵ�����·�ľ�ͷ������ɽ��֮��������˽�������
�������漣��ƫƫ���һ����ͨ������ȴ����һ���ǳ����������֣������ɽ
ׯ������ǰ��һ��С¥���Ѿ����������ĸ��ڵ׽�Ƕ���֣�������С¥��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"xingxing",
  "northdown" : __DIR__"huoyan",
]));
        set("outdoors","shenshui");
        set("coor/x",200);
        set("coor/y",12320);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
