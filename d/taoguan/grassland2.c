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
  "east" : __DIR__"lake2",
  "north" : __DIR__"taoguan",
  "south" : __DIR__"grassland1",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2080);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}    
