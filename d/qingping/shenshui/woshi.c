 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ů����");
        set("long", @LONG
���ǹ�����Ů�����ң������ʣ������������г��費�࣬��ȫ��ǡ����
�������е�����һ����ɹ�Ҥ��ƿ�д������µĲ��ż����ող�����Ұ����
Ϊ����ƾ����һ˿���⡣
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"gong",
  "east" : __DIR__"woshi2",
]));
        set("coor/x",210);
        set("coor/y",12350);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
