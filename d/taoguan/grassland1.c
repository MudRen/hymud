 inherit ROOM;
void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
���ϳ��Ÿ�ʽ�����Ļ��ݣ������������ﶼ���Ѽ�������
��ҩ�ݣ����������û��Ҫһ�������������Ƕ��͵�ɽ�£���
����һ�������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lake1",
  "north" : __DIR__"grassland2",
  "south" : __DIR__"hole4",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2070);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}      
