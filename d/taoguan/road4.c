 inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ����ʯ���̳ɵ�ɽ����������ï�ܵ���ľ����ǰ�����
������·�Ѿ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road5",
  "southdown" : __DIR__"road3",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2030);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}  
