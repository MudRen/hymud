 inherit ROOM;
void create()
{
        set("short", "���Ŷ�");
        set("long", @LONG
���Ļ���·����������չ��·�ߵ�é�ݰ�С���ƾɣ��ֱߵ�����ɢ������
����Ż�ĸ�����·�ϵ�������Ƽ��ݣ���ƶ���������ϵ�ƣ��������ż����һ����
��ɫ����֮�ˣ����ڱǴҴҶ���������մ��һ�������һ�����͵���ζ�ӱ������
������ɢ����������������������С�ƹ����ӾƵ�ζ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tuji",
  "south" : __DIR__"zuisheng",
  "west"  : __DIR__"wgate",
  "east"  : __DIR__"wcloud4",
])); 
        set("outdoors", "fengyun");
        set("coor/x",-50);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
