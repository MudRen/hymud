 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ǳ����صķ��䣬û�д�����ֻ����һ������
�������������һ�㰵ҹ��Ĺ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "up": __DIR__"tianti1",
  "north": __DIR__"feng",
])); 
        set("coor/x",3310);
        set("coor/y",20);
        set("coor/z",-20);
        setup();
} 
